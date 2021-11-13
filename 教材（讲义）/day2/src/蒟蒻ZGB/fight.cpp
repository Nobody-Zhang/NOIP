#include<bits/stdc++.h>
using namespace std;
const int MaxN=1e5+5;
long long n,m,p1,s1,s2;
long long mapp[MaxN];
int main()
{
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
	cin>>n;
	for(register int i=1;i<=n;i++)
		cin>>mapp[i];
	cin>>m>>p1>>s1>>s2;
	mapp[p1]+=s1;
	long long sum1=0,sum2=0;
	for(register int i=1;i<m;i++)sum1+=mapp[i]*(m-i);
	for(register int i=m+1;i<=n;i++) sum2+=mapp[i]*(i-m);
	long long minn=1LL<<60;
	int p2=1;
	for(register int i=1;i<m;i++)
		if(abs(sum1+(s2*(m-i))-sum2)<minn)
			minn=abs(sum1+(s2*(m-i))-sum2),p2=i;
	if(abs(sum1-sum2)<minn) minn=abs(sum1-sum2),p2=m;
	for(register int i=m+1;i<=n;i++)
	if(abs(sum2+(s2*(i-m))-sum1)<minn) minn=abs(sum2+(s2*(i-m))-sum1),p2=i;
	cout<<p2<<endl;
	return 0;
}
