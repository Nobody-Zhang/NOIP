#include<bits/stdc++.h>
using namespace std;
#define mod 19260817
int inv[mod+10002],m,n;
int len1,len2;
char s1[10003],s2[10003];
int main()
{
	//freopen("t1.in","r",stdin);
	scanf("%s",&s1);
	len1=strlen(s1)-1;
	scanf("%s",&s2);
	len2=strlen(s2)-1;
	for(int i=0;i<=len1;i++)
		m=(m*10+s1[i]-'0')%mod;
	for(int i=0;i<=len2;i++)
		n=(n*10+s2[i]-'0')%mod;
	if(n==0)
	{
		printf("Angry!");
		return 0;
	}
	inv[1]=1;
	for(int i=2;i<=n;i++)
		inv[i]=(((-mod/i+mod)%mod)*inv[mod%i]+mod*20)%mod;
	long long ans=m;
	ans*=inv[n];
	ans%=mod;
	printf("%lld",ans);
	return 0;
}
