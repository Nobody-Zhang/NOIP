#include<bits/stdc++.h>
using namespace std;
#define N 1600000
bool not_zhishu[N];
int zhishu[N],m,hm[N];
void ola_xxs()
{
	for(int i=2;i<=m;i++)
	{
		if(not_zhishu[i]==false)
		{
			zhishu[++zhishu[0]]=i;
			hm[i]=i-1;
		}
		for(int j=1;j<=zhishu[0]&&zhishu[j]<=m/i;j++)
		{
			not_zhishu[i*zhishu[j]]=true;
			if(i%zhishu[j]==0)
			{
				hm[i*zhishu[j]]=hm[i]*zhishu[j];
				break;
			}
			else
			{
				hm[zhishu[j]*i]=hm[i]*hm[zhishu[j]];
			}
		}
	}
	return;
}
int main()
{
	cin>>m;
	ola_xxs();
	for(int i=1;i<=zhishu[0];i++)
	 cout<<zhishu[i]<<" ";
	 cout<<endl;
	for(int i=1;i<=m;i++)
	 cout<<hm[i]<<" ";
	return 0;
}
