#include <stdio.h>
int i,j,r,c;		

void read(int ptr[][c], int m, int n)
{
	for ( i=0 ; i<m ; i++ )
	{
		printf("Enter Row %d Elements : ",i+1);
		for ( j=0 ; j<n ; j++)
		{
			
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
	printf("Enter Row and Column Size    : ");
	scanf("%d %d",&r,&c);
	int arr[r][c],spr[r*c][3],tra[c][r],a=1,k=1;
	read(arr,r,c);
	printf("\n  Entered Matrix is ...\n");
	display(arr,r,c);
	printf("\n\n  It's 3 Tuple Form is...\n\n");
	spr[0][0]=r;
	spr[0][1]=c;

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

	tra[0][0]=spr[0][1];tra[0][1]=spr[0][0];tra[0][2]=spr[0][2];
	int m=spr[0][1],n=spr[0][2];

	
		for ( j=1 ; j<=n ; j++)
		{
			
				tra[k][0]=spr[j][1];
				tra[k][1]=spr[j][0];
				tra[k][2]=spr[j][2];
				k++;
			
		}
	
	
	printf("\n\n  It's transpose is \n\n");
	for ( i=0 ; i<a ; i++ )
	{
		printf("\n\n");

		for ( j=0 ; j<3 ; j++)
		{
			printf("\t %d  ",tra[i][j] );
		}
	}
	printf("\n\n");

	display(tra,a,3);
	return 0;				
}