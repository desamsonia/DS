// search element using recursion

#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>

typedef struct stu
{
	int data;
	struct stu *link;
}STUDENT;

int f = 0;
int s=1;

void search(STUDENT *head,int item)
{
	STUDENT *temp = NULL;

        temp = head;
        if(temp -> data == item)
          {
              f=1;
	      return;
           }
           search(temp = temp -> link,item);
        s++;
}

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
	printf("Enter item to find:");
	scanf("%d",&item);

	search(head,item);

	if(f==1) printf("found at %d\n",s);
	else printf("not found\n");

	return 0;
}
