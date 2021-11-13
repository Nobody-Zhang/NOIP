#include<bits/stdc++.h>
using namespace std;
string s1,s2;
unsigned long long pre[1000001],pows[1000001];
#define base 10007
unsigned long long hashs1(string s,int k)
{
	unsigned long long ans=0;
	for(int i=1;i<=k;i++)
	{
		ans=ans*base+s[i-1];
		pre[i]=ans;
	}
	return ans;
}
unsigned long long hashs2(string s,int k)
{
	unsigned long long ans=0;
	for(int i=0;i<k;i++)
	{
		ans=ans*base+s[i];
		//pre[i]=ans;
	}
	return ans;
}
int n;
unsigned long long getit(int l,int r)
{
	return pre[r]-pre[l-1]*pows[r-l+1];
}
int main()
{
	scanf("%d",&n);
	pows[0]=1;
	pows[1]=base;
	for(int i=2;i<1000001;i++) {pows[i]=pows[i-1]*base;}
	for(int i=1;i<=n;i++)
	{
		cin>>s2>>s1;
		hashs1(s1,s1.length());
		unsigned long long hash2=hashs2(s2,s2.length());
		int ans=0;
		//cout<<s1.length()<<endl<<s2.length()<<endl;
		for(int j=s2.length();j<=s1.length();j++)
		{
			int k=j-s2.length();
			if(getit(k,j)==hash2) ans++;
		}
		cout<<ans<<endl;
	}
}
