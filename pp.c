#include <stdio.h>

int f(int x)
{
	static int sum = 0;
	return (sum +=x); 
}
int main ()
{
	printf("%d   ", f(5));
	printf("%d   ", f(5));
	printf("%d   ", f(5));
	printf("%d   ", f(5));
	printf("%d   ", f(5));
	printf("%d   ", f(5));
	return 0;
}