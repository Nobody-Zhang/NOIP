#include<bits/stdc++.h>
using namespace std;
int n,m;
long long in[1000001];
int search(int lef,int rig,long long goal)
{
	if(lef==rig){
		if(in[lef]==goal) return lef;
		return -1;
	} 
	int flag=(lef+rig)/2;
	//if(lef==rig&&in[lef]!=goal) return -1;
	/*if(in[flag]==goal){
		while(in[flag]==goal){
			flag--;
		}
		return flag+1;
	}*/
	if(in[flag]>=goal)
	 return search(lef,flag,goal);
	return search(flag+1,rig,goal);
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	bool flag=false;
	cin>>in[1];
	for(int i=2;i<=n;i++)
	{
		cin>>in[i];
		//if(in[i]!=in[i-1]) flag=true;
	}	
	/*if(!flag){
		for(int i=1;i<=m;i++) cout<<"1 ";
		return 0;
	}*/
	for(int i=1;i<=m;i++)
	{
		long long sea;
		cin>>sea;
		cout<<search(1,n,sea)<<" ";
	}
	return 0;
}