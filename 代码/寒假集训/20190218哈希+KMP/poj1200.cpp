#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
string s1;
map<string,int>mp;
int main()
{
	int n,m;
	scanf("%d",&n);
	while(n--)
	{
		int num=0;
		scanf("%d",&m);
		scanf("%d",&m);
		cin>>s1;
		int len=s1.length();
		for(int i=m-1;i<=len-1;i++)
		{
			//s.clean();
			int l=i-m+1;
			int r=i;
			string s=s1.substr(l,r);
			//s.clear();
			/*/for(int j=l;j<=r;j++)
				s[j]=s1[j];*/
			//str
			cout<<s1<<endl;
			cout<<s<<endl;
			if(mp[s]==0) mp[s]=1,num++;
		}
		printf("%d\n",num);
	}
	return 0;
}
