#include <stdio.h>

int main(int argc, char *argv[]){

	int array[argc-1];
	for (int i = 0;i<argc-1;i++){
		array[i]=argv[i+1];
	}
	int temp;
	int start=0;
	int end = argc-1;
    	while (start < end)
    	{
        	temp = array[start];   
        	array[start] = array[end];
        	array[end] = temp;
        	start++;
        	end--;
    	}   
	for (int i=0 ;i<argc-1;i++){
		printf("%d ",array[i]);
	}
	return 0;
}
