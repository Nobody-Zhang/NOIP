#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	int q,o=0;
	cin>>q;
	for(int u=1;u<=q;u++)
	 cin>>a[u];
	for(int u=1;u<=q;u++)
	 for(int i=1;i<=q-u;i++)
	 if(a[i]>a[i+1])
	  swap(a[i],a[i+1]);
	for(int u=1;u<=q;u++)
	 for(int i=u+1;i<=q;i++)//ÅÅÐò´íÎó 
	  for(int p=i+1;p<=q;p++)
	   if(a[u]+a[i]>a[p]) 
	   o++;
	   cout<<o;
	   return 0;
}

