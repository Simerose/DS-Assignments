#include<stdio.h>
int main(){
	int a[20],n,ele;
	int mid,i;
	
	printf("Enter the number of elements");
	scanf("%d",&n);
	printf("Enter the elements into array in sorted order");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	printf("Enter the element to be found");
	scanf("%d",&ele);
	
		int low=0;
	int high=n-1;
	while(low<=high){
		mid=(low+high)/2;
		
		if (a[mid]==ele){
		
		printf("Element found at index %d",mid);
		break;}
		
		else if(a[mid]<ele){
			low=mid+1;
			
		}
		else if(a[mid]>ele){
			high=mid-1;
		}
	}
	return 0;
}
