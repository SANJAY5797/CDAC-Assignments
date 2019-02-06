#include <stdio.h>
#include <string.h>
 
int main()
{
  int number;
  printf("enter the number to check\n");
  scanf("%d",&number);
	int cubesum=0,temp=number;
  while(temp>0)
  {
    int v=temp%10;
    cubesum+=v*v*v;
    temp=temp/10;
  }
  if(cubesum==number)
  {
      printf("%d is Armstrong Number\n", number);
  }
  else
  {
      printf("%d is not a Armstrong Number\n",number );
  }
  // to stop console from closing
	system("pause");
  return 0;
}
