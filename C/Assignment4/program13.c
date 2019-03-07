#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int expand(char cInputString[100],char cExpandedString[300])
{
	long int i=(long int )0,k=0,j,first,last,valid,validr;
	
	 while(cInputString[i]!='\0')//checking till null character
      {
		 //storing each character into the new string
            cExpandedString[k++]=cInputString[i];
              i++;
		//storing character until it is not the end and not range character
             while((cInputString[i]!='-')&&(cInputString[i]!='\0'))
             {
                    cExpandedString[k++] = cInputString[i];
                    i++;
             }
		 //now if it is not the end character we have to fill the range
             if(cInputString[i]!='\0')
            {
                   first=i-1;last=i+1;
		     //valid is 1 if we have increasing range
		     //validr is 1 if we have decreasing range
                   valid=0;validr=0;
		     //checking if the range is increasing 
                   if(cInputString[first]>='A' && ((cInputString[last]>='A')&&(cInputString[last]>=cInputString[first])))
                   valid=1;
                   else if((cInputString[first]>='a' && ((cInputString[last]>='a')&&(cInputString[last]>=cInputString[first]))))
                   valid=1;
                   else if(cInputString[first]>='0' && ((cInputString[last]>='0')&&(cInputString[last]>=cInputString[first])))
                   valid=1;
			
		    //checking if the range is decreasing 
		     
                   else if((cInputString[last]>='A' && ((cInputString[first]>='A')&&(cInputString[first]<=cInputString[last]))))
                   validr=1;
                   else if((cInputString[last]>='a' && ((cInputString[first]>='a')&&(cInputString[first]<=cInputString[last]))))
                   validr=1;
                   else if((cInputString[last]>='0' && ((cInputString[first]<='9')&&(cInputString[first]>=cInputString[last]))))
                   validr=1;
               		else//means invalid
               		{
               			return 1;
               		}
		     //filling the increasing range
                   if(valid)
                   {
                          for(j=cInputString[i-1]+1;j<cInputString[i+1];j++)
                          cExpandedString[k++] = j;
                          i++;
                  }
		     //filling the decreasing range
                  else if(validr)
                 {
                         for(j=cInputString[i-1]-1;j>cInputString[i+1];j--)
                         cExpandedString[k++]=j;
                         i++;
                 }
 
           }
           else break;
       }
	
	cExpandedString[k]='\0';
	return 0;
}
int main(int argc, char const *argv[])
{
	char s1[50],s2[100];
	printf("Enter the string\n");
	scanf("%[^\n]s",s1);
	int nExpandStatus = expand(s1,s2);
	if(nExpandStatus==0)
	{
		printf("resultant string is\n");
		printf("%s\n",s2 );
	}
	else
	{
		printf("cannot be expanded due to invalid string format\n");
	}
	// to stop console from closing
	system("pause");
	return 0;
}
