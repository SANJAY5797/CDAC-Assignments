#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
#include<string.h>
/* function declarations*/
void count(); 
void removeComments();
void findMatchingAndReplace();
void replaceTabs();
int main(int argc,char *argv[])
{
	while(1)
	{
		//menu goes here
		printf("\n\nEnter any choice\n");
		printf("1.Count number of alphabets,digits and special characters from file\n");
		printf("2.Remove all comments from text file\n");
		printf("3.Find a matching word in the file and reverse it and replace it in the file\n");
		printf("4.Replace all the tabs present in the file with '\\t'\n");
		printf("5.Exit the application\n");
		int choice;
		scanf("%d",&choice);/// user input
		switch(choice)
		{
			// calling appropriate functions based on the user input given
			case 1: count();
					break;
			case 2:	removeComments();
					break;
			case 3: findMatchingAndReplace();
					break;
			case 4:	replaceTabs();
					break;
			case 5: exit(0);
			default:printf("Please enter a correct choice\n");
		}
	}
	return 0;
}