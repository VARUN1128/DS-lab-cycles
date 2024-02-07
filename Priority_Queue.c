#include<stdio.h>
#include<stdlib.h>

int front=-1,rear=-1,c,i,item,priority,size=3,loc;

struct prio_Q
{
    int Item;
    int Priority;
}pq[3];

void display()
{
    if ( front==-1 && rear==-1 )
    {   printf("\tPriority Queue is empty\n");   }
    else
    {
        printf("\n\tPriority Queue is :-\n");
        printf("\tElements   :  ");
        
        for(int i=front;i<=rear;i++)        // for printing Elements only
        {
            printf("%-3d  ",pq[i].Item);
        }
        printf("\n\tPriority   :  ");       // for printing element's priority
        for(int i=front;i<=rear;i++)
        {
            printf("%-3d  ",pq[i].Priority);
        }
        printf("\n");
    } 
}   
void enqueue()
{
	if ( front==0 && rear==size-1 )        // Priority Queue is Full
    {
        printf("\n\tPriority Queue is Full");
    }
    else
    {   printf("\tEnter Element to Enqueue : ");
        scanf("%d",&item);
        printf("\tEnter Priority of Element : ");
        scanf("%d",&priority);
        if ( front==-1 && rear ==-1)    // Priority Queue is empty
        {
            front=rear=0;
            pq[front].Item=item;
            pq[front].Priority=priority;
        }
        else if ( rear==size-1 )       // No space at rear but space in front
        {
            for( i=front ; i<=rear ; i++ )      // Shift all elements one  position to left
            {
                pq[i-1]=pq[i];
            }
            front--;rear--;

            for( i=rear ; i>=front ; i-- )      // Finding location to element to enqueue
            {
                if ( pq[i].Priority <= priority )
                {
                    break;
                }
            }
            loc=i+1;

            for( i=rear ; i>=loc ; i-- )        // Shifting all elements till enqueue element to left
            {
                pq[i+1]=pq[i];
            }
            pq[loc].Item=item;
            pq[loc].Priority=priority;
            rear++;
        }
        else        
        {
            for( i=rear ; i>=front ; i-- )      // Finding location to element to enqueue
            {
                if ( pq[i].Priority <= priority )
                {
                    break;
                }
            }
            loc=i+1;

            for( i=rear ; i>=loc ; i-- )        // Shifting all elements till enqueue element to left
            {
                pq[i+1]=pq[i];
            }
            pq[loc].Item=item;
            pq[loc].Priority=priority;
            rear++;
        }display();
    }
}
void dequeue()
{
    if ( front==-1 && rear==-1 )        // Priority Queue is Empty
    {
        printf("\n\tPriority Queue is Empty");
    }
    else if ( front==rear )     // Priority Queue have only one element
    {
        printf("\tElement Dequeued is : %d with Priority : %d\n",pq[front].Item,pq[front].Priority);
        front=rear=-1;
    }
    else
    {
        printf("\tElement Dequeued is : %d with Priority : %d\n",pq[front].Item,pq[front].Priority);
        front++;
    }
    display();
}

int main()
{
    printf("\n\t   ***   PRIORITY QUEUE   ***   \n\n");
    printf("   1 - Enqueue an Element \n   2 - Dequeue an Element ");
   	printf("\n   3 - Display Queue \n   4 - Exit\n\n");
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