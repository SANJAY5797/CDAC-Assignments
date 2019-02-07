#include<stdio.h>
#include<stdlib.h>
void prompt_func(unsigned int number)
{
	printf("Select the operation\n");
	printf("1. Bitwise AND\n");
	printf("2. Bitwise OR\n");
	printf("3. Bitwise XOR\n");
	int choice;
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: printf("%x\n",(number&0xf0) );
				break;
		case 2: printf("%x\n",(number|0xff) );
				break;
		case 3: printf("%x\n",(number^0xfa) );
				break;
		default: printf("please choose a valid option\n");
					break;
	}
	printf("\n");
	return ;
}
int main(int argc, char const *argv[])
{
	printf("Enter a hexadecimal number\n");
	unsigned int number;
	scanf("%x",&number);
	while(1)
	{
		printf("1. Display the hexadecimal equivalent of the one's complement\n");
		printf("2. Carry out a masking operation and then display the hexadecimal equivalent of the result\n");
		printf("3. Carry out a bit shifting operation and then display the hexadecimal equivalent of the result\n");
		printf("4. Exit\n\n");
		int choice;
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("hexadecimal equivalent of the one’s equivalent is 0x%x\n\n", ~number);
					break;
			case 2: prompt_func(number);
					break;
			case 3: printf("hexadecimal equivalent of the resultant value is 0x%x\n\n",(number>>3) );
				break;
			case 4:
				exit(0);
		}
	}

	return 0;
}
