#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	int i,m,min=100000000,min2,y;
	cin>>m;
	for(int y=1;y<=m;y++)
	 cin>>a[y];
	for(y=1;y<=m;y++)
	 if(min>a[y])
	 {
	 	min=a[y];
		min2=y;
	 }
	swap(a[1],a[min2]);
	for(int y=1;y<=m;y++)
	cout<<a[y]<<" ";
	return 0;
}
