#include <stdio.h>
#include <stdlib.h>

int parity_check(int x){
    int counter = 0;
    for (int i = sizeof(int)* 8 - 1 ; i >= 0; i-- ){
        // putchar((x & 1u << i)? '1':'0'); 
        // check the binary of x
        ((x & 1u << i)? counter^=1:0);
    }
    // printf("/n");
    
    return counter;
}

int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("%d", parity_check(num));
    
    return 0;
}