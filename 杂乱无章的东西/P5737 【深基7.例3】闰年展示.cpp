#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,n,tot=0;
	cin>>m>>n;
	for(int i=m;i<=n;i++)
		if((i%4==0&&i%100!=0)||(i%400==0)) tot++;
	cout<<tot<<endl;
	for(int i=m;i<=n;i++)
		if((i%4==0&&i%100!=0)||(i%400==0)) cout<<i<<" ";
	return 0;
}