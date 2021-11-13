#include<bits/stdc++.h>
using namespace std;
bool flag;
long long lson[10000010],rson[10000010],value[10000010],ans;
int n;
long long read()
{
    int x=0,f=1;
    char ch;
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}
inline void write(long long x)
{
    if(x<0){putchar('-');x=-x;}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
long long cnt(long long x)//统计以x为根节点,子树的个数
{
	long long sum=0;
	if(lson[x]!=-1)
	{ 
		sum+=cnt(lson[x]);
	}
	if(rson[x]!=-1)
	{
		sum+=cnt(rson[x]);
	}
	return sum+1;
} 
void dfs(long long xx,long long yy)//左子树和右子树 
{
	if(xx==-1&&yy==-1)//完全到底了 
	{
		return;
	} 
	if(xx==-1||yy==-1||value[xx]!=value[yy])//非对称 
	{
		flag=false;
		return;
	} 
	dfs(lson[xx],rson[yy]);
	dfs(rson[xx],lson[yy]);
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		value[i]=read();
	}	
	for(int i=1;i<=n;i++)
	{
		lson[i]=read();rson[i]=read();
	}
	ans=1;//至少有一个节点是对称的
	for(int i=1;i<=n;i++)
	{
		if(lson[i]==-1||rson[i]==-1||value[lson[i]]!=value[rson[i]])
		{
			continue;
		}
		else
		{
			flag=true;
			dfs(lson[i],rson[i]);	
			if(flag==true)
			{
				long long num=cnt(i);
				ans=max(ans,num);
			}
		}
	} 
	write(ans);
	return 0;
}
