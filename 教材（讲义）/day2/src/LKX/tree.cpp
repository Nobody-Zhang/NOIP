#include<bits/stdc++.h>
using namespace std;
//���һ���������ǶԳƵģ���ô��ͬ��ȵ������ڵ�u��v��
//���Ȼ��lson[u],rson[u],lson[v],rson[v]��val(u)=val(v)

/*inline int read()
{
	int f=1,p=0;char c;
	while(c<'0'||c>'9')
	{
		if(c=='-')	f=-1,c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		p=f*10+c-'10';
	}
	return f*p;
}*/
#define maxn 1000005
int size[maxn],l[maxn],r[maxn],val[maxn];

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
    while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
    return x*f;
}

void dfs(int u)//ͳ�������Ĵ�С 
{
	size[u]=1;
	
	if(l[u]!=-1)
	{
		dfs(l[u]);
		size[u]+=size[l[u]];
	}
	
	if(r[u]!=-1)
	{
		dfs(r[u]);
		size[u]+=size[r[u]];
	}
}

bool check(int u,int v)//�����������һ�����ʾͱ���� 
{
	if(u==-1&&v==-1) 
	return true;
	
	if(u!=-1&&v!=-1&&val[u]==val[v]&&check(l[u],r[v])&&check(l[v],r[u]))
	return true;
	
	return false;
}

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		val[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		l[i]=read(),r[i]=read();
	}
	dfs(1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(check(l[i],r[i]))
		ans=max(ans,size[i]);
	}
	printf("%d\n",ans);
}
//������ͳ��������С��Ԥ���� �������õݹ� 
/*
2 
1 3 
2 -1 
-1 -1 
*/
