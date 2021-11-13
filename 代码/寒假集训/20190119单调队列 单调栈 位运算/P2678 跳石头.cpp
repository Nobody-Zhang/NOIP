#include<bits/stdc++.h>
using namespace std;
int in[50000005],l,m,n,ans;
bool judge(int mid)
{
	int inc=0;
	int now=0;
	for(int i=1;i<=m+1;i++)
	 {
	 	int len=in[i]-in[now];
	 	if(len<mid) inc++;
	 	else now=i;
	 }
	if(inc<=n) return true;
	return false;
}
int main()
{
	cin>>l>>m>>n;
	for(int i=1;i<=m;i++)
	 cin>>in[i];
	sort(in+1,in+m+1);
	in[m+1]=l;
	int lef=1,rig=l;
	while(lef<=rig)
	{
		int mid=(lef+rig)/2;
		if(judge(mid)){
			ans=mid;
			lef=mid+1;
		}
		else{
			rig=mid-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
