#include <stdio.h>
int c,r1,c1,r2,c2,n1,n2,i,j,k,m,n;
void read(int ptr[][c],int m,int n)
{
	for ( i=0 ; i<m ; i++ )
	{
		printf("Enter Row %d ELements : ",i+1);
		for ( j=0 ; j<n ; j++ )
		{	scanf("%d",&ptr[i][j] );	}
	}
}
void display(int ptr[][c],int m,int n)
{
	for ( i=0 ; i<m ; i++ )
	{
		printf("\n\n\t\t");
		for ( j=0 ; j<n ; j++ )
		{	printf("\t%d",ptr[i][j]);	}
	}
	printf("\n\n");
}
void tuple(int tup[][3],int mat[][c],int m, int n)
{
	tup[0][0]=m;tup[0][1]=n;
	k=1;
	for ( i=0 ; i<m ; i++ )
	{
		for ( j=0 ; j<n ; j++ )
		{
			if ( mat[i][j] != 0 )
			{
				tup[k][0]=i;
				tup[k][1]=j;
				tup[k][2]=mat[i][j];
				k++;
			}
		}
	}
	tup[0][2]=k-1;c=3;
	display(tup,k,3);
}
void transpose(int a[][3],int b[][3],int m,int n )
{
	k=1;
	b[0][0]=a[0][1];
	b[0][1]=a[0][0];
	b[0][2]=a[0][2];
	for ( i=0 ; i<m ; i++ )
	{
		for ( j=1 ; j<=n ; j++ )
		{
			if ( a[j][1] == i )
			{
				b[k][0]=a[j][1];
				b[k][1]=a[j][0];
				b[k][2]=a[j][2];
				k++;
			}
		}
	}c=3;
	display(b,k,3);
}
void add(int m1[][3],int m2[][3],int m3[][3])
 {
    m3[0][0]=m1[0][0];
    m3[0][1]=m1[0][1];
    m=1,n=1,k=1;
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            if( (m1[m][0]==i && m1[m][1]==j) && (m2[n][0]==i && m2[n][1]==j))
            {
                m3[k][0]=m1[m][0];
                m3[k][1]=m1[m][1];
                m3[k][2]=m1[m][2]+m2[n][2];
                m++,k++,n++;
            }
            else if((m1[m][0]==i) && (m1[m][1]==j))
            {
                m3[k][0]=m1[m][0];
                m3[k][1]=m1[m][1];
                m3[k][2]=m1[m][2];
                m++,k++;
            }
            else if((m2[n][0]==i) && (m2[n][1]==j))
            {
                m3[k][0]=m2[n][0];
                m3[k][1]=m2[n][1];
                m3[k][2]=m2[n][2];
                n++,k++;
            }
        }
   }
   m3[0][2]=k-1;c=3;
   display(m3,k,3);
 }
void main()
{
	int tup1[50][3],tup2[50][3],tra1[50][3],tra2[50][3],sum[50][3];
	printf("Enter the size of Matrix 1 Row and Column : ");
	scanf("%d %d",&r1,&c1);
	printf("Enter the size of Matrix 2 Row and Column : ");
	scanf("%d %d",&r2,&c2);
	int mat1[r1][c1],mat2[r2][c2];
	printf("\nEnter Matrix 1 Elements :-\n\n");c=c1;
	read(mat1,r1,c1);
	printf("\nEnter Matrix 2 Elements :-\n\n");c=c2;
	read(mat2,r2,c2);c=c1;
	printf("\n\n\tMatrix 1\n");
	display(mat1,r1,c1);c=c2;
	printf("\n\n\tMatrix 2\n");
	display(mat2,r2,c2);
	printf("\n\n\tTuple form of Matrix 1 :-\n");c=c1;
	tuple(tup1,mat1,r1,c1);c=c2;
	printf("\n\n\tTuple form of Matrix 2 :-\n");
	tuple(tup2,mat2,r2,c2);
	n1=tup1[0][2];n2=tup2[0][2];
	printf("\n\n\tTraspose of Matrix 1 in Tuple form is :-\n");
	transpose(tup1,tra1,c1,n1);
	printf("\n\n\tTraspose of Matrix 2 in Tuple form is :-\n");
	transpose(tup2,tra2,c2,n2);
	if((r1!=r2) && (c1!=c2))
    {    printf("Incompatible Size, Addition Not Possible !!!\n");    }
    else
    {	printf("\n\n\tSum of Matrix 1 & 2\n");
		add(tup1,tup2,sum); }
}
/*

Enter the size of Matrix 1 Row and Column : 4 5
Enter the size of Matrix 2 Row and Column : 4 5

Enter Matrix 1 Elements :-
Enter Row 1 ELements : 0 0 1 0 3
Enter Row 2 ELements : 0 0 0 4 0
Enter Row 3 ELements : 0 7 0 0 0
Enter Row 4 ELements : 0 0 6 0 0

Enter Matrix 2 Elements :-
Enter Row 1 ELements : 0 0 2 0 0
Enter Row 2 ELements : 0 0 0 0 0
Enter Row 3 ELements : 0 4 6 0 0
Enter Row 4 ELements : 0 0 3 0 0

        Matrix 1

                        0       0       1       0       3

                        0       0       0       4       0

                        0       7       0       0       0

                        0       0       6       0       0


        Matrix 2

                        0       0       2       0       0

                        0       0       0       0       0

                        0       4       6       0       0

                        0       0       3       0       0


        Tuple form of Matrix 1 :-

                        4       5       5

                        0       2       1

                        0       4       3

                        1       3       4

                        2       1       7

                        3       2       6


        Tuple form of Matrix 2 :-

                        4       5       4

                        0       2       2

                        2       1       4

                        2       2       6

                        3       2       3


        Traspose of Matrix 1 in Tuple form is :-

                        5       4       5

                        1       2       7

                        2       0       1

                        2       3       6

                        3       1       4

                        4       0       3


        Traspose of Matrix 2 in Tuple form is :-

                        5       4       4

                        1       2       4

                        2       0       2

                        2       2       6

                        2       3       3


        Sum of Matrix 1 & 2

                        4       5       6

                        0       2       3

                        0       4       3

                        1       3       4

                        2       1       11

                        2       2       6

                        3       2       9

*/