#include<bits/stdc++.h>
using namespace std;
#define maxx 100005
int mp[maxx][5],n,x,y;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	 {
	 	int a,b,c,d;
	 	scanf("%d%d%d%d",&a,&b,&c,&d);
	 	mp[++mp[0][0]][1]=a;
	 	mp[mp[0][0]][2]=b;
	 	mp[mp[0][0]][3]=a+c;
	 	mp[mp[0][0]][4]=b+d;
	 }
	scanf("%d%d",&x,&y);
	for(int i=mp[0][0];i>=1;i--)
	{
		if(mp[i][1]<=x&&mp[i][2]<=y&&mp[i][3]>=x&&mp[i][4]>=y)
		{
			printf("%d",i);
			return 0;
		}
	}
	printf("-1");
	return 0;
}
