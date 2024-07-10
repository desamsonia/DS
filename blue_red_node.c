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
        STUDENT *head=NULL,*head1=NULL,*head2=NULL,*temp=NULL,*prev1=NULL,*prev2=NULL,*prev3=NULL,*prev4=NULL;
        int i=0,f=0;
        while(i<9)
        {
           head = addLast(head);
           i++;
        }

	temp = head;
	while(temp != NULL)
	{
		if(temp->id == 1)
		{
		   if(head1 == NULL)
		   {
		       prev1 = temp;	   
		       head1=temp;
		   }
                   else  prev2->link=temp;
                   prev2=temp;
	        }
		else if(temp->id == 0)
		{
			if(head2 == NULL)
			{
				prev3 = temp;
				head2 = temp;
			}
			else  prev4->link=temp;
			prev4=temp;
		}
		temp=temp->link;
	}
	prev2->link = NULL;
	prev4->link = NULL;

       temp=head1;
       while(temp != NULL)
       {
	       printf("%d %s\n",temp->id,temp->name);
	       temp=temp->link;
       }
       temp=head2;
       while(temp !=NULL)
       {
	       printf("%d %s\n",temp->id,temp->name);
	       temp=temp->link;
       }
       return 0;

}
