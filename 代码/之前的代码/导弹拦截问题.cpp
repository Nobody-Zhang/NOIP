#include<bits/stdc++.h>
using namespace std;
int high[1001],maxx[1001],all,minn;
int k=1;//当前的导弹拦截系统个数 
int transfor;//表示中转作用 
int main()
{
	freopen("act.in","r",stdin);
	freopen("act.out","w",stdout);
	while((scanf("%d",&high[++all]))!=EOF);//输入数据 
	all=all-1;
	maxx[1]=high[1];
	for(int i=2;i<=all;i++)//搜索第i个导弹 
	{
		transfor=0;
		for(int j=1;j<=k;j++) 
           //搜索全部系统 
		{
			if(maxx[j]>=high[i])
		  	//表示能被导弹系统拦截 
			{
				if(transfor==0)//表示没有任何导弹系统之前的能拦截 
				 transfor=j;//中转变为j 
				else if(maxx[j]<maxx[transfor])// 表示有更优解 
				//也就是说，有个比当前的系统最大值更小的 
				 transfor=j;//更新最优方案 
			} 
		}
		if(transfor==0)//表示上一个没有执行 
		//也就是说，没有任何系统能拦截这个导弹 
		{
			k++;//新建一个导弹系统；
			maxx[k]=high[i];//将新建的系统能达到的最大值更新为当前的导弹高度 	
		} 
		else//上一个循环执行，表明能被当前有的系统拦截 
		{
			maxx[transfor]=high[i];//更新系统能拦截最大值 
		}
		
	}
	cout<<k<<endl;
	return 0;
}
