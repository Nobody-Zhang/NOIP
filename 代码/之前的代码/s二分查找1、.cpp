#include<bits/stdc++.h>
using namespace std;
int x;
void search(int min,int max,int n)
{
	int mid;
	mid=(max+min)/2;
	x++;
	if(n==mid) return; 
	else if(n>mid) search(mid,max,n);
	else search(min,mid,n);
}
int main()
{
	int o,m,n;
	cin>>o>>m>>n;
	search(o,m,n);
	cout<<x;
	return 0;
}
