#include<bits/stdc++.h>
using namespace std;
int xzhi[10005],fc[10005][5],shuchu=0;
int min1,p;
int jisuan(int a,int b,int c,int x)
{
	return (a*x*x+b*x+c);
}
int main()
{
	freopen("minval.in","r",stdin);
	freopen("minval.out","w",stdout);
	int n,m;
	 scanf("%d%d",&n,&m);
	for(int t=1;t<=n;t++)
	{
	 scanf("%d%d%d",&fc[t][1],&fc[t][2],&fc[t][3]);
     fc[t][4]=1;
	}
	while(shuchu<=m-2)
	{
		min1=2100000000;
		for(int t=1;t<=n;t++)
	 {
		xzhi[t]=jisuan(fc[t][1],fc[t][2],fc[t][3],fc[t][4]);
        if(xzhi[t]<min1)
        p=t,min1=xzhi[t];
	 }
	  fc[p][4]++;
	  printf("%d ",min1),shuchu++;
		
	}
	min1=2100000000;
		
		for(int t=1;t<=n;t++)
xzhi[t]=jisuan(fc[t][1],fc[t][2],fc[t][3],fc[t][4]),min1=min(min1,xzhi[t]);
	 
	  
	  printf("%d",min1);
	
	
}
