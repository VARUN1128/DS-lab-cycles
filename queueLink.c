#include <stdio.h>
#include <stdlib.h>
int c,item;			// Global Variables
 
struct node				// Declaring Structure Node with Required Variables
{
	int data;
	struct node *link;
}*ptr,*new,*temp,*front=NULL,*rear=NULL;

void enqueue()
{
	new = malloc (sizeof(struct node));		// Allocating Memory for new
	printf("  Enter Item :");
	scanf("%d",&item);
	new -> data = item;
	new->link=NULL;
	if( front == NULL)
	{	front = rear = new;	}
	else
	{
		rear->link=new;
		rear=new;
	}
}

void dequeue()
{
	if( front == NULL )
	{	printf("\n  Queue is Empty !!!");	}
	else if ( front==rear )
	{
		printf("  %d is Deleted",front->data);
		free(front);
		front=rear=NULL;
	}
	else
	{
		temp=front;
		printf("  %d is Deleted",front->data);
		front=front->link;
		free(temp);
	}
}

void display()
{
	if( front == NULL )
	{	printf("\n  Queue is Empty !!!");	}
	else
	{	
		ptr = front;
		printf("\n  Queue  is  :  ");
		while ( ptr != NULL )
		{
			printf("%d  ",ptr->data);
			ptr = ptr ->link;
		}
	}
}
int main()
{	printf("\n\t   ***   QUEUE USING LINKED LIST   ***   \n\n");
    printf("   1 - Enqueue an Element \n   2 - Dequeue an Element ");
   	printf("\n   3 - Display Queue \n   4 - Exit\n");
    while(1)
    {
    	printf("Enter Your Option : ");
    	scanf("%d",&c);
    	switch(c)
    	{
    		case 1 : enqueue();break;
    		case 2 : dequeue();break;
    		case 3 : display();break;
    		case 4 : exit(1);break;
    		default :  printf("Wrong Option Choosed !\n");
    	}	
    	 printf("\n");
    }
}  