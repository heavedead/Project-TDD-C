#include "tddc/tddc.h"

#include <string.h>
#include <stdio.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

int cpch(char* dst, size_t dstsize, const char* src)
{
  /*
   * All the work is done by snprintf. We don't have much to do
   */
  return snprintf(dst, dstsize, "%s", src);
}

int catch(char* dst, size_t dstsize, const char* src)
{
  /*
   * Here we consider that concatenating is the same as 
   * copying at the end of the existing destination string.
   *
   * <----dststrsize----> <-----dstsize-dststrsize------>
   *
   * | h | e | l | l | o | 0 | ? | ? | ? | ? | ? | ? | ? |
   *
   *   ^ dst               ^ dst+dststrsize
   */
  size_t dststrsize = strlen(dst);
  return cpch(dst+dststrsize, dstsize-dststrsize, src);
}

int cpnch(char* dst, size_t dstsize, const char* src, size_t n)
{
  return cpch(dst, dstsize<(n+1) ? dstsize : n+1, src); /* mettre la maccro ici */
}



int catnch(char* dst, size_t dstsize, const char* src, size_t n)
{
  return catch(dst, min(strlen(dst)+n+1, dstsize), src);
}

