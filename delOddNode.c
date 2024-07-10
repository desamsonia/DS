#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>

typedef struct Student
{
        int id;
        char name[10];
        struct Student *link;
}STUDENT;


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
        STUDENT *head=NULL,*temp=NULL,*prev=NULL;
        int i=0,f=0;
	int n;
	n=count(head);
        while(i<6)
        {
           head = addLast(head);
           i++;
        }
	int cnt=1;
	temp=head;
        while(temp != NULL)
        {
	    if((cnt%2)==1)
	    {
		    printf("count = %d\n",cnt);
		    if(cnt==1)
		    {
			    head = temp->link;
			    free(temp);
		    }
		    else
		    {
			    prev->link=temp->link;
		    }
		    if(temp->link == NULL && cnt == n)
		    {
			    free(temp);
			    temp=NULL;
		    }
	    }
	    prev=temp;
	    temp=temp->link;
	    cnt++;
	}
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->id);
		temp=temp->link;
	}

	
}

