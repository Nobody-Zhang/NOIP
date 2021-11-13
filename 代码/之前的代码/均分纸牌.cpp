#include<bits/stdc++.h>
using namespace std;
int n,in[10001],j,s;
//n是有多少牌堆,in是每堆多少张,j是一共多少张 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	 cin>>in[i];
	 j+=in[i];
	}
	j/=n;//求平均 
	for(int i=1;i<=n;i++)
	 in[i]-=j;//每个数减去平均数 
	int i=1,k=n;
	while(in[i]==0&&i<n) i++;//将前面的0减去 
	while(in[k]==0&&k>1) k--;//将后面的0减去 
	while(i<k) 
	{
		in[i+1]+=in[i];//把第i个数据加到i+1中 
		in[i]=0;//上一个数达到平均数 
		s++;//总步数+1 
		i++;//下一个 
		while(in[i]==0&&i<k) i++;//清除过程中的0 
	}
	cout<<s<<endl;//输出总共的方案数 
	return 0;
}
