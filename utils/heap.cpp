#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class heap
{
public:
  heap()
  : heap_(0),
    max_size_(1024),
    size_(0)
  {
    heap_ = new int[max_size_];
    for (int i = 0; i < max_size_; ++i)
      heap_[i] = 0;
  }
  ~heap()
  {
    delete []heap_;
  }
  int insert(int val)
  {
    if (this->size_ >= this->max_size_)
      return -1;
    this->heap_[size_] = val;
    this->reheap_up(this->size_);
    ++this->size_;
    return 0;
  }
  void reheap_up(int slot)
  {
    int pos = slot;
    int parent = (slot - 1) / 2;
    int val = this->heap_[pos];
    while (pos > 0)
    {
      if (this->heap_[parent] <= val) 
        break;
      else
      {
        this->heap_[pos] = this->heap_[parent];
        pos = parent;
        parent = (parent - 1) / 2;
      }
    }
    this->heap_[pos] = val;
  }
  int remove(int slot)
  {
    int val = this->heap_[0];
    this->heap_[0] = this->heap_[this->size_ - 1];
    --this->size_;
    this->reheap_down(0, this->size_ - 1);
    return val;
  }
  void reheap_down(int start, int end)
  {
    int pos = start;
    int lchild = (pos * 2) + 1;
    int val = this->heap_[pos];
    while (lchild <= end)
    {
      if (lchild < end && this->heap_[lchild] > this->heap_[lchild + 1])
        ++lchild;
      if (val <= this->heap_[lchild])
        break;
      else
      {
        this->heap_[pos] = this->heap_[lchild];
        pos = lchild;
        lchild = (2 * lchild) + 1;
      }
    }
    this->heap_[pos] = val;
  }
private:
  int *heap_;
  int size_;
  int max_size_;
};
int main ()
{
  srand(time(0));

  heap h;
  for (int i = 0; i < 20; ++i)
  {
    h.insert(rand() % 20);
  }

  // print
  for (int i = 0; i < 20; ++i)
  {
    printf("%d ", h.remove(i));
  }
  printf("\n");
}
