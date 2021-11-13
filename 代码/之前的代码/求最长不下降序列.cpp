#include<bits/stdc++.h>
using namespace std;
int in[1000005][4],maxx,maxq,m;
//1存储数据，2存储当前的长度，3存储他的父亲标号 
/*void pr(int i)
{
	if(i==0) return;
	cout<<in[i][1]<<" ";
	pr(in[i][2]);
}*/
int main()
{
	int minn=9999999;
	cin>>m;
	for(int i=1;i<=m;i++)
	 cin>>in[i][1];
	in[m][2]=1;
	for(int i=m-1;i>=1;i--)
	 {
	 	for(int j=i+1;j<=m;j++)
	  	 if(in[i][1]<in[j][1]&&in[i][2]<in[j][2])
	   	  in[i][2]=in[j][2],in[i][3]=j;
	   	in[i][2]++;
	 }
	 //int o=1;
	 for(int i=1;i<=m;i++)
	  {
	  	if(maxx<in[i][2]) 
		  	maxx=in[i][2];
	  }
	 for(int i=1;i<=m;i++)
	  if(maxx==in[i][2])
	   {
	   	maxq=i;
	   	break;
	   }
	cout<<"max="<<maxx<<endl;
	while(maxq!=0)
	{
		cout<<in[maxq][1]<<" ";
		maxq=in[maxq][3];
	}
	return 0;
}
