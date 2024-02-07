#include <stdio.h>
#include<stdlib.h>

int n1,n2,i;
struct node
{
	int coef,expo;
	struct node *link;
}*Phead,*Qhead,*Rhead,*new,*ptr,*head,*P,*Q,*R;

struct node* read(int  n)		// Read Polynomial L2R
{
	head=NULL;
	for( i=n ; i>0 ; i-- )
	{	
		new = malloc(sizeof(struct node));
		scanf("%d",&new->coef);
		scanf("%d",&new->expo);
		new->link=NULL;

		if ( head==NULL)
		{
			head=new;
			ptr=head;
		}
		else
		{
			ptr->link=new;
			ptr=new;
		}
	}
	return head;
}

void display(struct node *head)
{
	if ( head == NULL )
	{
		printf("Polynomial is Empty\n");
	}
	else
	{
		ptr=head;
		while(ptr->link != NULL )
		{
			printf("%dx^%d + ",ptr->coef,ptr->expo);
			ptr=ptr->link;
		}
		printf("%d",ptr->coef);
	}
}

struct node* polyAdd()
{
	head=NULL;
	P=Phead;
	Q=Qhead;
	while ( P != NULL && Q !=NULL )
	{
		new = malloc(sizeof(struct node));
		new->link=NULL;
		if ( P->expo == Q->expo )
		{
			new->coef = P->coef+Q->coef;
			new->expo = P->expo;
			P=P->link;
			Q=Q->link;
		}
		else if ( P->expo > Q->expo )
		{
			new->coef = P->coef;
			new->expo = P->expo;
			P=P->link;
		}
		else
		{
			new->coef = Q->coef;
			new->expo = Q->expo;
			Q=Q->link;
		}
		if ( head==NULL )
		{
			head=new;
			R=head;
		}
		else
		{
			R->link=new;
			R=new;
		}
	}
	while ( P!= NULL)
	{
		new = malloc(sizeof(struct node));
		new->coef = P->coef;
		new->expo = P->expo;
		new->link=NULL;
		if ( head==NULL )
		{
			head=new;
			R=head;
		}
		else
		{
			R->link=new;
			R=new;
		}
	}

	while ( Q!= NULL)
	{
		new = malloc(sizeof(struct node));
		new->coef = Q->coef;
		new->expo = Q->expo;
		new->link=NULL;
		if ( head==NULL )
		{
			head=new;
			R=head;
		}
		else
		{
			R->link=new;
			R=new;
		}
	}
	return head;
}

int main()
{
	printf(" Enter No of terms Polynomial 1 & 2 : ");
	scanf("%d%d",&n1,&n2);
	printf(" Enter Coeffients of Polynomial 1 : "); //from 0 
	Phead=read(n1);
	printf(" Enter Coeffients of Polynomial 2 : "); //from 0 
	Qhead=read(n2);
	printf("\n Entered polynomial 1 is ");
	display(Phead);
	printf("\n Entered polynomial 2 is ");
	display(Qhead);

	printf("\n\n Sum of Polynomial 1 & 2 is : ");
	Rhead = polyAdd();
	display(Rhead);

	return 0;
}

/* 					OUTPUT

 Enter the degrees of Polynomial 1 & 2 : 2 3
 Enter Coeffients of Polynomial 1 : 3 2 5
 Enter Coeffients of Polynomial 2 : 4 0 4 8

 Entered polynomial 1 is 3x^2 + 2x^1 + 5
 Entered polynomial 2 is 4x^3 + 0x^2 + 4x^1 + 8

 Sum of Polynomial 1 & 2 is : 4x^3 + 3x^2 + 6x^1 + 13

 */