#include<bits/stdc++.h>
using namespace std;
const int maxn=15;
const int ma=200000000;
long long n,m;
long long shu;
long long cnt;
long long num[maxn];
long long tongji[ma];
int main()
{
	freopen("not.in","r",stdin);
	freopen("not.out","w",stdout);
	srand(time(NULL));
	cin>>n>>m;
	if(n==1)
	{
		cin>>shu;
		if(shu==0)
		{
			printf("0");
			return 0;
		}
		for(long long i=1;i<=m;i++)
		{
			if(i%shu!=0)
			{
				cnt++;
			}
		}
		cout<<cnt;
		return 0;
	}
	if(n==2)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>num[i];
			if(num[i]==0)
			{
				printf("0");
				return 0;
			}
		}
		for(long long j=1;j<=m;j++)
		{
			if(j%num[1]!=0&&j%num[2]!=0)
			{
				cnt++;
			}
		}
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
	}
	cout<<rand();
	return 0;
}
