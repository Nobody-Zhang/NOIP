#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> void read(T&);

int n,m,cnt,a[11];

ll gcd(ll a,ll b){return b==0 ? a : gcd(b,a%b);}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}

int sign,flag,aim_deep;
void dfs(int dep,int pre,int mul)
{
	if(dep==aim_deep){
		cnt+=flag*(int)(m/mul);
		return;
	}
	for(int i=pre+1;i<=n;i++){
		ll tmp=lcm(mul,a[i]);
		if(tmp>m) continue;
		dfs(dep+1,i,tmp);
	}
}

int main()
{
	freopen("not.in","r",stdin);
	freopen("not.out","w",stdout);
	read(n);read(m);
	cnt=m;
	for(int i=1;i<=n;i++)
		read(a[i]);
	sort(a+1,a+n+1);
	for(sign=1;sign<=n;sign++){
		aim_deep=sign;
		flag=(sign&1) ? -1 : 1;
		dfs(0,0,1);
	}
	printf("%d\n",cnt);
	return 0;
}

template<class T> void read(T &re)
{
	re=0;
	T sign=1;
	char tmp;
	while((tmp=getchar())&&(tmp<'0'||tmp>'9')) if(tmp=='-') sign=-1;
	re=tmp-'0';
	while((tmp=getchar())&&(tmp>='0'&&tmp<='9')) re=re*10+(tmp-'0');
	re*=sign;
}