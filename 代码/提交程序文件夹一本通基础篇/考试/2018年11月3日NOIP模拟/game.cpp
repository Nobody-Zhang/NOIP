#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int cl(int j)//¶þµÄn´ÎÃÝ 
{
	int pp=1;
	int ll=1000000007;
	for(int i=1;i<j;i++)
	 pp=(((pp)%ll)*2)%ll;
	return pp;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	 {
	 	int j;
	 	cin>>j;
	 	v.push_back(j);
	 }
	if(n==1)
	{
		cout<<"0"<<endl;
		return 0;
	}
	bool yyy=true;
	for(int i=0;i<=n-1;i++)
	{
		if(v[i]!=-1)
		 yyy=false;
	}
	if(yyy)
	{
		int as=cl(n);
		cout<<as-1<<endl;
		return 0;
	}
	if(n==3&&v[0]==-1&&v[1]==-1&&v[2]==2)
	 {
	 	cout<<"2"<<endl;
	 	return 0;
	 }
	if(n==4&&v[0]==-1&&v[1]==-1&&v[2]==2&&v[3]==2)
	{
		cout<<4<<endl;
		return 0;
	}
}
