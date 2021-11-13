#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll c[100005];

/*void read(int &x)
{
    int f=1;x=0;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    x*=f;
}*/
ll r1,r2;
int m,p1;
ll s1,s2;

int main()
{
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%I64d",&c[i]);
	
	scanf("%d%d%I64d%I64d",&m,&p1,&s1,&s2);
	
	for(int i=1;i<=m-1;i++)
	{
		r1+=c[i]*(m-i);
	}
	
	for(int i=m+1;i<=n;i++)
	{
		r2+=c[i]*(i-m);
	}
	
	if(p1>m) r2+=(p1-m)*s1;
	if(p1<m) r1+=(m-p1)*s1;
	
	if(r1==r2) 
	{
		printf("%d\n",m);
		return 0;	
	}
	
	int p2=m;
	ll delta=abs(r1-r2);
	
	for(int i=1;i<=n;i++)
	{
		if(i<m)//找最优解：不断更新最优解且更新答案 
		{
			ll min1=abs(r1+s2*(m-i)-r2); 
			if(min1<delta) p2=i,delta=min1;
		}
		
		if(i>m)
		{
			ll min1=abs(r2+s2*(i-m)-r1);
			if(min1<delta) p2=i,delta=min1;
		}
		
	}
	
	printf("%d\n",p2);
}
/*
6 
1 1 1 1 1 16
5 4 1 1
*/
