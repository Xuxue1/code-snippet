
#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

#ifndef LOG_MODULE
#define LOG_MODULE __FILE__
#endif /* LOG_MODULE */

#define LOG_MODULE_STRING printf("%s: ", LOG_MODULE );

#ifdef LOG_VERBOSE
#define LONG_LOG_MODULE_STRING  printf("%s: (%s:%d) ", LOG_MODULE, __FUNCTION__, __LINE__ );
#else
#define LONG_LOG_MODULE_STRING  LOG_MODULE_STRING
#endif /* LOG_VERBOSE */

/* time measuring macros for profiling tasks */
#ifdef DEBUG
#  define _PROFILE(function)                                                \
     do {                                                                   \
       struct timeval current_time;                                         \
       double dtime;                                                        \
       gettimeofday(&current_time, NULL);                                   \
       dtime = -(current_time.tv_sec + (current_time.tv_usec / 1000000.0)); \
       function;                                                            \
       gettimeofday(&current_time, NULL);                                   \
       dtime += current_time.tv_sec + (current_time.tv_usec / 1000000.0);   \
       printf("%s: (%s:%d) took %lf seconds\n",                             \
              LOG_MODULE, __FUNCTION__, __LINE__, dtime);                   \
     } while(0)
#  define _PROFILE_ACCUMULATE(function)                                     \
     do {                                                                   \
       struct timeval current_time;                                         \
       static double dtime = 0;                                             \
       gettimeofday(&current_time, NULL);                                   \
       dtime -= current_time.tv_sec + (current_time.tv_usec / 1000000.0);   \
       function;                                                            \
       gettimeofday(&current_time, NULL);                                   \
       dtime += current_time.tv_sec + (current_time.tv_usec / 1000000.0);   \
       printf("%s: (%s:%d) took %lf seconds\n",                             \
              LOG_MODULE, __FUNCTION__, __LINE__, dtime);                   \
     } while(0)
#else
#  define XINE_PROFILE(function) function
#  define XINE_PROFILE_ACCUMULATE(function) function
#endif /* DEBUG */


#ifdef NDEBUG
#define _assert(exp) \
  do {                                                                \
    if (!(exp))                                                       \
      fprintf(stderr, "assert: %s:%d: %s: Assertion `%s' failed.\n",  \
              __FILE__, __LINE__, __FUNCTION__, #exp);                \
  } while(0)
#else
#define _assert(exp) \
  do {                                                                \
    if (!(exp)) {                                                     \
      fprintf(stderr, "assert: %s:%d: %s: Assertion `%s' failed.\n",  \
              __FILE__, __LINE__, __FUNCTION__, #exp);                \
      abort();                                                        \
    }                                                                 \
  } while(0)
#endif

#define _abort()                                                      \
  do {                                                                \
    fprintf(stderr, "abort: %s:%d: %s: Aborting.\n",                  \
            __FILE__, __LINE__, __FUNCTION__);                        \
    abort();                                                          \
  } while(0)


#ifdef __cplusplus
}
#endif
