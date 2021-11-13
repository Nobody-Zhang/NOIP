#include<bits/stdc++.h>
using namespace std;
int n1,n2,len,tot;
int num[100010];
int can[100010];
int need[100010];
int mod[20]={0,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int ljb;
bool flag;
struct sb
{
	int len;
	int need;
}book[100010];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n1,&n2);
	for(int i=1;i<=n1;i++)
	{
		scanf("%d",&num[i]);
	}
	sort(num+1,num+1+n1);
	for(int i=1;i<=n2;i++)
	{
		scanf("%d%d",&book[i].len,&book[i].need);
	}
	for(int j=1;j<=n2;j++)
	{
		flag=false;
		for(int i=1;i<=n1;i++)
		{
			if((num[i]%mod[book[j].len])==book[j].need)
			{
				can[1]=num[i];
				flag=true;
				break;
			}
			can[1]=0;
		}
		if(flag)
		{
			printf("%d\n",can[1]);
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
}
/*
5 5
2123
1123
23
24
24
2 23
3 123
3 124
2 12
2 12
*/
