#include<bits/stdc++.h>
using namespace std;
int f1[61][4][3],v[61],p[61],q[61],m,n,f[32005];
int main()
{
	cin>>m>>n;//m是总钱数，n是总个数 
	for(int i=1;i<=n;i++)
	{
		cin>>v[i]>>p[i]>>q[i];
		//v是价格，p是重要度，q是主件还是附件 
		p[i]*=v[i];//p这里表示价值 
	}
	for(int i=1;i<=n;i++)
	 if(q[i]==0) {
	 	f1[i][0][0]++;//当前小组个数+1 
	 	f1[i][f1[i][0][0]][1]=v[i];//2主件存储在第一格 
	 	f1[i][f1[i][0][0]][2]=p[i];
	 }
	 else{
	 	f1[q[i]][0][0]++;
	 	f1[q[i]][f1[q[i]][0][0]][1]=v[i]+f1[q[i]][1][1];//2附件存储在第二三格 
	 	f1[q[i]][f1[q[i]][0][0]][2]=p[i]+f1[q[i]][1][2];
	 }
	for(int i=1;i<=n;i++)
	 if(f1[i][0][0]==3)
	  {
	  	f1[i][0][0]++;
	  	f1[i][4][1]=f1[i][3][1]+f1[i][2][1]-f1[i][1][1];
	  	f1[i][4][2]=f1[i][3][2]+f1[i][2][2]-f1[i][1][2];
	  }
	//3重量存储在第一格，价值存储在第二格 
	for(int i=1;i<=n;i++)
	 for(int j=m;j>=0;j--)
	  for(int k=1;k<=f1[i][0][0];k++)
	   if(j>=f1[i][k][1])
	   	f[j]=max(f[j],f[j-f1[i][k][1]]+f1[i][k][2]);
	cout<<f[m];
	return 0;
}
