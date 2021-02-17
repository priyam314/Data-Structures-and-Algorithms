#include <stdio.h>
#include <string.h>

int main(int argc,char* argv[]){
	int l = strlen(argv[1]);
	char c[l];
	for (int i=0 ;i<l;i++){
		c[i]=argv[1][i];
	}
	for (int i=0 ;i<l/2;i++){
		char temp = c[i];
		c[i]= c[l-1-i];
		c[l-1-i]=temp;
	}
	printf("%s",c);
	return 0;
}
 
