#include<bits/stdc++.h>
using namespace std;
int L,R,D;
int g(int x)
{
	if(x==1) return 1;
	int tt=0;
	for(int i=2;i*i<=x;++i)
	{
		if(x%i==0){
			tt+=i;
			while(x%i==0) x/=i;
		}
	}
	if(x==1) return tt;
	return tt+x;
}
int qpow(int a,int x)
{
	if(x==0)return 1;
	int ans=1;
	for(;x;x>>=1,a=a*1ll*a%D)if(x&1)ans=ans*1ll*a%D;
	return ans;
}
int f(int x)
{
	return qpow(2048,qpow(3,g(x)));
}
int main()
{
	freopen("func.in","r",stdin);
	freopen("func.out","w",stdout);
	scanf("%d%d%d",&L,&R,&D);
	int ans=f(L);
	for(int i=L+1;i<=R;++i)
	{
		ans^=f(i);
	}
	printf("%d\n",ans);
	return 0;
}
/*
1 100000 19
*/
/*
17
*/
