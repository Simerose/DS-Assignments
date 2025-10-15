#include<stdio.h>
int main(){
	int a[20],i,j,n;
	int temp;
	printf("Enter the number of elements");
	scanf("%d",&n);
	
	printf("Enter the elements into the array");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	//Bubble Sort
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if (a[j]>a[j+1]){
			
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
		}
	}
	printf("Sorted array in ascending order is:");
	for(i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
	
	return 0;
}
