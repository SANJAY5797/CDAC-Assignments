#include <stdio.h>
 
void main()
{
    int  num, binary_val, decimal_val = 0, base = 1, rem;
 
    printf("Enter a binary number(1s and 0s) \n");
    scanf("%d", &num); /* maximum five digits */
    binary_val = num;
    while (num > 0)
    {
        rem = num % 10;
        decimal_val = decimal_val + rem * base;
        num = num / 10 ;
        base = base * 2;
    }
    printf("The Binary number is = %d \n", binary_val);
    printf("Its decimal equivalent is = %d \n", decimal_val);
    binary_val=0;
    num=decimal_val;
    while(decimal_val>0)
    {
        binary_val=binary_val*10+(decimal_val%2);
        decimal_val=decimal_val/2;
    }
    printf("Its decimal equivalent is = %d \n", num);
    printf("The Binary number is = %d \n", binary_val);
    // to stop console from closing
    system("pause");
}