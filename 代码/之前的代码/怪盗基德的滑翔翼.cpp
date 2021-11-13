#include<bits/stdc++.h>
using namespace std;
int in[10001][4],m,n,maxx;
int main()
{
	cin>>m;
	while(m)
	{
		memset(in,0,sizeof(in));
		cin>>n;
		maxx=0;
		for(int i=1;i<=n;i++)
		 cin>>in[i][1];
		in[1][2]=1;
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=i-1;j++)
			if(in[i][1]<in[j][1]&&in[i][2]<in[j][2])
			 in[i][2]=in[j][2];
			in[i][2]++;
		}
		for(int i=n;i>=1;i--)
		{
			for(int j=i+1;j<=n;j++)
			if(in[i][1]<in[j][1]&&in[i][3]<=in[j][3])
		 	 in[i][3]=in[j][3];
			in[i][3]++;
		}
		for(int i=1;i<=n;i++)
		 if(maxx<in[i][2]) maxx=in[i][2];
		for(int i=1;i<=n;i++)
		 if(maxx<in[i][3]) maxx=in[i][3];
		cout<<maxx<<endl;
		m--;
	}
	return 0;
}
