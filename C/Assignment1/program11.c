#include<stdio.h>
long double power(long double ans,long int exponent)
{
	long double res=1;
	for(long int i=1;i<=exponent;i++)
		res*=ans;
	return res;
}
int main(int argc, char const *argv[])
{
	long double rate_of_interest=5;
	long int principal_amount=5000000;
	long int period=10;
	printf("Simple Interest is:  ");
	long double simple_interest=((long double)principal_amount*rate_of_interest*period/100);
	printf("%Lf\n",simple_interest);
	long double compound_interest;
	printf("Compound Interest when done annually is:  ");
	compound_interest=((power((1+rate_of_interest/100.0),period)*principal_amount)- principal_amount);
	printf("%Lf\n",compound_interest);
	printf("Compound Interest when done semi-annually is:  ");
	compound_interest=((power((1+rate_of_interest/200.0),2*period)*principal_amount)-principal_amount);
	printf("%Lf\n",compound_interest);
	printf("Compound Interest when done quarterly is:  ");
	compound_interest=((power((1+rate_of_interest/400.0),4*period)*principal_amount)- principal_amount);
	printf("%Lf\n",compound_interest);
	printf("Compound Interest when done monthly is:  ");
	compound_interest=((power((1+rate_of_interest/1200.0),12*period)*principal_amount)- principal_amount);
	printf("%Lf\n",compound_interest);
	printf("Compound Interest when done daily is:  ");
	compound_interest=((power((1+rate_of_interest/36500.0),365*period)*principal_amount)- principal_amount);
	printf("%Lf\n",compound_interest);
	// to stop console from closing
	system("pause");
	return 0;
}