#include<bits/stdc++.h>
using namespace std;
//t-a[i]<=m ���Զ�ά���鲻�ᱬ
#define N 505
int good[N][N],n,timer,a[N]; 
int dfs(int i,int t)
{
	if(i==n+1) return 0;
	//������ڵ�ʱ��û���� ��������һ�����˵�ʱ�� 
	if(t<a[i]) return dfs(i,a[i]);
	//t��ΪС��a[i] �ᵼ������Խ�� 
	if(good[i][t-a[i]])//��i���� �����ѵĵȴ�ʱ��Ϊt-a[i] 
	 return good[i][t-a[i]];
	
	//������ ���Ǵ���һ���ƹ�������ʱ��Ҫ��һ�� 
	int sum=0,j=i;
	//�պ�<=����ʱ�����һ���� 
	while(j<=n&&a[j]<=t)
	 sum+=a[j++];
	//��Ϊj�����1���Ժ���Ͳ��ü�1 
	int best=(j-i)*t-sum+dfs(j,t+timer);
	for(;j<=n;j++)
	{
		sum+=a[j];
		best=min(a[j]*(j-i+1)-sum+dfs(j+1,a[j]+timer),best);
	}
	//���仯���� 
	return good[i][t-a[i]]=best;
}
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%d%d",&n,&timer);
	for(int i=1;i<=n;i++)
	 scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	printf("%d\n",dfs(1,0));
}
