#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
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
long long m,in,maxx;
bool judge()
{
	if(in==1) return false;
	for(long long i=2;i*i<=in;i++)
	 if(in%i==0) return false;
	return true;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	redi(m);
	for(int i=1;i<=m;i++)
	 {
	 	redi(in);
	 	if(judge()) printf("YES\n");
	 	else printf("NO\n");
	 }
	return 0;
	//for(int i=1;i<=)
}
