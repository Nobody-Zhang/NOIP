//my.cpp.
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
/*
����dp[i]�������˵�i��λ��֮������÷֡�
��ô״̬ת�Ʒ����ǣ�
dp[i]=max(dp[j])+a[i]; //����j�ǿ�������i��λ�á�
���ѡ���ԭ������˼������������ǲ����ܵġ�һ��Ҫ������ʵ��
*/

/*
����һ��f[i]�ó���ֱ�Ӽӽ������Ǵ���ģ���Ϊf[i]ֻ������������d-g��d+g�ĵ㣬
������< d-g�ĵ���ת�Ʋ����ġ�����ά��һ��point,��ʾ��ǰ��ǰ���һ��û�м��뵥�����е�Ԫ�أ�
���ҽ�����ǰ�ڵ�������>=d-g��ʱ��������Ԫ�ؽ��ӡ����������ÿ��ѭ��һ��i��ʱ�������� 
Ȼ��ȥ����ͷ�Ķ���״̬ 
����ö��׵����ֵ�ó�f[i]�����ж�f[i]�Ƿ��������k�� 
*/
long long MIN= 0x8080808080808080;
const int inf=5e5+7;
typedef long long ll;
struct node
{
    ll dis;
    ll score;
}arr[inf];
ll que[inf],dp[inf];//�������С�dp[i]��ʾ������i�����ӵ�����ջ� 
int n,d,k;          //��Ҫ����ϸ�ڣ�����Ҫ�Ŀ���ɡ�����һ������������ ������ 1
 
long long fun(ll mid)//һ���ǹ̶��ģ�����һ�־��������ֲ��ǹ̶��İɡ�
{
	ll thel=max( (int)1, int(d-mid));      //���Ϊ����С�ľ���ɡ�
    ll ther=d+mid;
	memset(que,0,sizeof(que));
	memset(dp,0x80,sizeof(dp));
	dp[0]=0;
 
    int head=1,tail=0;//
    int point=0;         
    for(int i=1;i<=n;i++)//�ؼ�����dp[j],��һ������������
    {
        while(arr[point].dis+thel<=arr[i].dis&&point<i)
        {
            if( dp[point]!=MIN )//������ǿ����������ϡ�
            {
                while(head<=tail&&dp[point]>=dp[que[tail]] )tail--;//��⻹�ǹؼ�����
                que[++tail]=point;//��˿�������һ�����������ӵ�Ԫ�ؽ��м�ԭ�ȶ����е�Ԫ�ء�
            }
            point++;
        }
        //֮�����ȥ������j�ķ�Χ�е��ˡ��԰��������������ġ�
        while( head<=tail&&arr[ que[head] ].dis+ther<arr[i].dis)head++;
		if(head<=tail)//�������ֲ���һ�۾��ܿ������ģ����е������������Ŀ�����ۺ�ʱ��Ҫ�����ж�head�Ƿ�С�ڵ���tail��
			dp[i]=dp[que[head]]+arr[i].score;
    }
    //֮���Ǵ���һ����Χѡ�����ֵ�أ� Ӧ�������İɡ�
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
    else            //��Ҫ������Ϊ������С�
    {
        ll l=0,r=max(arr[n].dis,(ll)d);
        while(l<=r)     //
        {
            ll mid=(l+r)/2;
          //  ll thel=max( (int)1, int(d-mid));      //���Ϊ����С�ľ���ɡ�
          //  ll ther=d+mid;
            if(fun(mid)) theans=mid,r=mid-1;
            else l=mid+1;
        }
        cout<<theans<<endl;
    }
    return 0;
}

