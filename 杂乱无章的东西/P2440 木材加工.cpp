#include<bits/stdc++.h>
using namespace std;
//木材厂有 nn 根原木，现在想把这些木头切割成 kk 段长度均为 ll 的小段木头
int n,k,l,len[100010],len_tot;
int main()
{
	//cin.tie(0);
	//ios::sync_with_stdio(false);
	bool flag=true;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>len[i];
		len_tot+=len[i];
		if(len_tot>k&&flag) flag=false;
	}
	if(len_tot==k){
		cout<<1<<endl;
		return 0;
	}
	if(flag)
	{
		cout<<0<<endl;
		return 0;
	}
	sort(len+1,len+n+1);
	int rig=len[n],lef=1;
	while(1)
	{
		int mid=(rig+lef)/2;
		if(lef==mid){
			cout<<lef<<endl;
			return 0;
		}
		int tot=0;
		for(int i=1;i<=n;i++)
		{
			tot+=(len[i]/mid);
		}
		//cout<<mid<<endl;
		//printf("%d\n",mid);
		if(tot>=k) lef=mid;
		else rig=mid-1;
	}
}