#include <stdio.h>
#include <stdlib.h>
int c,p,o,key,item;			// Global Variables
 
struct node				// Declaring Structure Node with Required Variables
{
	int data;
	struct node *link;
}*ptr,*new,*curr,*pre,*temp,*head=NULL;


void display()			//Function for Displaying List
{
	if ( head==NULL )
	{	printf("   List is Empty ! \n"); 	}
	else
	{
		ptr = head;
		printf("\nList is  :  ");
		while ( ptr != NULL )
		{
			printf(" %d -->",ptr->data);
			ptr = ptr ->link;
		}printf(" NULL");
	}
}

struct node* search()		// Function for Searching an Element 
{
	printf("Enter key :");
	scanf("%d",&key);
	if ( head==NULL )
	{	printf("   List is Empty ! \n"); 	}
	else
	{
		ptr = head;
		while ( ptr->data != key && ptr->link != NULL )
		{	ptr = ptr->link;	}
		if ( ptr -> data == key )
		{	return ptr;	}
		else
		{	printf("Search Failed : Key Not Found!!\n");return NULL;	}	
	}
}

void insertion()		// Function for Inserting Element
{
	printf("\t\t1 - Front\n Insert At  : \t2 - End\n\t\t3 - Specified Node\n");
	printf("  Make your Choice : ");scanf("%d",&o);
	new = malloc (sizeof(struct node));		// Allocating Memory for new
	printf("Enter Item :");
	scanf("%d",&item);
	new -> data = item;
	if ( o == 1 )		// Inserting at Front
	{
		new -> link = head;
		head = new;
	}
	else if ( o == 2 )		// Inserting at End
	{
		new -> link = NULL;
		if ( head == NULL )		// If list is Empty
		{	head = new;		}
		else		// If List contains more than 1 nodes
		{
			ptr = head;
			while ( ptr->link != NULL )
			{	ptr = ptr -> link;	}
			ptr -> link = new;
		}
	}
	else if ( o == 3 )		// Inserting at Specific Node
	{
		if ( head==NULL )
		{	printf("   List is Empty ! \n"); 	}
		else
		{
			if ( search() )
    		{
				new->link = ptr->link;
				ptr->link=new;
    		}
		}
	}
}

void deletion()			// Function for Deleting Element
{
	printf("\t\t1 - Front\n Delete From  : 2 - End\n\t\t3 - Specified Node\n");
	printf("  Make your Choice : ");scanf("%d",&o);
	if ( o==1 )
	{
		if ( head==NULL )
		{	printf("   List is Empty ! \n"); 	}
		else
		{
			temp = head;
			head = head->link;
			free(temp);
		}
	}
	else if ( o==2 )	// Deleting from End
	{
		if ( head==NULL )
		{	printf("   List is Empty ! \n"); 	}
		else
		{
			if ( head->link == NULL )
			{
				temp = head;
				head = NULL;
				free(temp);
			}
			else
			{
				pre = head;
				curr = head->link;
				while ( curr->link != NULL )
				{
					pre = curr;
					curr = curr->link;
				}
				pre->link=NULL;
				free(curr);
			}
		}
	}
	else if ( o==3 )	// Deleting from Specific Node
	{
		
		if ( head==NULL )
		{	printf("   List is Empty ! \n"); 	}
		else
		{
			printf("Enter key :");
			scanf("%d",&key);
			if ( head->data == key )
			{
				temp = head;
				head = head->link;
				free(temp);
			}
			else
			{
				pre=curr= head;
				while ( (curr->data != key) && (curr->link != NULL) )
				{
					pre = curr;
					curr = curr->link;
				}
				if ( curr ->data != key )
				{	printf("Search key Not Found\n");	}
				else
				{
					pre -> link = curr->link;
					free(curr);
				}
			}
		}
	}
}

int main()
{
	printf("\n\t   ***   LINKED LIST   ***   \n\n");
    printf("   1 - Insert a Node \n   2 - Delete a Node ");
   	printf("\n   3 - Display List \n   4 - Search for a Node\n   5 - Exit \n\n");
    while(1)
    {
    	printf("Enter Your Option : ");
    	scanf(" %d",&c);
    	switch(c)
    	{
    		case 1 : insertion();break;
    		case 2 : deletion();break;
    		case 3 : display();break;
    		case 4 : 	ptr = search();
    					if ( ptr != NULL )
    					{	printf("Key Found\n");	}break;
    		case 5 : exit(1);break;
    		default :  printf("Wrong Option Choosed !  : Try Again\n");
    	}	 printf("\n");
    }
    return 0;
}