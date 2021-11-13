#include<bits/stdc++.h>
using namespace std;
int m,in[1005][3],maxx;
int main()
{
	cin>>m;
	for(int i=1;i<=m;i++)
	 cin>>in[i][1];
	for(int i=1;i<=m;i++)
	 {
	 	for(int j=1;j<=i;j++)
	 	 if(in[i][1]>in[j][1]) in[i][2]=in[j][2];
	 	in[i][2]++;
	 }
	for(int i=1;i<=m;i++)
	 if(maxx<in[i][2])
	  maxx=in[i][2];
	cout<<maxx<<endl;
	return 0;
}
