#include<stdio.h>
int main()
{
	int m,n,i,j;
	printf("Enter the dimensions of the matrix:");
	scanf("%d%d",&m,&n);
	
	int matrix[50][50],transpose[50][50];
	
	printf("Enter the elements of matrix");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&matrix[i][j]);
			printf("%d",matrix[i][j]);
		}
	}

	
	
	for(i=0;i<m;i++)//transpose
	{
		for(j=0;j<n;j++)
		transpose[j][i]=matrix[i][j];
	}
	
	printf("The transpose of the matrix is:");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d",transpose[i][j]);
		}
	}
	return 0;
	
}
