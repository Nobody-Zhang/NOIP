#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s[5],f;
	int a[5],max=0;
	for(int p=1;p<=4;p++)
		{
			cin>>s[p]>>a[p];
			if(a[p]>max)
			{
				max=a[p];
				f=s[p];
			}
				
		}
	cout<<f;
	return 0;
}
