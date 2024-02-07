#include <stdio.h>
#include <stdlib.h>
int c,o,key,item;			// Global Variables
 
struct node				// Declaring Structure Node with Required Variables
{
	int data;
	struct node *Llink,*Rlink;
}*ptr,*new,*temp,*head=NULL;

void display()			//Function for Displaying List
{
	if ( head==NULL )
	{	printf("   List is Empty ! \n"); 	}
	else
	{
		ptr = head;
		printf("\nList is  :  NULL <-->");
		while ( ptr != NULL )
		{
			printf("  %d  <-->",ptr->data);
			ptr = ptr ->Rlink;
		}printf(" NULL");
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
		new -> Llink = new -> Rlink= NULL;
		if ( head == NULL )		// If list is Empty
		{	head = new;		}
		else		
		{
			new -> Rlink = head;
			head -> Llink = new;
			head = new;
		}
		
	}
	else if ( o == 2 )		// Inserting at End
	{
		new -> Llink = new -> Rlink= NULL;
		if ( head == NULL )		// If list is Empty
		{	head = new;		}
		else		// If List contains more than 1 nodes
		{
			ptr = head;
			while ( ptr->Rlink != NULL )
			{	ptr = ptr -> Rlink;	}
			ptr -> Rlink = new;
			new ->Llink =ptr;
		}
		
	}
	else if ( o == 3 )		// Inserting at Specific Node
	{
		if ( head==NULL )
		{	printf("   List is Empty ! \n"); 	}
		else
		{
			printf("Enter key :");
			scanf("%d",&key);
			ptr = head;
			while ( ptr->data != key && ptr->Rlink != NULL )
			{	ptr = ptr->Rlink;	}
			if ( ptr -> data != key )
			{	printf("Search Failed : Key Not Found!!\n");return NULL;	}
			else
    		{
				new->Llink = ptr;
				new->Rlink = ptr->Rlink;
				if ( new->Rlink != NULL )
				{	new->Rlink->Llink=new;	}
				ptr->Rlink=new;
    		}
		}
	}display();
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
			if( head->Rlink == NULL)
			{
				temp = head;
				head = NULL;
				free(temp);
			}
			else
			{
				head=head->Rlink;
				free(head->Llink);
				head->Llink=NULL;
			}
		}
	}
	else if ( o==2 )	// Deleting from End
	{
		if ( head==NULL )
		{	printf("   List is Empty ! \n"); 	}
		else
		{
			if ( head->Rlink == NULL )		
			{
				temp = head;
				head = NULL;
				free(temp);
			}
			else
			{
				ptr = head;
				while ( ptr->Rlink != NULL )
				{	ptr=ptr->Rlink;		}
				ptr->Llink->Rlink=NULL;
				free(ptr);
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
			if ( head->Rlink == NULL )
			{
				if ( head->Rlink == NULL )
				{
					temp = head;
					head = NULL;
					free(temp);
				}
				else
				{	printf("  Search key Not Found\n");	}
			}
			else if ( head->data == key )
			{
				head=head->Rlink;
				free(head->Rlink);
				head->Llink=NULL;
			}
			else 
			{
				ptr= head;
				while ( (ptr->data != key) && (ptr->Rlink != NULL) )
				{	ptr = ptr->Rlink;	}
				if ( ptr->data != key )
				{	printf("  Search key Not Found\n");	  }
				else
				{
					ptr->Llink->Rlink=ptr->Rlink;
					if ( ptr->Rlink->Llink == ptr->Llink )
					{	ptr->Rlink->Llink=ptr->Llink;	}
					free(ptr);
				}
			}
		}
	}
	display();
}

int main()
{
	printf("\n\t   ***   DOUBLY LINKED LIST   ***   \n\n");
    printf("   1 - Insert a Node \n   2 - Delete a Node ");
   	printf("\n   3 - Display List \n   4 - Exit \n\n");
    while(1)
    {
    	printf("Enter Your Option : ");
    	scanf(" %d",&c);
    	switch(c)
    	{
    		case 1 : insertion();break;
    		case 2 : deletion();break;
    		case 3 : display();break;
    		case 4 : exit(1);break;
    		default :  printf("Wrong Option Choosed !  : Try Again\n");
    	}	 printf("\n");
    }
    return 0;
}