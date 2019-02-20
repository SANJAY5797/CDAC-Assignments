#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	cout<<"enter the postfix expression"<<endl;
	cin>>str;
	int ans=0;
	stack<int> st;
	for(int i=0;i<str.length();)
	{
		if(isdigit(str[i]))
		{
			int temp=0;
			while(str[i]!='@')
			{
				temp=temp*10+(str[i]-'0');
				i++;
			}
			i++;
			st.push(temp);
		}
		else
		{
			int one=-999;
			if(!st.empty())
			{
				one=st.top();
				st.pop();
			}
			int two=-999;
			if(!st.empty())
			{
				two=st.top();
				st.pop();
			}
			if(one!=-999&&two!=-999)
			{
				int res;
				if(str[i]=='*')
				{
					res=two*one;
				}	
				else if(str[i]=='+')
				{
					res=two+one;
				}
				else if(str[i]=='-')
				{
					res=two-one;
				}
				else if(str[i]=='/')
				{
					res=two/one;
				}
				else if(str[i]=='%')
				{
					res=two%one;
				}
				st.push(res);
			}
			i++;
		}
	}
	cout<<st.top()<<endl;
	// to stop console from closing
	system("pause");
	return 0;
}