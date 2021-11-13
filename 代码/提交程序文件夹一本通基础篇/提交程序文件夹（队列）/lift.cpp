#include<bits/stdc++.h>
using namespace std;
#define MAXX 450052
int q[MAXX],vis[MAXX];
int be,en,n;
int main()
{
	//freopen("lift.in","r",stdin);
	//freopen("lift.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>be>>en;
	queue<int>p;
	for(int i=1;i<=n;i++)
	 cin>>q[i];
	vis[be]=1;
	p.push(be);
	while(!p.empty())
	{
		int now=p.front(),l=now-q[now],r=now+q[now];
		p.pop();
		if(l>=1&&!vis[l]) p.push(l),vis[l]=vis[now]+1;
		if(r<=n&&!vis[r]) p.push(r),vis[r]=vis[now]+1;
		if(l==en||r==en) break;
	}
	cout<<vis[en]-1<<endl;
	return 0;
}
