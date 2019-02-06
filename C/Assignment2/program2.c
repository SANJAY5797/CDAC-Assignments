#include <stdio.h>
#include<string.h>
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
    char arr[10];
    int i=0;
    while(decimal_val>0)
    {
        rem=decimal_val%16;
        arr[i]=(rem>9)?(rem-10+'A'):(rem+'0');
        i++;
        decimal_val=decimal_val/16;
    }
    i--;
    printf("Hexadecimal value of %d is \n",binary_val );
    while(i>=0)
    {
        printf("%c",arr[i]);
        i--;
    }
    printf("\n");
    printf("Enter Hexadecimal value in the form of string\n");
    char s[10]="CFA9";
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++)
    {
        switch(s[i])
        {
            case '0':printf("0000");break;
            case '1':printf("0001");break;
            case '2':printf("0010");break;
            case '3':printf("0011");break;
            case '4':printf("0100");break;
            case '5':printf("0101");break;
            case '6':printf("0110");break;
            case '7':printf("0111");break;
            case '8':printf("1000");break;
            case '9':printf("1001");break;
            case 'A':printf("1010");break;
            case 'a':printf("1010");break;
            case 'B':printf("1011");break;
            case 'b':printf("1011");break;
            case 'c':printf("1100");break;
            case 'C':printf("1100");break;
            case 'D':printf("1101");break;
            case 'd':printf("1101");break;
            case 'e':printf("1110");break;
            case 'E':printf("1110");break;
            case 'f':printf("1111");break;
            case 'F':printf("1111");break;
        }
    }
    printf("\n");
    //to stop console from closing 
    system("pause");
}