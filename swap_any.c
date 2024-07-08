#include "header.h"

int count(STUDENT *head)
{
    int n = 0;
   STUDENT *t1 = NULL;
   t1=head;
    while (t1 != NULL)
    {
        n++;
        t1 = t1->link;
    }

    return n;
}

STUDENT *swap_any(STUDENT *head)
{
	STUDENT *prev1=NULL,*prev2=NULL,*node1=NULL,*node2=NULL,*temp=NULL;
	int p1,p2,n=0,mp,i=1;
	printf("Enter pos of nodes to swap:");
	scanf("%d",&p1);
	scanf("%d",&p2);

	n=count(head);
	printf("nodes = %d\n",n);
	mp = (p1>p2) ? p1:p2;

	if((p1<=0 || p1 > n) ||(p2 <=0 || p2 > n))
		printf("invalid positions\n");
	if(p1==p2)
		printf("same\n");

        temp=head;
	while((temp != NULL) && (i <= mp))
	{
		if(i == p1-1) prev1 = temp;
		if(i == p1)   node1 = temp;
		if(i == p2-1) prev2 = temp;
		if(i == p2)   node2 = temp;
		temp = temp -> link;
		i++;
	}
	if(node1 != NULL && node2 != NULL)
	{
		if(prev1 != NULL)
			prev1->link = node2;
		if(prev2 != NULL)
			prev2->link = node1;
		temp = node1->link;
		node1->link = node2->link;
		node2->link = temp;
		if(prev1 == NULL)
			head = node2;
		else if(prev2 == NULL)
			head = node1;
	}
	return head;
	   
}
