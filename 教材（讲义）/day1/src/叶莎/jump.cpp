//my.cpp.
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
/*
定义dp[i]是跳到了第i个位置之后的最大得分。
那么状态转移方程是；
dp[i]=max(dp[j])+a[i]; //其中j是可以跳到i的位置。
如此选择的原因是你思考的那种情况是不可能的。一定要符合事实。
*/

/*
发现一个f[i]得出后直接加进队列是错误的，因为f[i]只能跳到距离它d-g到d+g的点，
距离它< d-g的点是转移不到的。考虑维护一个point,表示当前最前面的一个没有加入单调队列的元素，
当且仅当当前节点和它相差>=d-g的时候就让这个元素进队。这个进队在每次循环一个i的时候先做。 
然后去除队头的多余状态 
最后用队首的最大值得出f[i]，并判断f[i]是否满足大于k分 
*/
long long MIN= 0x8080808080808080;
const int inf=5e5+7;
typedef long long ll;
struct node
{
    ll dis;
    ll score;
}arr[inf];
ll que[inf],dp[inf];//单调队列。dp[i]表示跳到第i个格子的最大收获 
int n,d,k;          //不要在意细节，从主要的看起吧。定义一个变量？？？ 可以吗？ 1
 
long long fun(ll mid)//一种是固定的，还有一种就是像这种不是固定的吧。
{
	ll thel=max( (int)1, int(d-mid));      //理解为是最小的距离吧。
    ll ther=d+mid;
	memset(que,0,sizeof(que));
	memset(dp,0x80,sizeof(dp));
	dp[0]=0;
 
    int head=1,tail=0;//
    int point=0;         
    for(int i=1;i<=n;i++)//关键是在dp[j],用一个变量来保存
    {
        while(arr[point].dis+thel<=arr[i].dis&&point<i)
        {
            if( dp[point]!=MIN )//定义的是可以跳到其上。
            {
                while(head<=tail&&dp[point]>=dp[que[tail]] )tail--;//理解还是关键啊。
                que[++tail]=point;//如此看来，第一部分是新增加的元素进行挤原先队列中的元素。
            }
            point++;
        }
        //之后就是去除不在j的范围中的了。对啊，这俩是相连的。
        while( head<=tail&&arr[ que[head] ].dis+ther<arr[i].dis)head++;
		if(head<=tail)//对于这种不是一眼就能看出来的，其中的量是随机的题目，不论何时都要进行判断head是否小于等于tail。
			dp[i]=dp[que[head]]+arr[i].score;
    }
    //之后是从哪一个范围选出最大值呢？ 应该是最大的吧。
    long long ans=MIN;
    for(int i=1;i<=n;i++)
        if(dp[i]>ans)
			ans=dp[i];
   // return ans;
    if(ans>=k) return 1;
    else return 0;
}
 
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
    scanf("%d %d %d",&n,&d,&k);
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d %I64d",&arr[i].dis,&arr[i].score);
        if(arr[i].score>0)
            ans+=arr[i].score;
    }
    ll theans=0;
    if(ans<k)
        cout<<-1<<endl;
    else            //定要尝试最为精简才行。
    {
        ll l=0,r=max(arr[n].dis,(ll)d);
        while(l<=r)     //
        {
            ll mid=(l+r)/2;
          //  ll thel=max( (int)1, int(d-mid));      //理解为是最小的距离吧。
          //  ll ther=d+mid;
            if(fun(mid)) theans=mid,r=mid-1;
            else l=mid+1;
        }
        cout<<theans<<endl;
    }
    return 0;
}

