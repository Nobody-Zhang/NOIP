#include<bits/stdc++.h>
using namespace std;
#define N 100010
int m,n,ans[N],in[N];
deque<int>q;
int main()
{
	scanf("%d%d",&m,&n);//先输入多少个数
	//后面输入往后面的多少个 
	for(int i=1;i<=m;i++)
	 scanf("%d",&in[i]);
	for(int i=m+1;i<=n+m+1;i++)
	 in[i]=INT_MAX;
	for(int i=1;i<=m;i++)
	{
		while(!q.empty())
		 {
		 	if(i-q.front()<=n) break;
		 	q.pop_front();
		 }
		if(!q.empty())
		 if(q.front()>=n)
		  ans[q.front()-n+1]=min(in[i],in[q.front()]);
		while(!q.empty())
		{
			if(in[q.back()]>in[i]) break;
			q.pop_back();
		}
		q.push_back(i);
	}
	for(int i=1;i<=m;i++)
	 cout<<ans[i]<<" ";
	return 0;
} 
