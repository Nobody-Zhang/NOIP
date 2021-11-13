#include<bits/stdc++.h>
using namespace std;
int main()
{
	int add[1001],temp[1001];
	memset(add,0,sizeof(add));
	memset(temp,0,sizeof(temp));
	ios::sync_with_stdio(false);
	int m;
	cin>>m;
	temp[1]=1,add[1]=1;
	for(int i=2;i<=m;i++)
	{
		for(int j=1;j<=100;j++)
		//最长不超过100位吧
			temp[j]*=i;
		for(int j=1;j<=100;j++)
			if(temp[j]>=10)
			{
				temp[j+1]+=(temp[j]/10);
				temp[j]%=10;
			}
		for(int j=1;j<=100;j++){
			add[j]+=temp[j];
			if(add[j]>=10){
				add[j+1]+=(add[j]/10);
				add[j]%=10;
			}
		}
	}
	int flag=100;
	for(;flag>=0;flag--){
		if(temp[flag]!=0) break;
	}
	for(int i=flag;i>=1;i--){
		cout<<add[i];
	}
	return 0;
}