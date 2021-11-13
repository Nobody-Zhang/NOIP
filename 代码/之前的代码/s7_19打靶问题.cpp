#pragma GCC optimize(2)//启动氧气优化 
#include<bits/stdc++.h>//万能头 
int a[15],total;//定义a为漏环，total总方案个数 
using namespace std;//我也不知道干什么 
void dfs(int i,int rest)//第几枪<=10，可以漏rest环 
{
	if(i==11)//在规定以内漏完十环，就是得到90环 
	{
		if(rest==0)
		{
			for(int o=1;o<=10;o++)
			printf("%d ",10-a[o]);
			cout<<"\n";
			total++;//打印怎么打 
		  
		}
	 return;
	}
	for(int k=0;k<=10;k++)
	 {
	 		a[i]=k;
			 dfs(i+1,rest-k);
	 	
	 }
}
int main()
{
	dfs(1,10);
	cout<<total;
	return 0;
}
