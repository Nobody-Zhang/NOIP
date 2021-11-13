#include<bits/stdc++.h>
using namespace std;
int q,ans;
void f1(int x)
{
	ans=x;
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			ans=ans/i*(i-1);
			while(x%i==0)x=x/i;
		}
	}
	if(x>1) ans=ans/x*(x-1);
	return;
}
int main()
{
	cin>>q;
	f1(q);
	cout<<ans<<endl;
	return 0;
}
