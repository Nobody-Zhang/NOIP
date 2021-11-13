#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j[101][101];
	cin>>i;
	for(int m=1;m<=i;m++)
	 for(int n=1;n<=m;n++)
	  cin>>j[m][n];
	for(int m=i;m>=1;m--)
	 for(int n=1;n<=m;n++)
	  j[m][n]=max(j[m][n]+j[m+1][n],j[m][n]+j[m+1][n+1]);
	cout<<j[1][1];
	return 0;
}
