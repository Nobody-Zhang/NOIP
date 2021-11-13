#include<bits/stdc++.h>
using namespace std;
int m,a[1001][4],maxx;
int main()
{
	cin>>m;
	for(int i=1;i<=m;i++)
	 cin>>a[i][1];
	a[1][2]=a[1][1];
	for(int i=2;i<=m;i++)
	{
		for(int j=1;j<=i-1;j++)
		if(a[i][1]>a[j][1]&&a[i][2]<a[j][2]) a[i][2]=a[j][2];
		a[i][2]+=a[i][1];
	}
	for(int i=1;i<=m;i++)
	if(a[i][2]>maxx) maxx=a[i][2];
	cout<<maxx<<endl;
	return 0;
}
/*
7
1 7 3 5 9 4 8
*/
