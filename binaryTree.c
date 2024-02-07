/*  create a binary search tree with following operations

1-  insert a new node
2 - inorder traversal
3 - preorder 
4 - postorder
5 - delete a node



2. represent any given graph and perform a depth first search, breadth first search

*/
#include <stdio.h>
#include <stdlib.h>
int c,p,o,key,item;			// Global Variables
 
struct node
{
	int data;
	struct node *rChild,*lChild;
};

struct node* search(int item)
{
	ptr = root;
	while ( ptr != NULL )
	{
		if ( ptr -> data == item)
			return ptr;
		else if ( ptr->data<item)
			ptr=ptr->rChild;
		else
			ptr= ptr->lChild;
	}
}

void insertion()
{
	if ( root == NULL )
	{
		new = malloc (sizeof(struct node));		// Allocating Memory for new
		new->data=item;
		new->lChild=new->rChild=NULL;
		root = new;
	}
	else
	{
		ptr=root;
		flag=0;
		ptr = search(item);
		if ( ptr ==NULL)
		{
			new = malloc (sizeof(struct node));		// Allocating Memory for new
			new->lChild=new->rChild=NULL;
			ptr=new;
		}
	}
}



void inOrder()
{
	while ( root!= NULL )
	{
		inOrder(root->lChild);
		printf("%d",root->data);
		inOrder(root->rChild);
	}
}

void preOrder()
{
	while ( root != NULL )
	{
		printf("%d",root->data);
		preOrder(root->lChild);
		preOrder(root->rChild);
	}	
}

void postOrder()
{
	while ( root != NULL )
	{
		postOrder(root->lChild);
		postOrder(root->rChild);
		printf("%d",root->data);
	}
}
void deletion()
{
	ptr = root;
	
}

int main()
{
	printf("\n\t   ***   BINARY TREE   ***   \n\n");
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
    		case 4 :	scanf("%d",&item); 	
    					ptr = search(item);
    					if ( ptr != NULL )
    					{	printf("Key Found\n");	}break;
    		case 5 : exit(1);break;
    		default :  printf("Wrong Option Choosed !  : Try Again\n");
    	}	 printf("\n");
    }
	return 0;
}

