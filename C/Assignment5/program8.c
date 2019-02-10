#include<stdio.h>
#include<stdlib.h>
#define print(x,y) x##y
#define mkstr(xy) #xy
#define TEST 1
int main(int argc, char const *argv[])
{
	int xy=10;
	#if TEST>=1
	printf("the value of %s is %d\n",mkstr(xy),print (x,y));
	#else
	printf("TEST is not defined\n");
	#endif
	// to stop console from closing
	system("pause");
	return 0;
}