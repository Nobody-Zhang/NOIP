#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int as;
int a[100000];//怎么输出的数组 
int min1;
int n;
void dfs(int i,int last)//这里是第i次，剩余的数为last 
{
	int k;
	if(last==0)
	{
		as++;
		cout<<n<<"="<<a[1];
		for(int j=2;j<=i-1;j++)
		cout<<"+"<<a[j];
		cout<<"\n";
	}
	if(last<a[i-1]) min1=last;
	else min1=a[i-1];
	for(k=min1;k>=1;k--)
	{
		a[i]=k;
		dfs(i+1,last-k);
	}
}
int main()
{

	cin>>n;
	a[0]=n;	
	dfs(1,n);
	cout<<as;
	return 0;
}
