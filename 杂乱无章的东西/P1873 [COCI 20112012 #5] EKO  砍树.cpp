#include<bits/stdc++.h>
using namespace std;
#define maxx 1000001
long long m,len[maxx];//n棵树，需要m长度
int n;
bool judge(long long k)
{
	long long tmp=0;
	for(int i=1;i<=n;i++)
		if(len[i]>=k){
			tmp+=(len[i]-k);
		}
	if(tmp>=m) return true;
	return false;
}
long long search(long long lef,long long rig)
{
	if(lef==rig) return lef;
	long long tmp=(lef+rig)/2;
	if(!judge(tmp)) return search(lef,tmp);
	return search(tmp+1,rig);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>len[i];
	sort(len+1,len+n+1);
	cout<<search(1,len[n])-1<<endl;
	return 0;
}