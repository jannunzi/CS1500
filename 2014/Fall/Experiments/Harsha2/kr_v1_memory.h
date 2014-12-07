#include <stdio.h>
#include <stdint.h>

/*\
*  "The C Programming Language,"
*  Brian W. Kernighan and Dennis M. Ritchie
*  Copyright (C) 1978, Bell Telephone Laboratories
*
*  A Storage Allocator
*  PP. 173 - 177

*  MCS554AH2
*  Operating Systems
*  Rivier University
*  Fall 2014, Term II
*  Professor Vukelich
*
\*/

typedef long ALIGN;

union header {
	struct {
		union header	*ptr;
		uint16_t		size;
	} s;
	ALIGN		x;
};

typedef union header Header;

static Header base; /* empty list to get started */
static Header *allocp = NULL; /* last allocated block */

/* free: put block ap in free list */

void kr_free(void *);

#define NALLOC 128 /* minimum #units to request */

/* morecore: ask system for more memory */

static Header *morecore(unsigned);

/* kr_alloc: general-purpose storage allocator */

char *kr_alloc(unsigned);

static int system_core = 1;
