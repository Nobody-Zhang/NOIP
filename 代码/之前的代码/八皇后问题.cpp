#include<bits/stdc++.h>
using namespace std;
int h=8;
int mp[9][9];
int total;
int b[20],c[20],d[20];
void pr()
{
	for(int i=1;i<=8;i++)
	 {
	 	for(int j=1;j<=8;j++)
	 	 cout<<mp[i][j]<<" ";
	 	 cout<<"\n";
	 }
	 cout<<"\n";
}
void dfs(int i,int k)//i lie
{
	if(k>h)
	{
		pr();
		total++;
		return;
	}
	for(int n=1;n<=8;n++)//i是列 n是行 
	 if(b[n]==0&&c[i+n]==0&&d[8-n+i]==0)
	 {
	 	mp[n][i]=1;
	 	b[n]=1,c[i+n]=1,d[8-n+i]=1;
	 	dfs(i+1,k+1);
	 	b[n]=0,c[i+n]=0,d[8-n+i]=0;
	 	mp[n][i]=0;
	 }
} 
int main()
{
	dfs(1,1);
	cout<<total;
	return 0;
}
