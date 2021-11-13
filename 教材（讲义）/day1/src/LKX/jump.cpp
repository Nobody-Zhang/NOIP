#include<bits/stdc++.h>
using namespace std;

//像跳石头，二分答案 
//滑动窗口取区间的max和min 

//前面的j点的最大值加上i点本身的值要至少大于k
//二分g 
//deque支持q.push_front()—首部插入， q.pop_front()—首部弹出
//用单调队列优化，dp【i】只与j有关，假设Q里面front是最优状态，前j点的最大值 
const long long inf=1e18;
int  n;
long long pos[500001],val[500001];
deque<long long>Q;
long long d,k;
long long dp[500001];

bool check(long long mid)
{
	if(!Q.empty()) Q.clear();
	long long l=(d-mid<0?0:d-mid);
	long long r=mid+d;
	int las=0;//las为最远的待加入的编号
	for(int i=0;i<=n;i++)
	dp[i]=-inf;
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		while(pos[las]<pos[i]-r) las++;//las相当于head，相当于一个队列，head不在这个区间中，从0移到d-r 
		while(pos[i]-l>=pos[las]&&pos[i]-r<=pos[las]&&las<i)//保证不超上下界
		{
			while(Q.size()&&(dp[Q.back()]<=dp[las]||pos[Q.back()]<pos[i]-r)) 
			//Q.back()返回最后一个元素 
			Q.pop_back();
			Q.push_back(las);//把整个区间找遍，找到一个max 
			las++;
		}
		while(Q.size()&&pos[Q.front()]<pos[i]-r)
		Q.pop_front();//维护队首 
		
		if(Q.size()!=0) dp[i]=dp[Q.front()]+val[i];
		if(dp[i]>=k) return 1;
	}
	return 0;
}
//las.....r____l

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%I64d%I64d",&n,&d,&k);
	for(int i=1;i<=n;i++)
	scanf("%I64d%I64d",&pos[i],&val[i]);
	long long l=1,r=pos[n];
	while(l!=r)
	{
		long long mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	if(!check(l)){
        printf("-1");
        return 0;
    }
    else printf("%I64d",l);
    return 0;
}
/*
！！！！
1： long long是必须的
2：inf得足够大，0x7f7f7f7f太小了
3：取max时，你会发现max(0,d-mid)会CE
因为 0：int d-mid：long long
还是 if语句或?:运算符更安全
4：二分时注意l和r
应该没了吧。
*/
