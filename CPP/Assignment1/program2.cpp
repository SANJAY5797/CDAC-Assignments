#include<bits/stdc++.h>
using namespace std;
class Student// student class to store details about the student
{
	public://public section
		char *studentName;
		char grade;
		int marks[3];
};
class CollegeCourse
{
	//private section
	Student std;// object of class student as the data member
	public://public section
		void set_Data(const char *s,int m1,int m2,int m3)
		{
			// allocating separate block of memory
			int len=strlen(s);
			std.studentName=(char *)malloc(sizeof(char)*(len+1));
			strcpy(std.studentName,s);
			//std.grade=grade;
			std.marks[0]=m1;
			std.marks[1]=m2;
			std.marks[2]=m3;
		}	
		int calculateAverage()//calculating average of marks scored in 3 subjects
		{
			int ans=(std.marks[0]+std.marks[1]+std.marks[2])/3;
			return ans;
		}
		char computeGrade()//calculating grade based on the average computed
		{
			float avg=calculateAverage();
			if(avg>60)
			{
				return 'A';
			}
			else if(avg>50)
			{
				return 'B';
			}
			else if(avg>40)
			{
				return 'C';
			}
			else 
				return 'F';
		}
		void display()//displaying the student details
		{
			cout<<"Name of the student is ";
			printf("%s\n",std.studentName);
			char gr=computeGrade();
			std.grade=gr;
			cout<<"The marks in each subject are\n";
			for(int i=0;i<3;i++)
			{
				cout<<std.marks[i]<<" ";
			}
			if(gr=='A')
				printf("%s passed in first class\n",std.studentName);
			else if(gr=='B')
				printf("%s passed in second class\n",std.studentName);
			else if(gr=='C')
				printf("%s passed in third class\n",std.studentName);
			else
				printf("%s failed\n",std.studentName);
		}
};
int main()
{
	CollegeCourse cl1;//creating object
	cl1.set_Data("sanjay",31,32,33);
	cl1.display();
	// to stop console from closing 
	system("pause");
	return 0;
}