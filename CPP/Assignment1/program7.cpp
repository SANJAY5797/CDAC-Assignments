#include<bits/stdc++.h>
using namespace std;
class Matrix
{
	
	public:
		vector<vector<int> > arr;
		Matrix()
		{

		}
		Matrix(int xm,int xn)
		{
			cout<<"Enter the elements";
			for(int i=0;i<xm;i++)
			{
				vector<int> temp;
				for(int j=0;j<xn;j++)
				{
					int d;
					cin>>d;
					temp.push_back(d);
				}
				arr.push_back(temp);
			}
		}
		friend Matrix mulMatrix(const Matrix &a,const Matrix &b);
		void display()
		{
			for(int i=0;i<arr.size();i++)
			{
				for(int j=0;j<arr[i].size();j++)
					cout<<arr[i][j]<<" ";
				cout<<endl;
			}
		}
};
Matrix mulMatrix(const Matrix &a,const Matrix &b)
{
	Matrix ans;
	int m1=a.arr.size();
	int n1=a.arr[0].size();
	int m2=b.arr.size();
	int n2=b.arr[0].size();
	if(n1!=m2)
	{
		cout<<"multiplication not possible\n";
		exit(-1);
	}
	vector<vector<int> >res;
	for(int i=0;i<m1;i++)
	{
		vector<int> tmp;
		for(int j=0;j<n2;j++)
		{
			int temp=0;
			for(int k=0;k<m2;k++)
			{
				temp=temp+(a.arr[i][k]*b.arr[k][j]);
			}
			tmp.push_back(temp);
		}
		res.push_back(tmp);
	}
	ans.arr=res;
	return ans;
}
int main()
{
	int m,n;
	cout<<"enter the size of first matrix"<<endl;
	cin>>m>>n;
	Matrix a(m,n);
	cout<<"enter the size of second matrix"<<endl;
	cin>>m>>n;
	Matrix b(m,n);
	cout<<"displaying first matrix"<<endl;
	a.display();
	cout<<"displaying second matrix"<<endl;
	b.display();
	Matrix c=mulMatrix(a,b);//calling function to multiplay matrices
	cout<<"Resultant matrix is \n";
	c.display();
	// to stop console from closing
	system("pause");
	return 0;
}