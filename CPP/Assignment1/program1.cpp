#include<iostream>
using namespace std;
class Time
{
	/*private section*/
	int hours,minutes,seconds;
	public:// public section
		Time()//default constructor which initializes to 0
		{
			hours=minutes=seconds=0;
		}
		Time(int h,int m,int s) // parameterized constructor which initializes to given arguments
		{
			hours=h;
			minutes=m;
			seconds=s;
		}
		Time add(Time a)
		{
			int sec=a.seconds+seconds;
			int min=a.minutes+minutes;
			int h=a.hours+hours;
			//cout<<sec<<" "<<min<<" "<<h<<endl;
			if(sec>59)// checking if seconds exceed 59 and incrementing min if exceeds
			{
				min++;
				sec=sec-60;
			}
			if(min>59)// checking if minutes exceed 59 and incrementing hours if exceeds
			{
				h++;
				min=min-60;
			}
			if(h>23)// checking if hours exceed 23 and subtracting 24 from it if exceeds
			{
				h=h-24;
			}
			Time t;// creating a time object and storing the result
			t.hours=h;
			t.minutes=minutes;
			t.seconds=seconds;
			return t;// returning the time object
		}
		void print()// printing the time object in time format
		{
			cout<<"Addition of both the times is ";
			cout<<hours<<":"<<minutes<<":"<<seconds<<endl;
		}
};
int main()
{
	Time a(10,20,30);///initialization at the time of definition
	Time b(5,49,31);
	Time c=a.add(b);//invoking add member function
	c.print();
	//to stop console from closing
	system("pause");
}