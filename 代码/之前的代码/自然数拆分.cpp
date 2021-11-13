#include<bits/stdc++.h>
using namespace std;
long long c;
int as[100001]={1};
int max1,n;
int total;
void pr(int f)
{
	cout<<n<<"="<<as[1];
	for(int i=2;i<=f-1;i++)
	 cout<<"+"<<as[i];
	 cout<<"\n";
}
void dfs(int m,int left)//第m个，剩下有 left 
{
	if(left==0)//没有啦
	{
		total++;
		pr(m);
		return;
	}
	//max1=max(left,n-1);
	for(int i=as[m-1];i<=left;i++)
	if(i<n)
	{
		as[m]=i;
		left-=i;
		dfs(m+1,left);
		left+=i;
	}
}
int main()
{
	cin>>n;
	dfs(1,n);
	return 0;
}
