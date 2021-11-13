#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int pre[35],aft[35],pp[35],pa[35],len;
int cnt;
void read()
{
	char a[35],b[35];
	scanf("%s%s",a,b);
	len=strlen(a);
	for(int i=0;i<len;++i)
	  {
	  	pre[i]=a[i]-'a';
	  	pp[pre[i]]=i;
	  	aft[i]=b[i]-'a';
	  	pa[aft[i]]=i;
	  }
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	read();
	for(int i=1;i<len;++i)
	  {
	  	int x=pre[i];
	  	int p=pa[pre[i]];
	  	if(aft[p+1]==pre[i-1])
	  	  cnt++;
	  }
	//cout<<cnt<<endl;
	long long ans=1LL<<cnt;
	cout<<ans<<endl;
}
