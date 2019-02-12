#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct complex
{
	int real,img;
};
enum operation {
  addition=1,subtraction,multiplication,division,exits
};
void print(struct complex c)
{
	if (c.img >= 0)
        printf("Sum of the complex numbers = %d + %di\n", c.real, c.img);
    else
        printf("Sum of the complex numbers = %d %di\n", c.real, c.img);
    return ;
}
int main(int argc, char const *argv[])
{
	printf("Enter the operation you want to perform\n");
	printf("1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n\n");
	int x,y,z;
	struct complex a,b,c;
  printf("enter the choice in the form of name\n");
  char s[20];
  scanf("%s",s);
  enum operation choice;
  if(strcmp(s,"addition")==0)
  {
    choice=addition;
  }
  else if(strcmp(s,"subtraction")==0)
  {
    choice=subtraction;
  }
  else if(strcmp(s,"multiplication")==0)
  {
    choice=multiplication;
  }
  else if(strcmp(s,"division")==0)
  {
    choice=division;
  }
  else {
    choice=exits;
  }
	//scanf("%d",&choice);
	if(choice==5)
	{
		exit(0);
	}
	if(choice>=1&&choice<=4)
	{
		printf("Enter a and b where a + ib is the first complex number.");
	    printf("\na = ");
	    scanf("%d", &a.real);
	    printf("b = ");
	    scanf("%d", &a.img);
	    printf("Enter c and d where c + id is the second complex number.");
	    printf("\nc = ");
	    scanf("%d", &b.real);
	    printf("d = ");
	    scanf("%d", &b.img);
	}
	if (choice == 1)
    {
        c.real = a.real + b.real;
        c.img = a.img + b.img;
 		print(c);
    }
    else if (choice == 2)
    {
        c.real = a.real - b.real;
        c.img = a.img - b.img;
      	print(c);
    }
    else if (choice == 3)
    {
      c.real = a.real*b.real - a.img*b.img;
      c.img = a.img*b.real + a.real*b.img;
      print(c);
    }
    else if (choice == 4)
    {
      if (b.real == 0 && b.img == 0)
        printf("Division by 0 + 0i isn't allowed.");
      else
      {
        x = a.real*b.real + a.img*b.img;
        y = a.img*b.real - a.real*b.img;
        z = b.real*b.real + b.img*b.img;
 
        if (x%z == 0 && y%z == 0)
        {
          if (y/z >= 0)
            printf("Division of the complex numbers = %d + %di", x/z, y/z);
          else
            printf("Division of the complex numbers = %d %di", x/z, y/z);
        }
        else if (x%z == 0 && y%z != 0)
        {
          if (y/z >= 0)
            printf("Division of two complex numbers = %d + %d/%di", x/z, y, z);
          else
            printf("Division of two complex numbers = %d %d/%di", x/z, y, z);
        }
        else if (x%z != 0 && y%z == 0)
        {
          if (y/z >= 0)
            printf("Division of two complex numbers = %d/%d + %di", x, z, y/z);
          else
            printf("Division of two complex numbers = %d %d/%di", x, z, y/z);
        }
        else
        {
          if (y/z >= 0)
            printf("Division of two complex numbers = %d/%d + %d/%di",x, z, y, z);
          else
            printf("Division of two complex numbers = %d/%d %d/%di", x, z, y, z);
        }
      }
    }
    // to stop console from closing
    system("pause");
	return 0;
}