#include <stdio.h>

void prefix_sum(int *a, int *b, int*c){
	*c = *a + *b + *c;
	*b = *a + *b;
}

void main(){
	int A;
	int B;
	int C;
	A = 1;
	B = 1;
	C = 1;

	prefix_sum(&A, &B, &C);
	printf("%d %d %d \n" , A,B,C);
}
