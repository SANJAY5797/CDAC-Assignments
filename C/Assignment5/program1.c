#include<stdio.h>
#include<string.h>
struct time
{
	int hrs;
	int mins;
	int sec;
};
int main(int argc, char const *argv[])
{
	struct time var1;
	printf("Enter the time in 24hours format\n");
	scanf("%d %d %d",&var1.hrs,&var1.mins,&var1.sec);
	printf("The entered time is\n");
	printf("%d:%d:%d\n",var1.hrs,var1.mins,var1.sec);
	// to stop console from closing
	system("pause");
	return 0;
}