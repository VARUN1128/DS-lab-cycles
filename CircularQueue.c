#include <stdio.h>
#include <stdlib.h>
int front=-1,rear=-1,i,arr[5],item,size=5,choice;

void enqueue()
{
	if ( (rear+1)%size == front )
	{
		printf("Queue is Full ");
	}
	else
	{
		printf("\nEnter Element to Insert : ");
		scanf("%d",&item);
		if ( front == -1 && rear == -1 )
		{
			front=0;rear=0;
			arr[rear]=item;
		}
		else
		{
			rear = (rear+1)%size;
			arr[rear]=item;
		}
	}
}

void dequeue()
{
	if ( front == -1 && rear == -1 )
	{
		printf("Queue is Empty \n ");
	}
	else if ( front == rear )
	{
		printf("%d is deleted.\n",arr[front]);
		front=-1;rear=-1;
	}
	else
	{
		printf("%d is deleted.\n",arr[front]);
		front = ( front + 1 )%size;
	}
}

void display()
{
	if ( front == -1 && rear == -1 )
	{
		printf("Queue is Empty \n ");
	}
	else if ( front <= rear )
	{
		for ( i=0 ; i<=rear ; i++ )
		{
			printf("%d ",arr[i]);
		}
	}
	else
	{
		for ( i=front ; i<size ; i++ )
		{
			printf("%d ",arr[i]);
		}
		for ( i=0 ; i<=rear ; i++ )
		{
			printf("%d ",arr[i]);
		}
	}
}

int main()
{
	printf(" 1 - Enqueue an Element\n 2 - Dequeue an Element\n 3 - Display\n 4 - Exit");
	while (1)
	{
		printf("\nEnter your Choice : ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1 : enqueue();break;
			case 2 : dequeue();break;
			case 3 : display();break;
			case 4 : printf("\nExiting the Program!!\n");exit(0);
			default : printf("Wrong choice !!!\n");break;
		}
	}
	return 0;
}
