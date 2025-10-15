#include<stdio.h>
int main(){
	int n,i,j,temp,count;
	printf("Enter the number of elements into the array");
	scanf("%d",&n);
	
	int a[n];
	printf("Enter the elements of the array");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	for(i=0;i<n-1;i++)
	{
			for(j=0;j<n-i-1;j++)
			{
				if (a[j]>a[j+1]);
				{
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
	}
	
	for(i=0;i<n;i++)//counting distinct numbers
	{
		while(i<n-1 && a[i]==a[i+1])
		{
			i++;
		}
		count++;
	}
	printf("The number of distinct elements are:%d",count);
 return 0;
}

