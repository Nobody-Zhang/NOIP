#include<bits/stdc++.h>
using namespace std;
bool vis[100001]={1,1};
int pri[100001];
void prime(int maxx)
{
	for(int i=2;i<=maxx;i++)
	{
		if(vis[i]==false){
			pri[0]++;
			pri[pri[0]]=i;
		}
		for(int j=1;j<=pri[0]&&pri[j]*i<=maxx;j++)
		{
			vis[pri[j]*i]=true;
			if(i%pri[j]==0) break;
		}
	}
}
int main()
{
	int m;
	cin>>m;
	prime(100000);
	for(int i=1;i<=m;i++)
	{
		int k;
		cin>>k;
		if(vis[k]==0) cout<<k<<" ";
	}
	return 0;
}