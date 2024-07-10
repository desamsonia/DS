/* segmentation fault in this code */

#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>

typedef struct stu
{
	int data;
	struct stu *link;
}STUDENT;


STUDENT *addL(STUDENT *head)
{
	STUDENT *newnode = NULL,*temp = NULL;
	newnode = calloc(1,sizeof(STUDENT));

	printf("Enter data:");
	scanf("%d",&newnode->data);

	if(head == NULL)  
	{
		head = newnode;
	}

	else
	{
		temp = head;
		while(temp -> link)
		{
			temp = temp -> link;
		}
		temp->link = newnode;
	}

	return head;
}

int count(STUDENT *head)
{
     STUDENT *temp = NULL;
     temp = head;

     int nodes = 1;
     while(temp -> link != NULL)
     {
	     temp = temp -> link;
	     nodes++;
     }

     return nodes;
}

int main()
{
	int n;
	STUDENT *head = NULL, *temp = NULL,*prev = NULL;

	printf("Enter nodes:");
	scanf("%d",&n);
	int i=0;

	while(i<n)
	{
	   head = addL(head);
	   i++;
	}

	temp = head;
	while(temp)		
	{
		printf("%d ",temp->data);
		temp = temp -> link;
	}
       

	int nodes = count(head);
	printf("nodes = %d\n",nodes);
	int c = 1;
        
	while(head -> link != NULL)
	{
		if(c == nodes-1)
		{
		 head = head -> link;
		 head->link = NULL;
		}

		head = head -> link;
		c++;
        }

	temp = head;
	while(temp)
        {
                printf("%d ",temp->data);
                temp = temp -> link;
        }

	return 0;
}
