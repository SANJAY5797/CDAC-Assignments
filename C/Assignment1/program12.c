#include<stdio.h>
#include<math.h>
int rotate_right(int n,int b)
{
	return ((n>>b)|(n<<(31-b)));
}
int main(int argc, char const *argv[])
{
	int n,b;
	printf("Enter the number to rotate\n");
	scanf("%d",&n);
	printf("Enter the number of positions to rotate\n");
	scanf("%d",&b);
	int res=rotate_right(n,b);
	printf("Result: %d\n",res);
	// to stop console from closing
	system("pause");
	return 0;
}