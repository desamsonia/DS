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

void delWithOutHeadPtr(STUDENT *next)
{
	STUDENT *temp = next->link;

	next -> data = next->link->data;
	next -> link = next -> link->link;

	free(temp);
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

	STUDENT *del = NULL;
	del = head->link;
	delWithOutHeadPtr(del);

	temp = head;
        while(temp)
        {
                printf("%d ",temp->data);
                temp = temp -> link;
        }
	return 0;
}
