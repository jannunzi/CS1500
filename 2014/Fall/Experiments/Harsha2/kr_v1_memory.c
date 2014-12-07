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

#include "kr_v1_memory.h"

char *kr_alloc(unsigned nbytes) { /* general purpose storage allocator */
	register Header *p, *q;
	register int nunits;

	nunits = 1 + (nbytes + sizeof(Header) - 1) / sizeof(Header);
	if ((q = allocp) == NULL) { /* no free list yet */
		base.s.ptr = allocp = q = &base;
		base.s.size = 0;
	}

	for (p = q->s.ptr;; q = p, p = p->s.ptr) {
		if (p->s.size >= nunits) { /* big enough */
			if (p->s.size == nunits) /* exactly! */
				q->s.ptr = p->s.ptr;
			else { /* allocate tail end */
				p->s.size -= nunits;
				p += p->s.size;
				p->s.size = nunits;
			}
			allocp = q;
			return ((char *)(p + 1));
		}
		if (p == allocp) /* wrapped around free list */
			if ((p = morecore(nunits)) == NULL)
				return (NULL); /* memory exhausted */
	}
}

static Header *morecore(unsigned nu) { /* ask O/S for more memory */

	char 		*sbrk();
	register char	*cp;
	register Header	*up;
	register int		rnu;

	rnu = NALLOC * ((nu + NALLOC - 1) / NALLOC);
	if (system_core) {
		cp = sbrk(rnu * sizeof(Header));
		if ((void *)cp == (void *)-1)
			return (NULL);
		up = (Header *)cp;
		up->s.size = rnu;
		kr_free((char *)(up + 1));
		system_core--;
		return (allocp);
	}
	else { return (NULL); }
}

void kr_free(void *ap) {

	register Header *p, *q;

	p = (Header *)ap - 1;  /*pointer to header */
	for (q = allocp; !(p > q && p < q->s.ptr); q = q->s.ptr)
		if (q >= q->s.ptr && (p > q || p < q->s.ptr))
			break; /* at one end or the other */
	if (p + p->s.size == q->s.ptr) { /* join to upper nbr */
		p->s.size += q->s.ptr->s.size;
		p->s.ptr = q->s.ptr->s.ptr;
	}
	else p->s.ptr = q->s.ptr;
	if (q + q->s.size == p) { /* join to lower nbr */
		q->s.size += p->s.size;
		q->s.ptr = p->s.ptr;
	}
	else
		q->s.ptr = p;
	allocp = p;
}
