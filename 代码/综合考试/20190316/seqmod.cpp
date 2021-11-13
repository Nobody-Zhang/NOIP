#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void redi(T &t)
{
	register int k=getchar();t=0;
	while(!isdigit(k)) k=getchar();
	while(isdigit(k)) t=t*10+k-'0',k=getchar();
}
template <typename T,typename ...Args> inline void redi(T&t,Args&...args)
{
	redi(t);redi(args...);
}
#define mod 31
int seq[16],n,m;//1-15是一个循环 
void pre()
{
	seq[1]=1;
	for(int i=2;i<=15;i++)
		seq[i]=(seq[i-1]*10)%mod;
	return;
}
void in()
{
	redi(n,m);
	for(int i)
}
int main()
{
	pre();
	in();
}
