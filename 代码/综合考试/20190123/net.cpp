#pragma GCC optimize(2) 
#include<bits/stdc++.h>
using namespace std;
int a,b,n;
#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
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
}
#define maxx 100005
struct tr{
	int x,y,data;
}in[maxx];
struct tree{
	int deltalen;
	int x,y;
}len[maxx];
bool cmp(tr a,tr b){
	return a.x<b.x;
}
int inc,tot;
int used[maxx];
bool cp(tree a,tree b){
	return a.deltalen<b.deltalen;
}
bool cmp2(tr a,tr b){
	return a.y<b.y;
}
int find(int x)
{
	if(x==used[x]) return x;
	return used[x]=find(used[x]);
}
void unionn(int x,int y)
{
	int xx=find(x),yy=find(y);
	used[xx]=used[yy];
	return;
}
int main()
{
	freopen("net.in","r",stdin);
	freopen("net.out","w",stdout);
	redi(a,b,n);
	//scanf("%d%d%d",&a/*纵坐标*/,&b/*横坐标*/,&n);
	for(int i=1;i<=n;i++)
	 {
	 	redi(in[i].x,in[i].y);
	 	//scanf("%d%d",&in[i].x,&in[i].y);
	 	in[i].data=i;
	 }
	sort(in+1,in+n+1,cmp);
	for(int i=1;i<n;i++)
	 {
	 	inc++;
	 	len[inc].deltalen=abs(in[i].x-in[i+1].x);
	 	len[inc].x=in[i].data,len[inc].y=in[i+1].data;
	 }
	sort(in+1,in+n+1,cmp2);
	for(int i=1;i<n;i++)
	 {
	 	inc++;
	 	len[inc].deltalen=abs(in[i].y-in[i+1].y);
	 	len[inc].x=in[i].data,len[inc].y=in[i+1].data;
	 }
	for(int i=1;i<=n;i++)
	 used[i]=i;
	sort(len+1,len+1+inc,cp);
	/*for(int i=1;i<=inc;i++)
	 cout<<len[i].deltalen<<" "<<len[i].x<<" "<<len[i].y<<endl;*/
	 int num=0;
	for(int i=1;i<=inc;i++)
	 if(find(len[i].x)!=find(len[i].y))//不在同一个 
	  {
	  	if(num==n+1) break;
	  	num++;
	  	tot+=len[i].deltalen;
	  	unionn(len[i].x,len[i].y);
	  }
	cout<<tot;
	return 0;
}
