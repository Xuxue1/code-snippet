#include "mempool.h"
#include <string.h>
#include <stdlib.h>

mem_pool::mem_pool(void)
    : heap_size(0)
    , start_free(NULL)
    , end_free(NULL)
{
    memset(free_list, NULL, sizeof(free_list));
}

mem_pool::~mem_pool(void)
{
}

char* mem_pool::chunk_alloc(size_t size, int& nobjs)
{
    char* result;
    // 总共所需的内存
    size_t total_bytes = size * nobjs;
    // 剩余的内存
    size_t bytes_left = end_free - start_free;


    if (bytes_left >= total_bytes)
    {
        result = start_free;
        start_free += total_bytes;
        return result;
    }

    if (bytes_left >= size)
    {
        nobjs = (int)(bytes_left / size);
        total_bytes = size * nobjs;
        result = start_free;
        start_free += total_bytes;
        return result;
    }


    if (bytes_left > 0)
    {
        obj **my_free_list = free_list + free_list_index(bytes_left);
        ((obj*)start_free)->free_list_link = *my_free_list;
        *my_free_list = (obj*)start_free;
    }


    size_t bytes_to_get = 2 * total_bytes + round_up(heap_size >> 4);
    start_free = (char *)malloc(bytes_to_get);


    if (start_free != 0)
    {
        heap_size += bytes_to_get;
        end_free = start_free + bytes_to_get;
        return chunk_alloc(size, nobjs);
    }


    int i = (int)free_list_index(size) + 1;
    obj **my_free_list, *p;
    for ( ; i < BLOCK_LIST_NUM;  ++i)
    {
        my_free_list = free_list + i;
        p = *my_free_list;

        if (NULL != p)
        {
            *my_free_list = p->free_list_link;
            start_free = (char *)p;
            end_free = start_free + (i + 1) * ALIGN;
            return chunk_alloc(size, nobjs);
        }
    }

    end_free = NULL;

    return NULL;
}


void* mem_pool::refill(size_t n)
{
    int nobjs = LIST_NODE_NUM;
    char* chunk = chunk_alloc(n, nobjs);
    obj** my_free_list;
    obj* result;
    obj *current_obj, *next_obj;
    int i;

    if (1 == nobjs) 
    {
        return chunk;
    }

    my_free_list = free_list + free_list_index(n);


    result = (obj *)chunk;

    --nobjs;

    *my_free_list = next_obj = (obj *)(chunk + n);


    for (i = 1; ; ++i)
    {
        current_obj = next_obj;
        next_obj = (obj *)((char*)next_obj + n);

        if (nobjs == i)
        {
            current_obj->free_list_link = NULL;
            break;
        }
        current_obj->free_list_link = next_obj;
    }

    return result;
}


void* mem_pool::allocate(size_t n)
{
    obj** my_free_list;
    obj* result;

    if (n <= 0) 
    {
        return NULL;
    }

    if (n > MAX_BLOCK_SIZE)
    {
        return malloc(n);
    }

    try
    {
        my_free_list = free_list + free_list_index(n);
        result = *my_free_list;
        
        if (NULL == result)
        {
            result = (obj *)refill(round_up(n));
        }
        else
        {
            *my_free_list = result->free_list_link;
        }
    } 
    catch(...)
    {
        result = NULL;
    }

    return result;
}

void mem_pool::deallocate(void* p, size_t n)
{
    obj *q = (obj *)p;
    obj** my_free_list;

    if(n > MAX_BLOCK_SIZE)
    {
        free(p);
        return;
    }

    my_free_list = free_list + free_list_index(n);

    q->free_list_link = *my_free_list;
    *my_free_list = q;
}
