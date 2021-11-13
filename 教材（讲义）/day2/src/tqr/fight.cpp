#include<bits/stdc++.h>
#define N 100005
#define ll long long
#define fo(i,j,k) for(register int i=j;i<=k;i++)
using namespace std;

int n,m;
int c[N];
int p1,s1,s2;
ll sum1,sum2,cha,MIN=987654321;
int ans;

int main()
{
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
	scanf("%d",&n);
	fo(i,1,n) scanf("%d",&c[i]);
	scanf("%d%d%d%d",&m,&p1,&s1,&s2);
	c[p1]+=s1;
	fo(i,1,m-1) sum1+=(ll)c[i]*(ll)(m-i);
	fo(i,m+1,n) sum2+=(ll)c[i]*(ll)(i-m);

	fo(i,1,n)
	{
		if (i==m)
		{
			cha=abs(sum1-sum2);
			if (cha<MIN) {MIN=cha;ans=i;}
		}
		if (i<m)
		{
			sum1+=(ll)s2*(ll)(m-i);
			cha=abs(sum1-sum2);
			if (cha<MIN) {MIN=cha;ans=i;}
			sum1-=(ll)s2*(ll)(m-i);
		}
		if (i>m)
		{
			sum2+=(ll)s2*(ll)(i-m);
			cha=abs(sum1-sum2);
			if (cha<MIN) {MIN=cha;ans=i;}
			sum2-=(ll)s2*(ll)(i-m);
		}
	}
	printf("%d\n",ans);
	// cout<<sum1<<endl<<sum2;
	return 0;
}
/*
6
2 3 2 3 2 3
4 6 5 2

6
1 1 1 1 1 16
5 4 1 1
 */
