#include<bits/stdc++.h>
using namespace std;
#define maxn 50005
#define maxk 100005
int fri[maxn],n,m,tot,eat[maxn];
int find1(int x)
{//找到同类 
	if(x==fri[x]) return x;
	return fri[x]=find1(fri[x]);
}
int find2(int x)
{//找到可以吃的 
	if(x==eat[x]) return x;
	return eat[x]=find2(eat[x]);
}
void unionn1(int x,int y)
{//连接同类 
	fri[x]=find1(y);
}
void unionn2(int x,int y)
{//连接吃的 
	eat[x]=find2(y);
}
bool judge1(int x,int y)
{//找到是不是在同一食物链上面 
	return (find2(x)==find2(y));
}
bool judge2(int x,int y)
{
	return (find1(x)==find1(y));
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		fri[i]=i,eat[i]=i;
	while(m--)
	{
		int kd,x,y;
		scanf("%d%d%d",&kd,&x,&y);
		if(x>n||y>n)	{
			++tot;continue;
		}
		if(x==y)	{
			
			if(kd==2){
				++tot;continue;
			}
			continue;
		}
		if(kd==1)
		{
			if(judge1(x,y)) {
				++tot;continue;
			}
			unionn1(x,y);
		}
		if(kd==2)
		{
			if(judge2(x,y)) {
				++tot;continue;
			}
			unionn2(x,y);
		}
	}
	printf("%d\n",tot);
	return 0;
}/*
100 7
1 101 1
2 1 2
2 2 3
2 3 3
1 1 3
2 3 1
1 5 5

*/
