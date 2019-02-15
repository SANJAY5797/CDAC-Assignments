#include<iostream>
using namespace std;
class student
{
	public://public section
	string name;
	int rollno,marks[3],total;
	char grade;
	//member functions declarations
	friend istream& operator>>(istream &cin,student &x);
	friend void generate_results(student x[1]);
	friend ostream& operator<<(ostream &cout,student x);
	
};
istream& operator>>(istream &cin,student &x)//overloading cin
{
	cin>>x.name>>x.rollno>>x.marks[0]>>x.marks[1]>>x.marks[2];
	return cin;
}
ostream& operator<<(ostream &cout,student x)//overloading cout
{
	cout<<"name of the student is "<<x.name<<endl;
	cout<<"rollno of the student is "<<x.rollno<<endl;
	cout<<"marks of the student are "<<endl;
	for(int i=0;i<3;i++)
		cout<<x.marks[i]<<" ";
	cout<<endl;
		cout<<x.total<<endl;
	cout<<"grade of the student is "<<x.grade<<endl;
}
void generate_results(student x[3])//function to accept an array of student objects
{
	for(int i=0;i<3;i++)
	{
		x[i].total=x[i].marks[0]+x[i].marks[1]+x[i].marks[2];
		int avg=x[i].total/3;
		if(avg>=90)
		{
			x[i].grade='A';
		}
		else if(avg>=80)
		{
			x[i].grade='B';
		}
		else if(avg>=70)
		{
			x[i].grade='C';
		}
		else if(avg>=60)
		{
			x[i].grade='D';
		}
		else if(avg>=50)
		{
			x[i].grade='E';
		}
		else
		{
			x[i].grade='F';
		}
	}
}
int main()
{
	student x[3];//creating an array containing on student object
	cin>>x[0]>>x[1]>>x[3];//reading through overloaded cin
	generate_results(x);
	//outputing through overloaded cout
	cout<<x[0]<<endl;
	cout<<x[1]<<endl;
	cout<<x[2]<<endl;
	// to stop console from closing
	system("pause");
	return 0;
}