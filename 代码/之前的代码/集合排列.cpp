#include<bits/stdc++.h>
using namespace std;
long long n,r;
long long as[100001];
long long used[100001];//已经用过的 
long long total;//总共多少种 
void pr()//打印
{
	for(int i=1;i<=r;i++)
	 {
	 	cout<<as[i]<<" ";
	 	total++;
	 }
	cout<<"\n";
} 
void dfs(int j)//j是第几个 
{
	if(j>r)
	 {
	 	pr();
	 	return ;
	 }
	for(int i=1;i<=n;i++)
	if(used[i]==0)
	{
		as[j]=i;
		used[i]=1;
		dfs(j+1);
		used[i]=0;
		
	}
}
int main()
{
	cout<<"请依次输入n和r";//n是多少个r是选多少个
	cin>>n>>r;
	dfs(1);
	return 0;
}
