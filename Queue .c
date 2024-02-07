#include<stdio.h>
#include<stdlib.h>
int a[3],front=-1,rear=-1,c,item,n=3;
void enqueue()
{
	printf("Enter Element to Enqueue : ");
    scanf("%d",&item);
    if(rear==n-1)
    {
        printf("Queue is Full\n");
    }
    else if((front==-1)&&(rear==-1))
    {
        rear=0,front=0;
        a[rear]=item;
    }
    else
    {
        rear+=1;
        a[rear]=item;
	}
}
void dequeue()
{
    if((front==-1)&&(rear==-1))
    {
        printf("Queue is empty\n");
    }
    else if ( rear==front )
    {
        printf("%d is deleted\n",a[front]);  
        front=-1,rear=-1;
    }
    else
    {
        printf("%d is deleted\n",a[front]);
        front++;
    }
}
void display()
{
    if ( ( front==-1 )&&( rear==-1 ) )
    {   printf("Queue empty\n");   }
    else
    {
        printf("Queue is : ");
        for(int i=front;i<=rear;i++)
        {
            printf("%d  ",a[i]);
        }printf("\n");
    } 
}   
int main()
{
    printf(" 1 - Enqueue an Element \n 2 - Dequeue an Element ");
   		printf("\n 3 - Display Queue \n 4 - Exit\n");
    while(1)
    {
    	printf("Enter Your Option : ");
    	scanf("%d",&c);
    	printf("\n");
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