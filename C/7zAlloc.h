/* 7zAlloc.h -- Allocation functions
2010-10-29 : Igor Pavlov : Public domain */

#ifndef __7Z_ALLOC_H
#define __7Z_ALLOC_H

#include <stdlib.h>

void *SzAlloc(void *p, size_t size);
void SzFree(void *p, void *address);

void *SzAllocTemp(void *p, size_t size);
void SzFreeTemp(void *p, void *address);

#define MY_ALLOC(T, p, size, alloc) { if ((size) == 0) p = 0; else \
  if ((p = (T *)IAlloc_Alloc(alloc, (size) * sizeof(T))) == 0) return SZ_ERROR_MEM; }

#endif
