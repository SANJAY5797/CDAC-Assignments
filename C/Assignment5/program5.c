#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Date
{
	int day,month,year;
};
const int month_days[]={31,28,31,30,31,30,31,31,30,31,30,31};
int count_of_leap_years(struct Date d)
{
	int year =d.year;
	if(d.month<=2)
	{
		year--;
	}
	return (year/4-year/100+year/400);
}
long int diff_years(struct Date a,struct Date b)
{
	long int num1=a.year*365+a.day;
	for(int i=0;i<a.month-1;i++)
		num1+=month_days[i];
	num1+=(count_of_leap_years(a));
	long int num2=b.year*365+b.day;
	for(int i=0;i<b.month-1;i++)
		num2+=month_days[i];
	num2+=(count_of_leap_years(b));
	return abs(num1-num2);
}
int main(int argc, char const *argv[])
{
	printf("Enter the dates in the following format\n day-month-year\n");
	printf("Enter the first date\n");
	struct Date a,b;
	scanf("%d %d %d",&a.day,&a.month,&a.year);
	printf("Enter the second date\n");
	scanf("%d %d %d",&b.day,&b.month,&b.year);
	long int ans=diff_years(a,b);
	printf("The difference of dates is %d days\n",ans);
	// to stop console from closing
	system("pause");
	return 0;
}