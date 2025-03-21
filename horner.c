#include<stdio.h>

double Horners_Rule(int degree ,double coef[] ,double x)
{
	double result = coef[degree];
	
	for(int i = degree - 1 ; i >= 0 ; i--)
	{
		result = result * x + coef[i];
	}
	return result;
}

int main()
{
	int degree;
	printf("Enter the degree of the polynomial:");
	scanf("%d",&degree);
	
	double coef[degree + 1];
	for(int i = degree ; i >= 0 ; i--)
	{
		printf("Coefficient of x^%d:", i );
		scanf("%lf",&coef[i]);
	}
	
	double x;
	printf("Enter the value of x: ");
	scanf("%lf",&x);
	
	double result = Horners_Rule(degree ,coef ,x);
	
	printf("The result of the polynomial evaluation at x = %.2lf is: %.2lf. \n", x , result);
	
	return 0;
}


