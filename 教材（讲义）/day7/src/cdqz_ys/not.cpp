#include<bits/stdc++.h>
using namespace std;
int a[15],one[15],flagg[1000002];
int gcd(int a,int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}
int main()
{
	freopen("not.in","r",stdin);
	freopen("not.out","w",stdout);
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	if(m<=1000000)
	{
		for(int i=1;i<=n;i++)
	      scanf("%d",&a[i]); 
	   for(int j=1;j<=n;j++)
    	for(int i=m;i>=1;i--)
    	  {
    	//	if(i<a[j]) break;
    		if(i%a[j]==0&&!flagg[i]) ans++,flagg[i]=1;
    	  }
    	printf("%d",m-ans);
    	return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int u;
		scanf("%d",&a[i]); 
		one[i]=m/a[i];
		ans+=one[i];
	}
	if(n==1) 
	{
		printf("%d\n",m-ans);
		return 0;
	}
	else if(n==2)
	{
 	    int u=gcd(a[1],a[2]);
 	    int v=m/u;
 	    ans-=v;
 	    printf("%d",m-ans);
 	    return 0;
	}
	else if(n==3)
	{
		int u1=gcd(a[1],a[2]);
		int u2=gcd(a[1],a[3]);
		int u3=gcd(a[3],a[2]);
		int u4=gcd(a[2],gcd(a[1],a[3]));
		int v1=m/u1;
		int v2=m/u2;
		int v3=m/u3;
		int v4=m/u4;
		ans=ans-v1-v2-v3+v4;
		printf("%d",m-ans);
		return 0;
	}
	else if(n==4)
	{
		int u1=gcd(a[1],a[2]);
		int u2=gcd(a[1],a[3]);
		int u3=gcd(a[3],a[2]);
		int u4=gcd(a[1],a[4]);
		int u5=gcd(a[2],a[4]);
		int u6=gcd(a[3],a[4]);
		
		int u7=gcd(a[2],gcd(a[1],a[3]));
		int u8=gcd(a[4],gcd(a[1],a[2]));
		int u9=gcd(a[4],gcd(a[1],a[3]));
		int u10=gcd(a[2],gcd(a[4],a[3]));
		
		int u11=gcd(a[4],gcd(a[3],gcd(a[1],a[2])));
		int v1=m/u1;int v2=m/u2;int v3=m/u3;int v4=m/u4;
		int v5=m/u5;int v6=m/u6;int v7=m/u7;int v8=m/u8;
		int v9=m/u9;int v10=m/u10;int v11=m/u11;
		ans=ans-v1-v2-v3-v4-v5-v6+v7+v8+v9+v10-v11;
		printf("%d",m-ans);
		return 0;
		
	}
	else if(n==5)
	{
		int u1=gcd(a[1],a[2]);int u2=gcd(a[1],a[3]);
		int u3=gcd(a[3],a[2]);int u4=gcd(a[1],a[4]);
		int u5=gcd(a[2],a[4]);int u6=gcd(a[3],a[4]);
		int u7=gcd(a[1],a[5]);int u8=gcd(a[2],a[5]);
		int u9=gcd(a[3],a[5]);int u10=gcd(a[5],a[4]);
		
		int u11=gcd(a[2],gcd(a[1],a[3]));
		int u12=gcd(a[4],gcd(a[1],a[2]));
		int u13=gcd(a[4],gcd(a[1],a[3]));
		int u14=gcd(a[2],gcd(a[4],a[3]));
		int u15=gcd(a[2],gcd(a[1],a[5]));
		int u16=gcd(a[5],gcd(a[1],a[3]));
		int u17=gcd(a[4],gcd(a[1],a[5]));
		int u19=gcd(a[2],gcd(a[5],a[3]));
		int u20=gcd(a[4],gcd(a[5],a[2]));
     	int u18=gcd(a[4],gcd(a[5],a[3]));
		
		int u21=gcd(a[4],gcd(a[3],gcd(a[1],a[2])));
		int u22=gcd(a[5],gcd(a[3],gcd(a[1],a[2])));
		int u23=gcd(a[4],gcd(a[3],gcd(a[1],a[5])));
		int u24=gcd(a[4],gcd(a[3],gcd(a[5],a[2])));
		
		int u25=gcd(a[1],gcd(a[4],gcd(a[3],gcd(a[5],a[2]))));
		int v1=m/u1;int v2=m/u2;int v3=m/u3;int v4=m/u4;
		int v5=m/u5;int v6=m/u6;int v7=m/u7;int v8=m/u8;
		int v9=m/u9;int v10=m/u10;int v11=m/u11;int v12=m/u12;
		int v13=m/u13;int v14=m/u14;int v15=m/u15;int v16=m/u16;
		int v17=m/u17;int v18=m/u18;int v19=m/u19;int v20=m/u20;
		int v21=m/u21;int v22=m/u22;int v23=m/u23;int v24=m/u24;
		int v25=m/u25;
		ans=ans-v1-v2-v3-v4-v5-v6-v7-v8-v9-v10+v11+v12+v13+v14+v15+v16+v17
		+v18+v19+v20-v21-v22-v23-v24+v25;
		printf("%d",m-ans);
		return 0;
	}
	
}
