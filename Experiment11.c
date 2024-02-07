#include <stdio.h>
#include <stdlib.h>

int c,nos=0,item;			// Global Variables

struct node				// Declaring Structure Node with Required Variables
{
	int data;
	struct node *link;
}*new,*ptr,*head=NULL;

void display()			//Function for Displaying List
{
	if( head == NULL)
	{
		printf("List is Empty ! \n");
	}
	else
	{
		ptr = head;
		printf("\nList is  :  ");
		while ( ptr != NULL )
		{
			printf(" %d  ",ptr->data);
			ptr = ptr ->link;
		}
	}
}

void insert()
{
		new = malloc (sizeof(struct node));
		printf("Enter Item :");
		scanf("%d",&item);
		new -> data = item;
		new -> link = NULL;

		if ( head == NULL )		// If list is Empty
		{
			head = new;	
		}
		else		// If List contains more than 1 nodes
		{
			ptr = head;
			while ( ptr->link != NULL )
			{
				ptr = ptr -> link;
			}
			ptr -> link = new;
		}
		
		nos++;
}

int main()
{
	printf("\n\t   ***   LINKED LIST   ***   \n\n");
    printf("   1 - Insert a Node \n   2 - Display List ");
   	printf("\n   3 - Number of Nodes\n   4 - Exit \n\n");
    while(1)
    {
    	printf("Enter Your Option : ");
    	scanf(" %d",&c);
    	printf("\n");
    	switch(c)
    	{
    		case 1 : insert();break;
    		case 2 : display();break;
    		case 3 : printf("Number of Nodes = %d",nos);break;
    		case 4 : exit(1);break;
    		default :  printf("Wrong Option Choosed !  : Try Again\n");
    	}	
    	 printf("\n");
    }
    return 0;
}