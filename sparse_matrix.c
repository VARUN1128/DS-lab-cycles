#include <stdio.h>
int i,j,r,c;		//Code by Venkidesh...

void read(int ptr[][c], int m, int n)
{
	for ( i=0 ; i<m ; i++ )
	{
		for ( j=0 ; j<n ; j++)
		{
			printf("Enter Row %d Column %d Element : ",i+1,j+1);
			scanf("%d", (*(ptr + i) + j) );
		}
	}
}

void display(int ptr[][c], int m, int n)
{
	for ( i=0 ; i<m ; i++ )
	{
		printf("\n\n");
		for ( j=0 ; j<n ; j++)
		{
			printf("\t %d  ",ptr[i][j] );
		}
	}
}

int main()
{
	printf("Enter Column Size : ");
	scanf("%d",&r);
	printf("Enter Row Size    : ");
	scanf("%d",&c);
	int arr[r][c],spr[r*c][3];
	read(arr,r,c);
	printf("\n  Entered Matrix is ...\n");
	display(arr,r,c);
	printf("\n\n  It's 3 Tuple Form is...\n\n");
	spr[0][0]=r;
	spr[0][1]=c;
	int a=1;

	for ( i=0 ; i<r ; i++ )
	{
		for ( j=0 ; j<c ; j++)
		{
			if ( arr[i][j]!= 0 )
			{
				spr[a][0]=i;
				spr[a][1]=j;
				spr[a][2]=arr[i][j];
				a++;
			}
		}
	}
	spr[0][2]=a-1;
	for ( i=0 ; i<a ; i++ )
	{
		printf("\n\n");
		for ( j=0 ; j<3 ; j++)
		{
			printf("\t %d  ",spr[i][j] );
		}
	}
	printf("\n\n");
	return 0;				
}

/*  

 Output 


		
		Enter Column Size : 4
		Enter Row Size    : 4
		Enter Row 1 Column 1 Element : 0
		Enter Row 1 Column 2 Element : 0
		Enter Row 1 Column 3 Element : 9
		Enter Row 1 Column 4 Element : 0
		Enter Row 2 Column 1 Element : 0
		Enter Row 2 Column 2 Element : 1
		Enter Row 2 Column 3 Element : 0
		Enter Row 2 Column 4 Element : 0
		Enter Row 3 Column 1 Element : 5
		Enter Row 3 Column 2 Element : 0
		Enter Row 3 Column 3 Element : 9
		Enter Row 3 Column 4 Element : 0
		Enter Row 4 Column 1 Element : 8
		Enter Row 4 Column 2 Element : 0
		Enter Row 4 Column 3 Element : 0
		Enter Row 4 Column 4 Element : 6

		  Entered Matrix is ...


		         0       0       9       0

		         0       1       0       0

		         5       0       9       0

		         8       0       0       6

		  It's Array Representation is...



		         4       4       6

		         0       2       9

		         1       1       1

		         2       0       5

		         2       2       9

		         3       0       8

		         3       3       6
*/