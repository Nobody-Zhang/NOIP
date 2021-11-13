#include<bits/stdc++.h>//万能头文件 
using namespace std;
int n,r,a[20],used[20],total;//n个数里面选r个,用过的标记used[]数组里面为1，
//每个走的数存在a里面 ,total是总共个数 
void f(int i)//步数为i，即第i步走什么 
{
	if(i>r)//超过给定范围，开始打印 ，终止条件 
	 {
	 	for(int y=1;y<=r;y++)//从y开始到r 
	 	cout<<a[y]<<" ";//打印 
	 	cout<<"\n" ;//换行 
	 	total++;//个数+1 
	 	return;//结束这种情况 
	 } 
	 for(int u=1;u<=n;u++)//如果在范围之内，递增 试验 
	  if(used[u]==0)//如果没有标记,继续语句
	   {
	   		a[i]=u;//存储第i步为u
		    used[u]=1;//把u做标记，以便下一次不用
			f(i+1);// 试验下一步应该走哪一个数
			used[u]=0;//还原之前用过的数，方便下一次循环 
	   } 
	 //搜索函数结束 
}
int main()//下面编写主函数
{
	cin>>n>>r;//输入该从哪些数里面寻找多少个数 
	f(1);//从第一步开始 
	cout<<total;
	return 0;//结束主函数 
} //华丽结尾 
