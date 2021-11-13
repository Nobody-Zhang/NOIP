#include<bits/stdc++.h>
#define ll 1000000007
long long f[100005][6];
using namespace std;
void ls(int l,int s)
{
	f[1][0]=s;
	for(int i=2;i<=l;i++)
	{
		f[i][0]=(f[i-1][0]+f[i-1][1])*(s-1)%ll;
		f[i][2]=f[i-1][1];
		f[i][1]=f[i-1][0];
		f[i][3]=(((f[i-1][2]+f[i-1][3]+f[i-1][4])%ll)*(s-1))%ll;
		f[i][4]=f[i-1][3];
	}
}
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		memset(f,0,sizeof(f));
		int l,s;
		cin>>l>>s;
		ls(l,s);
		long long as=(f[l][2]+f[l][3]+f[l][4])%ll;
		cout<<as<<endl;
	}
	return 0;
}
