#ifndef TDDC_H
#define TDDC_H

#include <stddef.h>

/**
 * Function: cpch
 * Description: copy string `src` into char array `dst` of size `dstsize`
 * Return: the size of the `src` string, without terminating \0
 */
int cpch(char* dst, size_t dstsize, const char* src);

/**
 * Function: catch
 * Description: append string `src` into char array `dst` of size `dstsize`
 * Return: the size of the `src` string, without terminating \0
 */
int catch(char* dst, size_t dstsize, const char* src);

/**
 * Function: cpnch
 * Description: copy string `src` into char array `dst` of size `dstsize`
 * Return: the size of the `src` string, without terminating \0
 */
int cpnch(char* dst, size_t dstsize, const char* src, size_t n);

/**
 * Function: catnch
 * Description: append string `src` into char array `dst` of size `dstsize`
 * Return: the size of the `src` string, without terminating \0
 */
int catnch(char* dst, size_t dstsize, const char* src, size_t n);

#endif /* TDDC_H */
