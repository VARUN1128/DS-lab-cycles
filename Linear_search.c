#include <stdio.h>
int main()
{
	int s,i,item,flag=0;
	printf("\nEnter the Size of the Array :\t");
	scanf("%d",&s);
	int arr[s];
	printf("Enter Array Elements: ");

	for ( i=0 ; i<s ; i++ )
	{
		scanf("%d",&arr[i]);
	}	
	printf("\n\nEnter The Element To Search: \t");
	scanf("%d",&item);
	
	for ( i=0 ; i<s ; i++ )
	{
		if ( item == arr[i] )
		{
			flag=1;
			printf("\nThe Element is present at index %d",i);
		}
	}
	
	if ( flag == 0 )
	{
		printf("\nThe Element is not present.");
	}

	return 0;
}
