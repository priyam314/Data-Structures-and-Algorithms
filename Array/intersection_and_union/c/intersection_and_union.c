#include <stdio.h>

int main(){
	printf("length of first array\n");
	int first;
	scanf("%d",&first);
	printf("length of second array\n");
	int second;
	scanf("%d",&second);
	int arr1[first],arr2[second];
	printf("elements of first array\n");
	for (int i=0;i<first;i++){
		scanf("%d",&arr1[i]);
	}
	printf("elements of second array\n");
	for (int i=0;i<second;i++){
		scanf("%d",&arr2[i]);
	}
	int i=0,j=0,count=0;
	while (i<first && j<second){
		if(arr1[i]<arr2[j]){
			printf("%d ",arr1[i++]);
		}else if(arr1[i]>arr2[j]){
			printf("%d ",arr2[j++]);
		}else{
			printf("%d ",arr2[j++]);
			i++;
		}
		count++;
	}
	while(i<first){
		printf("%d ",arr1[i++]);
		count++;
	}
	while(j<second){
		printf("%d ",arr2[j++]);
		count++;
	}
	printf("\n%d ",count);
	
	return 0;
}
