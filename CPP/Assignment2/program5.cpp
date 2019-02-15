#include<bits/stdc++.h>
using namespace std;
class String
{
	//private section
	char *str;
	int len;
	public:
	//public section
		String()//default constructor
		{
			str=NULL;
			len=0;
		}
		String(char *s)// deep copy here
		{
			len=strlen(s);
			s=(char *)malloc(sizeof(char)*(len+1));
			strcpy(str,s);
		}
		String(const String &temp)// shallow copy goes here
		{
			str=temp.str;
			len=temp.len;
		}
		~String()//destructor
		{
		}
		//member functions declarations
		String operator+(String temp);
		char operator[](int index);
		friend ostream& operator<<(ostream &cout,String s);
		friend istream& operator>>(istream &cin,String &s);
		String operator=(String a);
};
//definitions of overloaded function
String String::operator+(String temp)
{
	String res;
	res.len=temp.len+len;
	res.str=(char *)malloc(sizeof(char)*(res.len+1));
	int i;
	for(i=0;i<len;i++)
		res.str[i]=str[i];
	for(int j=0;j<temp.len;j++)
		res.str[i]=temp.str[j];
	res.str[i]='\0';
	return res;
}
char String::operator[](int index)
{
	return this->str[index];
}
ostream& operator<<(ostream &cout,String s)
{
	cout<<s.str<<endl;
	return cout;
}
istream& operator>>(istream &cin,String &s)
{
	char temp[50];
	cin>>temp;
	s.str=(char *)malloc(sizeof(char)*(strlen(temp)+1));
	strcpy(s.str,temp);
	return cin;
}
String String::operator=(String a)
{
	str=(char *)malloc(sizeof(char)*(strlen(a.str)+1));
	strcpy(str,a.str);
	return *this;
}
int main()
{
	String a1,a2;
	cin>>a1;
	a2=a1;
	cout<<a1;
	cout<<a2;
	cout<<a2[2]<<endl;
	// to stop console from closing
	system("pause");
	return 0;
}
