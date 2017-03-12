#include <stdio.h>

float fahrenheitToCelsius(float fahrenheit) 
{
	return (5.0 / 9.0) * (fahrenheit - 32.0);
}

int main()
{
	printf("FAHRENHEIT\tCELSIUS\n");
	
	float fahrenheit, celsius;
	int lower, upper, step;
	
	lower = 0;
	upper = 300;
	step = 20;
	
	for (fahrenheit = upper; fahrenheit >= lower; fahrenheit -= step) {
		celsius = fahrenheitToCelsius(fahrenheit);
		printf("%3.0f\t%.1f\n", fahrenheit, celsius);
	}
	
}