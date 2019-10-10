#include <stdio.h>
#include <stdlib.h>

void main(){
    int binary[10], num, i;
    printf("Enter the number: ");
    scanf("%d", &num);
    for(i = 0; num > 0; i++){
        binary[i] = num % 2;
        num = num / 2;
    }

    for(i = i - 1; i >= 0; i--){
        printf("%d", binary[i]);
    }

    printf("\n");
}
