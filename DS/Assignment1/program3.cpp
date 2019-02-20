#include<bits/stdc++.h>
using namespace std;
int priority(char ch)
{
	switch(ch)
	{
		case '*':
		case '%':
		case '/':return 2;
		case '-':
		case '+':return 1;
		default :return 0;
	}
	return -1;
}
int main()
{
	string str;
	cout<<"Enter the infix expression"<<endl;
	cin>>str;
	stack<char> st;
	for(int i=0;i<str.length();i++)
	{
		if(isalpha(str[i]))
			cout<<str[i];
		else
		{
			if(str[i]=='('||str[i]=='[')
			{
				st.push(str[i]);
			}
			else
			{
				if(str[i]==')')
				{
					while(st.top()!='(')
					{
						cout<<st.top();
						st.pop();
					}
					st.pop();
				}
				else if(str[i]==']')
				{
					while(st.top()!='[')
					{
						cout<<st.top();
						st.pop();
					}
					st.pop();
				}
				else if(st.empty())
				{
					st.push(str[i]);
				}
				else if(priority(str[i])>priority(st.top()))
				{
					st.push(str[i]);
				}
				else
				{
					int p=priority(str[i]);
					while(!st.empty()&&priority(st.top())>=p)
					{
						cout<<st.top();
						st.pop();
					}
					st.push(str[i]);
				}
			}
		}
	}
	while(!st.empty())
	{
		cout<<st.top();
		st.pop();
	}
	cout<<endl;
	// to stop console from closing
	system("pause");
	return 0;
}