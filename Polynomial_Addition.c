#include<stdio.h>
int i,p,q,n1,n2;
struct poly
{
	int coef;
	int expo;
}p1[10],p2[10],p3[10];
void read( struct poly p[10], int n ) //For Input
{
	for( i=0 ; i<=n ; i++ )
	{
		p[i].expo = i;
		scanf(" %d",&p[i].coef );
	}
}
void display( struct poly p[10], int n ) //For Printing
{
	for( i=n ; i>0 ; i-- )
	{
		printf("%dx^%d + ",p[i].coef,p[i].expo);
	}
 	printf("%d\n",p[0].coef);
}
void add( struct poly m[10],struct poly n[10],struct poly o[10],int p,int q )
{
	for( i=q+1 ; i<=p ; i++ )
	{
		p3[i].coef=o[i].coef;
		p3[i].expo=o[i].expo;
	} 
	 for( i=0 ; i<=q ; i++ )
	{
		p3[i].coef=m[i].coef+n[i].coef;
		p3[i].expo=m[i].expo;
	}
	display(p3,p);
}
int main()
{
	 printf("Enter the degrees of Polynomial 1 & 2 : ");
	 scanf("%d%d",&n1,&n2);
	 printf("Enter Coeffients of Polynomial 1 : "); //from 0 
	 read(p1,n1);
	 printf("Enter Coeffients of Polynomial 2 : "); //from 0 
	 read(p2,n2);
	 printf("\n Entered polynomial 1 is \n ");
	 display(p1,n1);
	 printf("\n Entered polynomial 2 is \n ");
	 display(p2,n2);
	 printf("\n Sum of Polynomial 1 & 2 is :\n ");
	 if ( n1>=n2 )
	 { add(p1,p2,p1,n1,n2); }
	 else if ( n2>n1 )
	 { add(p1,p2,p2,n2,n1); }
	 return 0;
}