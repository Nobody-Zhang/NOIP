#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll num[100003];
int main()
{
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
	int n,m;
	ll p1,s1,s2;
	ll sum1=0,sum2=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%I64d",&num[i]);
	scanf("%d%I64d%I64d%I64d",&m,&p1,&s1,&s2);
	for(int i=1;i<=m-1;i++)
	  sum1=sum1+num[i]*(m-i);
	for(int i=m+1;i<=n;i++)
	  sum2=sum2+num[i]*(i-m);
	if(p1>m) sum2+=s1*(p1-m);
	else if(p1<m) sum1+=s1*(m-p1);
	if(sum1==sum2){printf("%d",m); return 0;}
	ll delta=abs(sum1-sum2);
	int ee=m;
	for(int i=1;i<=n;i++)
	{
		if(i<m)
		{
			ll pp=abs(sum1+s2*(m-i)-sum2);
			if(pp<delta) ee=i,delta=pp;
		}
		if(i>m)
		{
			ll pp=abs(sum2+s2*(i-m)-sum1);
			if(pp<delta) ee=i,delta=pp;
		}
	}
	printf("%d",ee);
}
/*
6
2 3 2 3 2 3
4 6 5 2

6
1 1 1 1 1 16
5 4 1 1
*/
