#include<bits/stdc++.h>
using namespace std;
int a[3][52],m,n,f[52];
int out[52],ou[52];//怎么选 
int t,as;//t是当前的解，as是最优解 
void dfs(int i,int left)//第i次，还剩left个 
{
	if(t+f[i]<as) return;
	//就算当前的最大值加上后面全选都达不到最优解，返回
	//这个是剪枝的函数 
	if(t>as)//当前的大于当前最优解，将最优解替换成当前解 
	{
		as=t;//将最大价值的方案输入到answer里面 
		for(int k=1;k<=n;k++)
		out[k]=ou[k];//将怎么选的数组定义到最优数组 
	}
	for(int j=i;j<=n;j++)
	if(left>=a[1][j])//当剩下的空间还能装得下这个物品时运行 
	{
		ou[j]=1;//选这个物品 
		t+=a[2][j];//当前的解更新 
		dfs(j+1,left-a[1][j]);//搜索下一个怎么填 
		ou[j]=0;
		t-=a[2][j];//恢复 
	}
}
int main()
{
	cin>>m>>n;//m重量，n种物品
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=2;j++)
	  cin>>a[j][i];//输入每个重量(1)和价格(2)
	for(int i=n;i>=1;i--)
	 f[i]=f[i-1]+a[2][i];//后缀和 ，就是都取的最大值 
	dfs(1,m);
	cout<<as<<endl;//输出最大值 
	for(int i=1;i<=n;i++)
	if(out[i]!=0) //要当前的物品 
	cout<<i<<" ";//输出序号 
}
