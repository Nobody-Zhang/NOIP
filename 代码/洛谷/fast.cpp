#include<bits/stdc++.h>
using namespace std;
char buf[1<<21],*p1=buf,*p2=buf;
#define ri register int
#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
using namespace std;
template <typename T>inline void redi(T& t)
{
	ri c=getchar();t=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))t=t*10+c-48,c=getchar();
}
template <typename T,typename... Args> inline void redi(T& t, Args&... args)
{
	redi(t);redi(args...);
}
