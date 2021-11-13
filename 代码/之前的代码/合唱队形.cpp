#include<bits/stdc++.h>
using namespace std;
int f[101][4],h[101],m,n;
int main()
{
	cin>>m;
	for(int i=1;i<=m;i++)
	 cin>>h[i];
	for(int i=1;i<=m;i++)
	{
		int maxx=0;
		for(int k=i-1;k>=0;k--)//ÉÏÉýÐòÁÐ 
		 if(h[i]>h[k])
		 maxx=max(maxx,f[k][1]);
		f[i][1]=maxx+1;
	}
	for(int i=m;i>=0;i--)
	 {
	 	int maxx=0;
	 	for(int k=i+1;k<=m;k++)
	 	 if(h[i]>h[k])
		  maxx=max(maxx,f[k][2]);
	 	f[i][2]=maxx+1;
	 }
	 int maxx=0;
	 for(int i=1;i<=m;i++)
	  maxx=max(maxx,f[i][1]+f[i][2]);
	cout<<m-maxx+1;
	return 0;
}
