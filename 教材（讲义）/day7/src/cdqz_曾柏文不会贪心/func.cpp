#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL gcd(LL a,LL b)
{
	LL r=a%b;
	if(r==0) return b;
	a=b;b=r;
	gcd(a,b); 
}
LL fm(LL x,LL k,LL Mod) 
{
	LL ans=0; 
	while(k) 
	{
		if(k%2)ans=(ans+x)%Mod; 
		x=(x+x)%Mod; 
		k=k/2;  
	}
	return ans; 
}
LL fp(LL x,LL k,LL Mod)
{
	LL ans=1; 
	while(k) 
	{
		if(k%2) ans=fm(ans,x,Mod); 
		x=fm(x,x,Mod); 
		k=k/2; 
	}
	return ans; 
}
int test[30]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
bool Miller_Rabin(LL x) 
{
	if(x<=47)
	{
		for(int i=0;i<=14;i++) if(x==test[i]) return true; 
		return false; 
	} 
	LL xx=x-1; 
	while(xx%2==0)xx=xx/2;  
	for(int i=0;i<=14;i++)
	{
		bool Millers_judge=false; 
		if (fp(test[i],xx,x)==1)Millers_judge=true;
		for(int k=1;k<=(x-1)/xx&&(!Millers_judge);k*=2)
		    if(fp(test[i],xx* k,x)==x-1)Millers_judge=true; 
		if(!Millers_judge)return false;   
	}
	return true ;  
}
int Detal,que[10005],cnt;  
LL Fx(LL x,LL Mod) 
{ 
	return (fm(x,x,Mod)+Detal)%Mod; 
}
void Pollard_Rho(LL x)
{
	LL p=1;Detal=15; 
	if(x==1) return;   
	if(Miller_Rabin(x)){que[++cnt]=x;return;}
	while(--Detal)
	{
		LL a=rand(); 
		a=fm(a,100000000000000007,x);	
		LL b=a;a=Fx(a,x);
		LL C=1,lp=2;  
		while(a!=b) 
		{
			C++; 
			LL d=a-b;if(d<0)d=-d;d=d%x;  
		    p=gcd(x,d); 
		    if(p!=1&&p!=x)break; 
			a=Fx(a,x); 
			if(C==lp){b=a;a=Fx(a,x);lp=lp<<1;}  
		}   
		if(p!=1&&p!=x)break;
	}
	Pollard_Rho(x/p); 
	Pollard_Rho(p) ; 
}
LL L,R,D,fin[100001];
int main()
{
	freopen("func.in","r",stdin);
	freopen("func.out","w",stdout);
	scanf("%I64d%I64d%I64d",&L,&R,&D);
	for(LL i=L;i<=R;i++)
	{
		Pollard_Rho(i);
		LL sum=0;
		for(LL j=1;j<=cnt;j++)
		sum+=que[j];
		fin[i]=fp(2048,3*sum,D);
	}
	LL ans=fin[L];
	for(LL i=L+1;i<=R;i++)
	ans=ans^fin[i];
	printf("%I64d",ans);
	return 0;
}
