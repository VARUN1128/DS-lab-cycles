#include<stdio.h>
#include<stdlib.h>
int a[3],top=-1,c,item,n=3;
void push()
{
	printf("Enter Element to PUSH : ");
    scanf("%d",&item);
    if(top==n-1)
    {    printf("Stack Overflow\n");   }
    else
    {
    	top++;
        a[top]=item;
    }
}
void pop()
{
    if(top == -1)
    {    printf("Stack is Empty\n");    }
    else
    {
        printf("Element %d is Popped\n",a[top]);
        top--;
    }
}
void display()
{
    if(top==-1)
    {    printf("Stack empty\n");    }
    else
    {
        printf("Stack is  :");
        for(int i=0;i<=top;i++)
        {    printf("%d  ",a[i]);    }
        printf("\n");
    }
}
int main()
{
    printf(" 1 - PUSH an Element \n 2 - POP an Element ");
    printf("\n 3 - Display Stack \n 4 - Exit\n");
    while(1)
    {
    	printf("Enter Your Option : ");
    	scanf("%d",&c);
    	printf("\n");
    	switch(c)
    	{
    		case 1 : push();break;
    		case 2 : pop();break;
    		case 3 : display();break;
    		case 4 : exit(1);break;
    		default :  printf("Wrong Option Choosed !\n");
    	}	
    	 printf("\n");
    }
}  