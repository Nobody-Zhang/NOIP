#include<bits/stdc++.h>
#define N 1000001
using namespace std;
int n,ans;
int l[N],r[N],val[N];//左右儿子 
int size[N];//子树大小 

template <class T>
void read(T &x)
{
	char c;int sign=1;
	while((c=getchar())>'9'||c<'0') if(c=='-') sign=-1; x=c-48;
	while((c=getchar())>='0'&&c<='9') x=(x<<1)+(x<<3)+c-48; x*=sign;
}

void init(int rt)
{
	size[rt]=1;
	if(l[rt]!=-1) init(l[rt]),size[rt]+=size[l[rt]];
	if(r[rt]!=-1) init(r[rt]),size[rt]+=size[r[rt]];
}
bool dfs(int ll,int rr)
{
	if(ll==-1&&rr==-1) return true;//没节点 
	if(ll==-1||rr==-1) return false;//有一边有
	//都有 
	if(val[ll]==val[rr]) return dfs(l[ll],r[rr])&&dfs(r[ll],l[rr]);
	return false;
}

int main()
{

	read(n);
	for(int i=1;i<=n;++i) read(val[i]);
	for(int i=1;i<=n;++i) read(l[i]),read(r[i]);
	init(1);
	for(int i=1;i<=n;++i)
	{
		if(dfs(l[i],r[i])) ans=max(ans,size[i]);
	}
	cout<<ans<<endl;
}
