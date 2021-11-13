#include<bits/stdc++.h>
using namespace std;
int sum(int i)
{
	
	int he=0,p;
	for(p=1;p<=i;p++)
	he+=p;
	return he;
}
int main()
{
	int n,m,k,l;
		cin>>n>>m>>k;
	n=sum(n);
	m=sum(m);
	k=sum(k);
	l=n+m+k;
	cout<<l;
}
