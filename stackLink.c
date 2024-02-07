#include <stdio.h>
#include <stdlib.h>
int c,item;			// Global Variables
 
struct node				// Declaring Structure Node with Required Variables
{
	int data;
	struct node *link;
}*ptr,*new,*temp,*top=NULL;

void push()
{
	new = malloc (sizeof(struct node));		// Allocating Memory for new
	printf("  Enter Item :");
	scanf("%d",&item);
	new -> data = item;
	new->link=top;
	top=new;
}
void pop()
{
	if( top == NULL )
	{
		printf("\n  Stack is Empty !!!");
	}
	else
	{
		temp=top;
		printf("%d is Poped",temp->data);
		top=top->link;
		free(temp);
	}
}

void display()
{
	if( top == NULL )
	{
		printf("\n  Stack is Empty !!!");
	}
	else
	{	
		ptr = top;
		printf("\n  Stack  is  :  ");
		while ( ptr != NULL )
		{
			printf("%d  ",ptr->data);
			ptr = ptr ->link;
		}
	}
}
int main()
{	printf("\n\t   ***   STACK USING LINKED LIST   ***   \n\n");
    printf("   1 - PUSH an Element \n   2 - POP an Element ");
    printf("\n   3 - Display Stack \n   4 - Exit\n");
    while(1)
    {
    	printf("Enter Your Option : ");
    	scanf("%d",&c);
    	switch(c)
    	{
    		case 1 : push();break;
    		case 2 : pop();break;
    		case 3 : display();break;
    		case 4 : exit(1);break;
    		default :  printf("Wrong Option Choosed !\n");
    	}	printf("\n");
    }
}  