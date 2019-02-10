#include<stdio.h>
#include<string.h>
struct st
{
	int x;
	char y;
};
union un
{
	int x;
	char y;
};
int main(int argc, char const *argv[])
{
	struct st st1;
	union un un1;
	printf("The size of structure is %d\n",sizeof(st1));
	printf("The size of union is %d\n",sizeof(un1));
	// to stop console from closing
	system("pause");
	return 0;
}