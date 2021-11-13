#include<bits/stdc++.h>
using namespace std;
int a[35],lie[35],line1[35],line2[35],n;
void dfs(int i)//i是行 
{
	if(i==n+1)
	{
		for(int j=1;j<=n/*?*/;j++)
		 cout<<a[j]<<" ";
		cout<<"\n";
		return;
	}
	for(int j=1;j<=n;j++)//行递增 
	 if(lie[j]==0&&line1[j+i]==0&&line2[i-j+n]==0)
	{
		a[i]=j;
		lie[j]=1;
		line1[i+j]=1;
		line2[i-j+n]=1;
		dfs(i+1);
		lie[j]=0;
		line1[i+j]=0;
		line2[i-j+n]=0;
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1);
	return 0;
}
