#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("money.in","w",stdout);
	srand(time(0));
	int a=rand()%5+1;
	cout<<a<<endl;
	for(int i=1;i<=a;i++)
	{
		int k=rand()%10+1;
		cout<<k<<endl;
		for(int j=1;j<=k;j++)
		{
			int r=rand()%39+1;
			cout<<r<<" ";
		}
		cout<<endl;
	}
}
