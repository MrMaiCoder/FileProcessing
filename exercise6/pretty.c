#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
	char str[10][10];
	int num[10];
	int count = -1;
	do{
		count++;
		scanf("%s %d", str[count], &num[count]);
	}while(count < 10 && strcmp(str[count], "DONE"));
       	printf("====================\n");
	for (int i = 0; i < count; i++){
		printf("%-15s %03d\n", str[i], num[i]);
	}
	printf("====================\n");
	return 0;
}
	
