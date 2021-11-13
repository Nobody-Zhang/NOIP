#include<bits/stdc++.h>
using namespace std;
stack<int>v;
int m,in[800005],maxx[800005];
//int v[1000100],tail;
long long tot;
int main()
{
	//freopen("testdata.in","r",stdin);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	 //cin>>in[i];
	 scanf("%d",&in[i]);
	//in[0]=INT_MAX;
	//v.push(0);
	for(int i=1;i<=m;i++)
	{
		while(!v.empty())
		if(in[i]>=in[v.top()])
		{
			maxx[v.top()]=i;
			v.pop();
		}
		else break;
		v.push(i);
	}
	/*in[0]=INT_MAX;
	tail=0;
	for(int i=1;i<=m;i++)
	 {
	 	while(in[i]>=in[v[tail]])
	 	{
	 		maxx[v[tail]]=i;
	 		tail--;
	 	}
	 	if(in[i]<in[v[tail]]) v[++tail]=i;
	 }*/
	for(int j=1;j<=m;j++)
	 if(maxx[j])
	 	tot+=maxx[j]-j-1;
	 else tot+=m-j;
	cout<<tot<<endl;
	return 0;
}
