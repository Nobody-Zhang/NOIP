#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,a[11],top;
ll sum[10];
ll wan[10];

int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>n;
	int l=n/100000;
	for(int i=0;i<=99999;++i)//prework
	{
		int k=i,weishu=0;
		while(k)
		{
			wan[k%10]++;
			k/=10;
			weishu++;
		}
		wan[0]+=5-weishu;
	}
	for(int i=1;i<l;++i)//>100000
	{
		for(int j=0;j<=9;++j)
		{
			sum[j]+=wan[j];
		}
		int k=i;
		while(k)
		{
			sum[k%10]+=100000;
			k/=10;
		}
	}
	if(l)
	{
		for(int i=1;i<=99999;++i)
		{
			int k=i;
			while(k)
			{
				sum[k%10]++;
				k/=10;
			}
		}
	}
	for(int i=l*100000;i<=n;++i)//最后剩下的 
	{
		int k=i;
		while(k)
		{
			sum[k%10]++;
			k/=10;
		}
	}
	for(int i=0;i<=9;++i) cout<<sum[i]<<endl;
	return 0;
}

