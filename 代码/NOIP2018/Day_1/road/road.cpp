#include<bits/stdc++.h>
using namespace std;
int a[100001],n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	int tot=a[1];
	for(int i=1;i<=n-1;i++)
	{
		if(a[i]<a[i+1])
		 tot+=(a[i+1]-a[i]);
	}
	cout<<tot<<endl;
	return 0;
}
