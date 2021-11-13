#include<bits/stdc++.h>
using namespace std;
string a[6],b;
int main()
{
	int q;
	for(q=1;q<=5;q++)
	getline(cin,a[q]);
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5-i;j++)
		if(a[j]>a[j+1])
		{
			b=a[j];
			a[j]=a[j+1];
			a[j+1]=b;
		}
		for(int i=1;i<=5;i++)
		cout<<a[i]<<"\n";
		return 0;
}
