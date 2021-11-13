#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100005;

int n,m,p;
ll zuo,you,s1,s2,val[maxn];

ll ab(ll x)
{
	return x<0?-x:x;
}

int main()
{
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n; i++)
		scanf("%lld",&val[i]);
	scanf("%d%d%lld%lld",&m,&p,&s1,&s2);
	for(int i = 1;i < m; i++)
		zuo+=(m-i)*1ll*val[i];
	for(int i = m+1; i <= n; i++)
		you+=(i-m)*1ll*val[i];
	if(p<m)
		zuo+=s1*(m-p);
	else if(p>m)
		you+=s1*(p-m);
	ll cha = you-zuo;
	int q=0;
	for(int i = 1;i <= n; i++)
		if(!q || ab(cha+(q-m)*s2)>ab(cha+(i-m)*s2))
			q = i;
	printf("%d",q);
	return 0;
}
