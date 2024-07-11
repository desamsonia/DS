/* remove duplicates of sorted nodes data */

#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>

typedef struct Student
{
        int id;
        char name[10];
        struct Student *link;
}STUDENT;

STUDENT *addLast(STUDENT *head)
{
       STUDENT *temp = NULL;
       STUDENT *newnode = NULL;
       newnode = calloc(1,sizeof(STUDENT));
       printf("Enter id:");
       scanf("%d",&newnode->id);
       printf("Enter name:");
       scanf("%s",newnode->name);

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

int main()
{
        STUDENT *head=NULL,*temp=NULL,*next_next=NULL;
        int i=0;

        while(i<6)
        {
           head = addLast(head);
           i++;
        }

        temp=head;
	while(temp->link != NULL)
	{
		if(temp->id == temp->link->id)
		{   
			next_next = temp->link->link;
			free(temp->link);
			temp->link=next_next;
		}
		else
			temp=temp->link;
	}

	temp=head;

	while(temp!=NULL)
	{
		printf("%d ",temp->id);
		printf("%s ",temp->name);
		temp=temp->link;
	}
	return 0;		
}
