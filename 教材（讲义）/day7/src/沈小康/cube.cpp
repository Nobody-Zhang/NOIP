#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n;
double a[N];
double ans;

template <class T>
void read(T &x)
{
	char c;int sign=1;
	while((c=getchar())>'9'||c<'0') if(c=='-') sign=-1; x=c-48;
	while((c=getchar())>='0'&&c<='9') x=(x<<1)+(x<<3)+c-48; x*=sign;
}

void dfs(int now,double len,double p,double k)
{
	if(now>n)
	{
		if(len) k+=pow(len,3);
		ans+=p*k;
		return;
	}
	dfs(now+1,len+1,p*a[now],k);
	dfs(now+1,0,p*(1-a[now]),k+pow(len,3));
}

int main()
{
	freopen("cube.in","r",stdin);
	freopen("cube.out","w",stdout);
	read(n);
	for(int i=1;i<=n;++i) scanf("%lf",a+i);
	dfs(1,0,1.0,0);
	printf("%0.1f\n",ans);
	return 0;
}
