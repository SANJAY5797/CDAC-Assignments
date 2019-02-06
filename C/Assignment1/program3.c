#include<stdio.h>
int main(int argc, char const *argv[])
{
	int value=0xCAFE;
	int count=0;
	count+=((value&1)?1:0);
	count+=((value&2)?1:0);
	count+=((value&4)?1:0);
	count+=((value&8)?1:0);
	if(count>=3)
	{
		printf("the three of the last bits of value 0x%0X are on\n",value);
	}
	else
	{
		printf("less than 3 of the last 4 bits are set\n");
	}
	int res=(((value&0xff)<<8)|(value>>8));
	printf("reversed byte order is 0x%0X\n",res);
	int res2;
	int temp=value&0xfff0;
	value=(value&0x000f)<<12;
	temp=(temp&0xffff)>>4;
	res2=temp|value;
	printf("result after rotating 4 bits is 0x%0X\n", res2);
	// to stop console from closing
	system("pause");
	return 0;
}