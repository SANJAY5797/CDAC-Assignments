#include<bits/stdc++.h>
using namespace std;
int main()
{
	stack<char> st;
	string str;
	cout<<"Enter the expression\n";
	cin>>str;
	bool flag=true;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]=='('||str[i]=='['||str[i]=='{')
		{
			st.push(str[i]);
		}
		else
		{
			if(str[i]==')')
			{
				if(st.empty()||st.top()!='(')
				{
					flag=false;
					break;
				}
				else 
				{
					st.pop();
				}
			}
			else if(str[i]==']')
			{
				if(st.empty()||st.top()!='[')
				{
					flag=false;
					break;
				}
				else 
				{
					st.pop();
				}
			}
			else if(str[i]=='}')
			{
				if(st.empty()||st.top()!='{')
				{
					flag=false;
					break;
				}
				else 
				{
					st.pop();
				}
			}
		}
	}
	if(!st.empty())
		flag=false;
	if(flag)
	{
		cout<<"balanced \n";
	}
	else
		cout<<"not balanced\n";
	// to stop console from closing
	system("pause");
	return 0;
}