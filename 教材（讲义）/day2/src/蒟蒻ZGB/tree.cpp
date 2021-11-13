//#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define maxx 1000005
int tree1[maxx][3],tree2[maxx][3];
int fir1[maxx],fir2[maxx];
int f1[maxx],f2[maxx];
int mid1[maxx],mid2[maxx];
int m1[maxx],m2[maxx];
int size[maxx];
int n,root,ans,tmp;
template <typename T>inline void redi(T& t)
{
	register int c=getchar();t=0;
	bool flag=false;
	if(c=='-') flag=true;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))t=t*10+c-48,c=getchar();
	if(flag) t=-t;
}
template <typename T,typename... Args> inline void redi(T& t, Args&... args)
{
	redi(t);redi(args...);
}
void dfs1(int now)
{
	fir1[++fir1[0]]=now;
	f1[now]=fir1[0];
	if(tree1[now][1]!=-1) {
		dfs1(tree1[now][1]);
		size[now]+=size[tree1[now][1]];
	}
	mid1[++mid1[0]]=now;
	m1[now]=mid1[0];
	if(tree1[now][2]!=-1) {
		dfs1(tree1[now][2]);
		size[now]+=size[tree1[now][2]];
	}
	return;
}
void dfs2(int now)
{
	fir2[++fir2[0]]=now;
	f2[now]=fir2[0];
	if(tree2[now][1]!=-1) dfs2(tree2[now][1]);
	mid2[++mid2[0]]=now;
	m2[now]=mid2[0];
	if(tree2[now][2]!=-1) dfs2(tree2[now][2]);
	return;
}
void judge(int now)
{
	for(int i=f1[now];i<=f1[now]+size[now]-1;)
		for(int j=f2[now];j<=f2[now]+size[now]-1;)
			if(tree1[fir1[i]][0]!=tree2[fir2[j]][0]){
				return;
			}
			else i++,j++;
	for(int i=m1[now]-(size[now])/2;i<=m1[now]+(size[now])/2;)
		for(int j=m2[now]-(size[now])/2;j<=m2[now]+(size[now])/2;)
			if(tree1[mid1[i]][0]!=tree2[mid2[j]][0]){
				return;
			}
			else i++,j++;
	if(size[now]>tmp) tmp=size[now],ans=now;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	redi(n);//cin>>n;
	for(int i=1;i<=n;i++) size[i]=1;
	for(int i=1;i<=n;i++)
	{
		int k;
		redi(k);
		tree1[i][0]=tree2[i][0]=k;
	}
	for(int i=1;i<=n;i++)
	{
		int a,b;
		redi(a,b);
		//cin>>a>>b;
		tree1[i][1]=tree2[i][2]=a;
		tree2[i][1]=tree1[i][2]=b;
	}
	root=1;
	dfs1(root);
	dfs2(root);
	for(int i=1;i<=n;i++)
		judge(i);
	cout<<tmp<<endl;
	return 0;
}
