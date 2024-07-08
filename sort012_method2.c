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

	int cnt[3] = {0,0,0};

	temp = head;
	while(temp != NULL)
	{
		cnt[temp -> data] = cnt[temp -> data] + 1;

		temp = temp->link;
	}

	i =0;
	temp = head;
       
	while(temp != NULL)
	{
		if(cnt[i] == 0)	 i++;

		else
		{
			temp->data = i;
			--cnt[i];
			temp = temp -> link;
		}
	}

        temp = head;
        while(temp)
        {
                printf("%d ",temp->data);
                temp = temp -> link;
        }

	return 0;
}
