#include<bits/stdc++.h>
using namespace std;
long long in[100001];
queue <long long> q[100001];
int main()
{
	int total=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>in[i];
	sort(in+1,in+1+n);
	total++;
	q[total].push(in[1]);
	int targ;
	for(int i=2;i<=n;i++)
	{
		bool flag=false;
		int siz=100000;
		for(int j=1;j<=total;j++)
		{
			if(in[i]==q[j].back()+1){
				int tmp=q[j].size();
				if(tmp>=siz) continue;
				siz=q[j].size();
				targ=j;
				flag=true;
			}
		}
		if(flag){
			q[targ].push(in[i]);
			continue;
		}
		total++;
		q[total].push(in[i]);
		
	}
	int ans=100001;
	for(int i=1;i<=total;i++)
	{
		int tmp=q[i].size();
		ans=min(ans,tmp);
	}
	cout<<ans<<endl;
	return 0;
}