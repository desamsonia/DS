// swapping of adjecent nodes only [not perfect code ] refer -> swap_any.c to get swap any nodes

#include "header.h"
STUDENT *swap(STUDENT *head)
{
	STUDENT *p=NULL, *q=NULL,*r=NULL;
	int loc,i=1;
	printf("Enter start node to swap:");
	scanf("%d",&loc);
	p=head;
	while(i < loc-1)
	{
	   p=p->link;
	   i++;
	}

	q=p->link;
	r=q->link;

	q->link=r->link;
	r->link=q;
	p->link=r;

	return head;
}

