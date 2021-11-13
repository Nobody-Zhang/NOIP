#include<bits/stdc++.h>
using namespace std;
int f(int m,int n)
{
	if(m==1||n==1||m==0) return 1;
	else if(m<n) return f(m,m);//剩余的盘子不要 
	else return f(m-n,n)+f(m,n-1); 
	/*f(m-n,n)是每个盘子各放一个的情况 
	f(m,n-1)是至少有一个盘子没有放的情况*/
}
int main()
{
	int k,h,g;
	cin>>k;
	for(int i=1;i<=k;i++)
	 {
	 	cin>>h>>g;
	 	cout<<f(h,g)<<"\n";
	 }
	 return 0;
}
