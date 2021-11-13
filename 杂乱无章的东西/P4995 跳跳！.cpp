#include<bits/stdc++.h>
using namespace std;
long long ans;
int in[301],n;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	 cin>>in[i];
	sort(in+1,in+1+n);
	int i=0,j=n;
	while(i!=j)
	{
		ans+=(in[i]-in[j])*(in[i]-in[j]);
		i++;
		ans+=(in[i]-in[j])*(in[i]-in[j]);
		if(i==j) break;
		j--;
	}
	cout<<ans<<endl;
	return 0;
}