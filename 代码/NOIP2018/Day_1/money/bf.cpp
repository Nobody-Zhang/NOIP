#include<bits/stdc++.h>
using namespace std;
int as[25001],b[101];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.ans","w",stdout);
	int all;
	cin>>all;
	for(int k=1;k<=all;k++)
	{
		int tot=0;
		memset(as,0,sizeof(as));
		memset(b,0,sizeof(b));
		int a;
		cin>>a;
		for(int i=1;i<=a;i++)
		{
			int j;
			cin>>j;
			b[i]=j;
		}
		sort(b+1,b+1+a);
		for(int i=1;i<=a;i++)
		{
			if(as[b[i]]==0){
				as[b[i]]=1;
				int tmp=b[i];
				tot++;
				int tp=1;
				while(1)
				{
					tp++;
					if(tp*tmp>b[a]) break;
					as[tp*tmp]=1;
				}
				int st=1;
				while(1)
				{
					if(as[st]==1)
					{
						if(st+tmp>b[a]) break;
						as[st+tmp]=1;
					}
					st++;
				}
			}
		}
		cout<<tot<<endl;
	}
	return 0;
}
