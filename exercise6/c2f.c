#include <stdio.h>
int main()
{
	int lower;
	int upper;
	printf("Lower limit: ");
	scanf("%d", &lower);
	printf("Upper limit: ");
	scanf("%d", &upper);
	printf("Celcius\t\tFahrenheit\n");
	printf("=============================\n");
	float newupper = lower;
	while(lower <= upper){
		newupper = newupper * (9/5) + 32;
		printf("%d\t\t%.1f \n", lower, newupper);
		lower+=5;
	}
}
