#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
bool bs[1000]={false};
double s[1000][1000],c[1000];
int a[1000],b[1000],n,m,x,y,i,j,t1,t2,ms,k;
int main()
{
	cin>>n;
	for (i=1; i<=n; i++) cin>>a[i]>>b[i];
	cin>>m;
	for (i=1; i<=m; i++)
	{
		cin>>x>>y;
		s[x][y]=sqrt((a[x]-a[y])*(a[x]-a[y])+(b[x]-b[y])*(b[x]-b[y]));
        s[y][x]=s[x][y];
    }
	cin>>t1>>t2;
	for (i=1; i<=n; i++)
	for (j=1; j<=n; j++)
	    if(s[i][j]==0) s[i][j]=100001;
	
    for (i=1; i<=n; i++)
        c[i]=s[t1][i]; 
    for (i=1; i<=n-1; i++)
    {
		ms=1000001; k=0;
		for (j=1; j<=n; j++)
			if((bs[j]==false)&&(c[j]<ms))
		    {
				ms=c[j];
			    k=j;
		    }
		if(k==0) break;
		bs[k]=true;
		for (j=1; j<=n; j++)
		    if (c[k]+s[k][j]<c[j]) c[j]=c[k]+s[k][j];  
	}
	printf("%.2f",c[t2]);
}
