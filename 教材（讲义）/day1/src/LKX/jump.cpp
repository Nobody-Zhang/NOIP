#include<bits/stdc++.h>
using namespace std;

//����ʯͷ�����ִ� 
//��������ȡ�����max��min 

//ǰ���j������ֵ����i�㱾���ֵҪ���ٴ���k
//����g 
//deque֧��q.push_front()���ײ����룬 q.pop_front()���ײ�����
//�õ��������Ż���dp��i��ֻ��j�йأ�����Q����front������״̬��ǰj������ֵ 
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
	int las=0;//lasΪ��Զ�Ĵ�����ı��
	for(int i=0;i<=n;i++)
	dp[i]=-inf;
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		while(pos[las]<pos[i]-r) las++;//las�൱��head���൱��һ�����У�head������������У���0�Ƶ�d-r 
		while(pos[i]-l>=pos[las]&&pos[i]-r<=pos[las]&&las<i)//��֤�������½�
		{
			while(Q.size()&&(dp[Q.back()]<=dp[las]||pos[Q.back()]<pos[i]-r)) 
			//Q.back()�������һ��Ԫ�� 
			Q.pop_back();
			Q.push_back(las);//�����������ұ飬�ҵ�һ��max 
			las++;
		}
		while(Q.size()&&pos[Q.front()]<pos[i]-r)
		Q.pop_front();//ά������ 
		
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
��������
1�� long long�Ǳ����
2��inf���㹻��0x7f7f7f7f̫С��
3��ȡmaxʱ����ᷢ��max(0,d-mid)��CE
��Ϊ 0��int d-mid��long long
���� if����?:���������ȫ
4������ʱע��l��r
Ӧ��û�˰ɡ�
*/
