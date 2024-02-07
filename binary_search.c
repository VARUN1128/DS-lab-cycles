#include <stdio.h>
int main()
{	
	int s,item,i;
	printf("Enter Size of Array : ");
	scanf("%d",&s);
	int arr[s],value= -1,HIGH=(s-1),LOW=0,MID;
	printf("Enter Array Elements  : ");

	for ( i=0 ; i<s ; i++ )
	{
		scanf("%d",&arr[i] );
	}

	printf("Enter Element to Search : ");
	scanf("%d",&item);

	while( LOW <= HIGH )
	{
		MID = ( HIGH + LOW ) / 2 ;
		if ( arr[MID] == item )
		{ 	value = MID;break; 	}
		if ( arr[MID] <item )
		{ 	LOW = MID+1; 	}
		else
		{ 	HIGH = MID -1; 	}
	}

	if ( value == -1 )
	{ printf("Element not Present \n"); }
	else
	{ printf("Element is at Position %d.",value+1); }	

	return 0;
}