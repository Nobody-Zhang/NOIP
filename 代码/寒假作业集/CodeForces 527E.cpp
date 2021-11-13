#pragma GCC optimize(2)
#include<bits/stdc++.h> 
using namespace std;
#define maxm 500100
#define maxn 500100 
/*#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
template <typename T> inline void redi(T& t)
{
	register int c=getchar();t=0;
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) t=t*10+c-'0',c=getchar();
}
template <typename T,typename... Args>inline void redi(T& t,Args&... args)
{
	redi(t);
	redi(args...);
}*/
long long n,deg[maxn],m,head[maxn],inc,ans[maxn];
bool used[maxn];//保存是奇数还是偶数 偶数是false，奇数是true 
struct s{
	int data,last,from;
}edge[maxn];
void add(int a,int b)
{
	inc++;
	edge[inc].data=b;
	edge[inc].last=head[a];
	head[a]=inc;
	edge[inc].from=a;
	return;
}
/*void fx(int a)
{
	if(deg[a]==false) deg[a]=true;
	else deg[a]=false;
	return;
}*/
void ola(int x)
{
	for(int i=head[x];i;i=edge[i].last)
	if(used[(i+1)/2]==false)
	{
		used[(i+1)/2]=true;
		//cout<<i<<endl;
		ola(edge[i].data);
		ans[++ans[0]]=i;
	}
	return;
}
/*
void ola(int u)

{

    for (int &i = head[u]; i; i = edge[i].last)

    {
        if (used[(i+1) / 2]) continue;
        used[(i+1) / 2] = 1;
        int v = edge[i].data;
        int tmp = i;
        ola(v);
		ans[++ans[0]]=tmp;

    }

}*/
int main()
{
	//freopen("CF 527E.in","r",stdin);
	memset(ans,0,sizeof(ans));
	//redi(n,m);
	scanf("%d%d",&n,&m);
	//for(int i=1;i<=n;i++) fa[i]=i;//并查集处理每个连通块 
	for(int i=1;i<=m;i++)
	{
		int a,b;
		//redi(a,b);
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
		//fx(a);fx(b);//find(a)]=find(b);
		deg[a]++,deg[b]++; 
	}
	bool flag=false;
	int tmp=-1;
	for(int i=1;i<=n;i++)
	if(deg[i]&1){
		if(tmp==-1) tmp=i;
		else{
			add(i,tmp);
			add(tmp,i);
			tmp=-1;
		}
		/*if(flag==false){//表示当前无待连接的边 
			tmp=i;
			flag=true;
			continue;
		}
		if(flag==true){//表示当前有待连接的边 
			add(tmp,i);
			add(i,tmp);
			flag=false;
			continue;
		}*/
		
	}
	//if(flag==true) add(tmp,tmp);
	if((inc/2)&1) add(n,n);
	/*for(int i=1;i<=n;i++)
	if(run[fa[i]]==false) ola(fa[i]);*/
	ola(1);
	printf("%d\n",ans[0]);
	for(int i=1;i<=ans[0];i++)
	{
		if(i&1){
			printf("%d %d\n",edge[ans[i]].from,edge[ans[i]].data);
		}
		else{
			printf("%d %d\n",edge[ans[i]].data,edge[ans[i]].from);
		}
	}
	/*while(!q.empty())
	{
		if(flag==false){
			printf("%d %d\n",edge[q.front()].from,edge[q.front()].data);
			//cout<<edge[q.front()].from<<" "<<edge[q.front()].data<<endl;
			flag=true;
		}
		else{
			printf("%d %d\n",edge[q.front()].data,edge[q.front()].from);
			//cout<<edge[q.front()].data<<" "<<edge[q.front()].from<<endl;
			flag=false;
		}
		q.pop();
	}*/
	return 0;
} 
