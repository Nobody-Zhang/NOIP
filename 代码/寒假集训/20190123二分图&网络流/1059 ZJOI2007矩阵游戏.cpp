#include<bits/stdc++.h>
using namespace std;
bool mp[201][201];
int main()
{
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int size;
		scanf("%d",&size);
		for(int i=1;i<=size;i++)
		 for(int j=1;j<=size;j++)
		  mp[i][j]=false;
		for(int i=1;i<=size;i++)
		 for(int j=1;j<=size;j++)
		  {
		  	int a;
		  	scanf("%d",&a);
		  	if(a==0) mp[i][j]=false;
		  	else mp[i][j]=true;
		  }
		for(int i=1;i<=size;i++)
		 
	}
}
