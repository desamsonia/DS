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

int main()
{
	int n;
	STUDENT *head = NULL, *temp = NULL;
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

        int item;
	int f=0;
	int s=1;
	printf("Enter item to find:");
	scanf("%d",&item);

        if(head == NULL) printf("EMPTY\n");

	else
	{
	  temp = head;
	  while(temp -> link != NULL)
	  {
		  if(temp -> data == item)
		  {
			  f=1;
			  break;
		  }

		  else temp = temp -> link;
		  s++;
	  }
	}

	if(f==1) printf("found at %d\n",s);
	else printf("not found\n");

	return 0;
}
