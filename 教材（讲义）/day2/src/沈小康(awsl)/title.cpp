#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("title.in","r",stdin);
	freopen("title.out","w",stdout);
	int ans=0;
	char a[1001];
	while(cin>>a)
	{
		for(int i=0;i<strlen(a);++i) if(a[i]!=' ') ans++;
	}
	cout<<ans<<endl;
	return 0;
}
