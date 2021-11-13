#include<bits/stdc++.h>
using namespace std;
int m;
struct t{
	int last,data;
	bool used;
}edge[10010];
int inc,head[10010],num[10010],from;
bool fr;
stack<int>s;
void add(int a,int b)
{
	inc++;
	edge[inc].last=head[a];
	edge[inc].data=b;
	head[a]=inc;
	return;
}
void dfs(int x)
{
	for(int i=head[x];i;i=edge[i].last)

	{
		int now=edge[i].last;
		dfs(now);
		break;
	}

}
int main()
{
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	 {
	 	int a,b;
	 	scanf("%d%d",&a,&b);
	 	add(a,b);
	 	add(b,a);
	 	num[a]++;
	 	num[b]++;
	 	num[0]=max(num[0],a);
	 	num[0]=max(num[0],b);
	 }
	for(int i=1;i<=num[0];i++)
	 if(num[i]%2==1){
	 	from=i;
	 	break;
	 }
	 dfs(from);
}
