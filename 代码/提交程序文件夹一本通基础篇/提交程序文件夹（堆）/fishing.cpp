#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define fish first
#define lake second
int n,f[101],d[101],t[101],Time,t1,as,m,maxx;
priority_queue< pair<int,int> >heap;
int main()
{
	freopen("fishing.in","r",stdin);
	freopen("fishing.out","w",stdout);
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>f[i];
	for(int i=1;i<=n;i++) cin>>d[i];
	for(int i=1;i<n;i++) cin>>t[i];
	cin>>m;
	for(int i=1;i<=n;i++)
	{
		Time=m-t1;
		as=0;
		for(int j=1;j<=i;j++)
		 heap.push(make_pair(f[j],j));
		while(Time>0&&heap.top().fish>0)
		{
			pair<int,int>a=heap.top();
			heap.pop();
			as+=a.fish;
			a.fish-=d[a.lake];
			heap.push(a);
			Time--;
		}
		if(as>maxx) maxx=as;
		t1+=t[i];
	}
	cout<<maxx<<endl;
	return 0;
}
/*
5
10 14 20 16 9
2 4 6 5 3
3 5 4 4
14
*/
