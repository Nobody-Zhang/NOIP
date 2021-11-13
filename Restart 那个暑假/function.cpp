#include<bits/stdc++.h>
using namespace std;
long long ans[21][21][21];//最后一位顺便存储flag，看有没有计算过
long long fun(int x,int y,int z)
{
	if(x<=0||y<=0||z<=0) return 1;
	if(ans[x][y][z]) return ans[x][y][z];//如果之前被处理过，直接返回答案
	if(x<y&&y<z){
		ans[x][y][z]=fun(x,y,z-1)+fun(x,y-1,z-1)-fun(x,y-1,z);
		return ans[x][y][z];
	}
	ans[x][y][z]=fun(x-1,y,z)+fun(x-1,y-1,z)+fun(x-1,y,z-1)-fun(x-1,y-1,z-1);
	return ans[x][y][z];
}
int main()
{
	long long a,b,c;
	while(1)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		if(a==-1&&b==-1&&c==-1) return 0;
		if(a<=0||b<=0||c<=0) {//第一种情况
			printf("w(%lld, %lld, %lld) = 1\n",a,b,c);
			continue;
		}
		if(a>20||b>20||c>20){//第二种情况
			printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,fun(20,20,20));
			continue;
		}
		printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,fun(a,b,c));//都不满足，进入函数
	}
}