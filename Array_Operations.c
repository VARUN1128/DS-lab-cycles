#include <stdio.h>
#include <stdlib.h>
int i,j,loc,n,item,size,option,value,temp; //Global Declaration...
void read ( int arr[], int s )
{
	for ( i=0 ; i<s ; i++ )
	{
		printf("Enter Element %d : ",i+1);
		scanf("%d",&arr[i] );
	}
}
void display( int arr[], int s )
{
	printf("\n");
	for ( i=0 ; i<s ; i++ )
	{
		printf("%d \t",arr[i]);
	}
	printf("\n");
}
int binary_search( int arr[], int s ,int item)
{
	int HIGH=(s-1),LOW=0,MID;
	while( LOW <= HIGH )
	{
		MID = LOW + ( HIGH - LOW ) / 2 ;
		if ( arr[MID] == item )
		{ return MID;break; }
		if ( arr[MID] <item )
		{ LOW = MID+1; }
		else
		{ HIGH = MID -1; }
	}
	return -1;
}
void insertion( int arr[], int *s ,int size )
{
	printf("Enter Element to be Inserted : ");
	scanf("%d",&item );
	printf("Enter Location of Element : ");
	scanf("%d",&loc);
	if ( *s == size)
	{
		printf("Array is Full, Insertion is not possible..");
	}
	else
	{
		for ( i=(*s-1) ; i >= (loc-1) ; i-- )
		{
			arr[i+1] = arr[i];
		}
		arr[loc-1] = item;
		*s = *s +1;
		printf("Insertion Completed Successfully...");
	}
}
void deletion( int arr[], int *s )
{
	printf("Enter Element to be Deleted : ");
	scanf("%d",&item );
	value=binary_search(arr,n,item);
	if ( value == -1 )
	{ printf("Element not Present, Deletion not possible \n"); }
	else
	{
		for ( i=value ; i<=(*s-1) ; i++ )
		{
			arr[i]=arr[i+1];
		}
		*s = *s - 1;
		printf("Deletion Completed Successfully...");
	}
}
void bubble_sort( int arr[], int n )
{
	for ( i=0 ; i<n ; i++ )
	{
		for ( j=0 ; j<(n-1) ; j++ )
		{
			if ( arr[j] > arr[j+1])
			{
				arr[j] = arr[j] + arr[j+1];
				arr[j+1] = arr[j] - arr[j+1];
				arr[j] = arr[j] - arr[j+1];
			}
		}
	}
}
int main()
{
	printf("Enter Size of Array : ");
	scanf("%d",&size);
	printf("Enter no. of Elements in Array : ");
	scanf("%d",&n);
	int arr[size];
	printf("Enter Array ...\n\n");
	read(arr,n);
	printf("\n\n 1 - Display Array \n 2 - Insert Element \n 3 - Delete Element ");
	printf("\n 4 - Search Element using Binary Search \n 5 - Sort Array using Bubble Sort");
	printf("\n 6 - Exit");
	while(1)
	{
	printf("\n\nEnter your Option : ");
	scanf("%d",&option);
	switch (option)
	{
		case 1 : display(arr,n);break;
		case 2 : insertion(arr,&n,size);break;
		case 3 : deletion(arr,&n);break;
		case 4 : 	bubble_sort(arr,n);
					printf("Array is Sorted.\n");
					printf("Enter Element to be Searched : ");
					scanf("%d",&item);
					value=binary_search(arr,n,item);
					if ( value == -1 )
					{ printf("Element not Present \n"); }
					else
					{ printf("Element is at Position %d.",value+1); }
					break;
		case 5 : 	bubble_sort(arr,n);
					printf("Array Sorted Successfully...\n");break;
		case 6 : exit(1);break;
		default : printf("Invalid Option Selected...\n ");
		}
	}
}