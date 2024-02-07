#include <stdio.h>
#include <stdlib.h>
int c,p,o,key,item;			// Global Variables
 
struct node				// Declaring Structure Node with Required Variables
{
	int data;
	struct node *link;
}*ptr,*new,*curr,*pre,*temp,*head=NULL;

int isEmpty()		// Function for Checking List is Empty or Not
{
	if ( head==NULL )
	{	printf("  List is Empty ! \n");return 0; 	}
	else 
	{	return 1;	}
}

void display()			//Function for Displaying List
{
	if ( isEmpty() ) 
	{
		ptr = head;
		printf("\nList is  :  ");
		while ( ptr->link != head )
		{
			printf(" %d -->",ptr->data);
			ptr = ptr ->link;
		}printf(" %d --> head",ptr->data);
	}
}

struct node* search()		// Function for Searching an Element 
{
	printf("Enter key :");
	scanf("%d",&key);
	if ( isEmpty() )
	{
		ptr = head;
		while ( ptr->data != key && ptr->link != head )
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
		if ( head == NULL )
		{
			head=new;
			new->link=new;
		}
		else
		{
			ptr = head;
			while ( ptr->link != head )
			{
				ptr = ptr->link;
			}
			new->link=head;
			head=new;
			ptr->link=head;
		}
	}
	else if ( o == 2 )		// Inserting at End
	{
		if ( head == NULL )
		{
			head=new;
			new->link=new;
		}
		else
		{
			ptr = head;
			while ( ptr->link != head )
			{
				ptr = ptr->link;
			}
			ptr->link=new;
			new->link=head;
		}
	}
	else if ( o == 3 )		// Inserting at Specific Node
	{
		if ( isEmpty() )
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
		if ( isEmpty() )	// Deleting from Front
		{
			if ( head->link == head )
			{
				temp=head;
				head=NULL;
				free(temp);
			}
			else
			{
				temp=ptr = head;
				while ( ptr->link != head )
				{
					ptr = ptr->link;
				}
				head=head->link;
				ptr->link=head;
				free(temp);
			}
		}
	}
	else if ( o==2 )	// Deleting from End
	{
		if ( isEmpty() )
		{
			if ( head->link == head )
			{
				temp=head;
				head=NULL;
				free(temp);
			}
			else
			{
				pre = head;
				curr = head->link;
				while ( curr->link != head )
				{
					pre=curr;
					curr = curr->link;
				}
				pre->link=head;
				free(curr);
			}
		}
	}
	else if ( o==3 )	// Deleting from Specific Node
	{
		
		if ( isEmpty() )
		{
			printf("Enter key :");
			scanf("%d",&key);
			if ( head->link == head )
			{
				if( head->data == key )
				{
					temp = head;
					head = NULL;
					free(temp);
				}
				else
				{	printf("Search key Not Found\n");	}
			}
			else if ( head -> data == key)
			{
				temp=ptr=head;
				while ( ptr->link != head)
				{
					ptr=ptr->link;
				}
				head=head->link;
				ptr->link=head;
				free(temp);
			}
			else
			{
				pre= head;
				curr=head->link;
				while ( (curr->data != key) && (curr->link != head) )
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
	printf("\n\t   ***   CIRCULAR LINKED LIST   ***   \n\n");
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