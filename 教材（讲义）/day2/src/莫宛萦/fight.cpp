#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N 100005
ll a[N],p1,s1,s2;
int n,m;
int main()
{
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	 scanf("%I64d",&a[i]);
	scanf("%d%I64d%I64d%I64d",&m,&p1,&s1,&s2);
	ll tot_left=0,tot_right=0;
	for(int i=1;i<=n;i++)
	{
		int delt=abs(m-i);
		if(i<m)
		tot_left+=delt*a[i];
		else if(i>m)
		tot_right+=delt*a[i];
	}
	
	if(p1<m) tot_left+=(m-p1)*s1;
	else if(p1>m) tot_right+=(p1-m)*s1;
	//cout<<tot_left<<" "<<tot_right;
	ll d=abs(tot_left-tot_right);
	//cout<<d;
	if(tot_left==tot_right)
	{
		printf("%d\n",m);
		return 0;
	}
	else if(tot_left<tot_right)
	{
		int ans=-1;
		ll minn=d;
		for(int i=m-1;i>=1;i--)
		//一定要有= 因为要找到最小的编号 
		 if(abs((m-i)*s2+tot_left-tot_right)<=minn)
		 {
			minn=abs((m-i)*s2+tot_left-tot_right);
			ans=i;
		 }
		if(ans==-1) printf("%d",m);
		else printf("%d\n",ans);	
	}
	else
	{
		int ans=-1;
		ll minn=d;
		for(int i=n;i>=m+1;i--)
		 if(abs((i-m)*s2-tot_left+tot_right)<=minn)
		 {
			minn=abs((i-m)*s2-tot_left+tot_right);
			ans=i;
		 }
		if(ans==-1) printf("%d",m);
		else printf("%d\n",ans);
	}
}
/*
6
2 3 2 3 2 3 
4 6 5 2
ans 2
6
2 3 2 3 2 3 
4 6 2 2
ans 5
6
1 1 1 1 1 16
5 4 1 1
ans 1

*/
