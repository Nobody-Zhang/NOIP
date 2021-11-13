//#pragma optimize(2)
#include<bits/stdc++.h>
using namespace std;
int flag[100010],len[100010];
int l,n,k;//l表示公路的长度，n原有路标的数量，以及最多可增设的路标数量k
//注意是k-1个长度间距搜索
/*void search(int l,int r)
{
	if(l>=r)
	{
		cout<<l<<endl;
		exit(0);
	}
	int mid=(l+r)/2;
	int tot=0;
	for(int i=1;i<=n-1;i++)
	{
		tot+=(len[i]-1)/mid;
	}
	if(tot>k) search(mid+1,r);
	else search(l,mid);
}*/
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>l>>n>>k;
	cin>>flag[1];
	for(int i=2;i<=n;i++)
	{
		cin>>flag[i];
		len[i-1]=flag[i]-flag[i-1];
	}
	//search(1,l);
	int lef=1,rig=l;
	while(1)
	{
		int mid=(lef+rig)/2;
		if(lef>=rig)
		{
			cout<<lef<<endl;
			return 0;
		}
		int tot=0;
		for(int i=1;i<=n-1;i++)
		{
			tot+=(len[i]-1)/mid;
		}
		if(tot>k) lef=mid+1;
		else rig=mid;
	}
}