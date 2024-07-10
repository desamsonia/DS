/* delete middle node */

#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>

typedef struct Student
{
        int id;
        struct Student *link;
}STUDENT;

STUDENT *addLast(STUDENT *head)
{
       STUDENT *temp = NULL;
       STUDENT *newnode = NULL;
       newnode = calloc(1,sizeof(STUDENT));

       printf("Enter id:");
       scanf("%d",&newnode->id);

       if(head==NULL)
       {
               head = newnode;
       }

       else
       {
               temp = head;
               while(temp->link)
               {
                   temp = temp->link;
               }
               temp->link = newnode;
       }
       return head;
}


int countNodes(STUDENT *head)
{
	STUDENT *temp = NULL;
	temp = head;
	int n=1;

	while(temp ->link != NULL)
	{
		temp = temp ->link;
		n++;
	}
	return n;
}

STUDENT *delMid(STUDENT *head)
{
	int n = countNodes(head);
	int r = 1;
	STUDENT *temp = NULL;
        STUDENT *newhead = NULL;
	newhead = head;

        int mid = n / 2;

        while(--mid > 0)
	{
	    head = head -> link;
	}

	head->link = head->link->link;
	
	return newhead;
}

int main()
{
        STUDENT *head=NULL,*temp=NULL,*next_next=NULL;
        int i=0;
	int node;
	printf("enter nodes:");
	scanf("%d",&node);

        while(i<node)
        {
           head = addLast(head);
           i++;
        }
         
	head = delMid(head);

	temp=head;
	while(temp!=NULL)
	{
		printf("%d  ",temp->id);
		temp=temp->link;
	}
	return 0;		
}
