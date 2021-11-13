#include<bits/stdc++.h>
using namespace std;
int n,in[1005][4],maxx;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	 cin>>in[i][1];
	for(int i=1;i<=n;i++)
	 {
	 	for(int j=i-1;j>=1;j--)
	 	if(in[i][1]>in[j][1]&&in[i][2]<=in[j][2])
	 	in[i][2]=in[j][2];
	 	in[i][2]++;
	 }//这个是求最长上升子序列的问题 
	 //但是由于浏览到一个景点下山时还是可以游玩，就要求那个点向后的最长下降子序列 
	 //可以转化成求max到当前的最长上升子序列 
	for(int i=n;i>=1;i--)
	{
		for(int j=i+1;j<=n;j++)
		if(in[i][1]>in[j][1]&&in[i][3]<=in[j][3])
		 in[i][3]=in[j][3];//求长下降子序列 
		in[i][3]++;
	}
	for(int i=1;i<=n;i++)
	 if(in[i][2]+in[i][3]>maxx) maxx=in[i][2]+in[i][3];
	cout<<maxx-1;//因为当前景点被算了两遍，所以说就要-1
	return 0; 
}
/*
8
186 186 150 200 160 130 197 220
*/
