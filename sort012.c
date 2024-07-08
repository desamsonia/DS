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
	int n,n1=0,n2=0,n3=0;
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
	printf("\n");

	temp = head;
	while(temp != NULL)
	{
		if(temp->data == 0) n1++;
		if(temp->data == 1) n2++;
		if(temp->data == 2) n3++;

		temp = temp -> link;
	}

	printf("n1 = %d ,n2 = %d, n3 = %d\n",n1,n2,n3);

	temp = head;
	while(temp != NULL)
	{
		if(n1>0)
		{
			temp->data = 0;
			n1--;
			temp = temp->link;
		}

		else if(n2>0)
		{
			temp->data = 1;
			n2--;
			temp = temp->link;
		}

		else if(n3>0)
		{
			temp->data = 2;
			n3--;
			temp = temp ->link;
		}
	}
/*
        while(temp != NULL)
        {
                if(n2>0)
		{
                        temp->data = 1;
			n2--;
			temp = temp -> link;
		}
		if(n2==0) break;
        }

	while(temp != NULL)
        {
                if(n3>0)
		{
                        temp->data = 2;
			n3--;
			temp = temp -> link;
		}
		if(n3==0) break;
        }*/

       temp = head;
        while(temp)
        {
                printf("%d ",temp->data);
                temp = temp -> link;
        }

	return 0;
}
