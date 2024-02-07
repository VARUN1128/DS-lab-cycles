#include<stdio.h>
#include<stdlib.h>

int dq[3],i,c,item,front=-1,rear=-1,size=3;

void display()
{
	if ( front==-1 && rear==-1 )		// Deque is Empty
	{
		printf("\n\tDeque is Empty ! ");
	}
	else
	{	printf("\tDeque is  :  ");
		for ( i=front ; i<=rear ; i++ )
		{
			printf("%-4d",dq[i]);
		}
	}
}

void push()
{
	if ( front==0 && rear==size-1 )		//Deque id Full
	{
		printf("\n\tDeque is Full");
	}
	else
	{	printf("\tEnter Element to Push : ");
		scanf("%d",&item);
		if ( front==-1 && rear ==-1)	//Deque is empty
		{
			front=rear=0;
			dq[front]=item;
		}
		else if (front>0)		// front having value greater than 0
		{
			front--;
			dq[front]=item;
		}
		else		// no space at front but space in rear
		{
			for( i=rear ; i>=0 ; i-- )		//shifting all positions to right
			{
				dq[i+1]=dq[i];
			}
			dq[front]=item;
			rear++;
		}display();
	}
}

void pop()
{
	if ( front==-1 && rear ==-1 )	//Deque is empty
	{
		printf("\n\tDeque is Empty ! ");
	}
	else if ( front==rear )		// Deque have only one element
	{
		printf("\tElement Dequed is : %d\n",dq[front]);
		front=rear=-1;
	}
	else
	{
		printf("\tElement Dequed is : %d\n",dq[front]);
		front++;
	}
	display();
}

void inject()
{
	if ( front==0 && rear ==size-1)
	{
		printf("\n\tDeque is Full");
	}
	else
	{	printf("\tEnter Element to Inject : ");
		scanf("%d",&item);
		if ( front==-1 && rear ==-1)	//Deque is empty
		{
			front=rear=0;
			dq[rear]=item;
		}
		else if ( rear<size-1 )		// free space at rear
		{
			rear++;
			dq[rear]=item;
		}
		else		// no space at rear but space in front
		{
			for( i=front ; i<=rear ; i++ )		//shifting all positions to left
			{
				dq[i-1]=dq[i];
			}
			dq[rear]=item;
			front--;
		}display();
	}
}
void eject()
{
	if ( front==-1 && rear ==-1)	//Deque is empty
	{
		printf("\n\tDeque is Empty ! ");
	}
	else if ( front==rear )
	{
		printf("\tElement Dequed is : %d\n",dq[rear]);
		front=rear=-1;
	}
	else
	{
		printf("\tElement Dequed is : %d\n",dq[rear]);
		rear--;
	}display();
}

int main()
{	printf("\n\t   ***   DEQUE   ***   \n\n");
	printf("   1 - Enqueue an Element at Front  [Push]\n   2 - Dequeue an Element at Front [Push]\n");
	printf("   3 - Enqueue an Element at Rear [Inject] \n   4 - Dequeue an Element at Rear [Inject]\n");
	printf("   5 - Display Deque  \n   6 - Exit program\n");
   		
    while(1)
    {
    	printf("\n # Enter Your Option : ");
    	scanf("%d",&c);
    	switch(c)
    	{
    		case 1 : push();break;
    		case 2 : pop();break;
    		case 3 : inject();break;
    		case 4 : eject();break;
    		case 5 : display();break;
    		case 6 : exit(1);break;
    		default :  printf("Wrong Option Choosed !\n");
    	}printf("\n");
    }
}