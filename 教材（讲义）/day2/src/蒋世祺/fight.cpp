#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
long long mi=999999999999999999;
int n,m,p1;
long long s[maxn],s1,s2;//s1,s2long long 
long long lon,hu;
int ans;

int main(){
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&s[i]);
	scanf("%d%d%lld%lld",&m,&p1,&s1,&s2);
	s[p1]+=s1;
	for(int i=1;i<m;i++)
	 lon+=(m-i)*s[i];
	for(int i=m+1;i<=n;i++)
	  hu+=(i-m)*s[i];
	long long delt=lon-hu; 
	if(!delt) ans=m;
	  else if(delt<0){
		for(int i=1;i<=m;i++)
		 if(abs(delt+s2*(m-i))<mi) mi=abs(delt+s2*(m-i)),ans=i;
	  }
	   else {
	   	for(int i=m;i<=n;i++)
	   	  if(abs(delt-s2*(i-m))<mi) mi=abs(delt-s2*(i-m)),ans=i;
	   }
	printf("%d",ans);
}
