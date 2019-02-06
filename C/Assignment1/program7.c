#include<stdio.h>
#include<limits.h>
int main(int argc, char const *argv[])
{
	int number,total_count=0,max_value=-1,min_value=INT_MAX;
	float avg_value=0;
	while(1)
	{
		scanf("%d",&number);
		if(number<=0)
			break;
		total_count++;
		if(number>max_value)
			max_value=number;
		if(number<min_value)
			min_value=number;
		avg_value+=number;
	}
	avg_value/=total_count;
	printf("total count of input numbers is %d\n",total_count);
	printf("maximum value of the numbers is %d\n",max_value);
	printf("minimum value of the numbers is %d\n",min_value);
	printf("average of all the numbers is %f\n", avg_value);
	// to stop console from closing
	system("pause");
	return 0;
}