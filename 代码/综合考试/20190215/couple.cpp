#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define maxx 100005
bool used[maxx];		
int in[maxx],n,m,a,b;
long long ans;
using namespace std;
template <typename T> inline void redi(T& t)
{
	register int c=getchar();t=0;
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) t=t*10+c-'0',c=getchar();
}
template <typename T,typename ...Args> inline void redi(T& t,Args&... args)
{
	redi(t);
	redi(args...);
}
int main()
{
	freopen("couple.in","r",stdin);
	freopen("couple.out","w",stdout);
	redi(n,m);
	register int j,i;
	for(i=1;i<=n;i++)
		redi(in[i]);
	for(i=1;i<=m;i++)
	{
		for(j=a;j<=b;j++) used[in[j]]=false;
		redi(a,b);
		ans=0;
		for(j=a;j<=b;j++)
		if(!used[in[j]]) {
			ans+=in[j];
			used[in[j]]=true;
		}else ans-=in[j];
		printf("%d\n",ans);
	}
	return 0;
}
