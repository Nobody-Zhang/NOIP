#include<bits/stdc++.h>
using namespace std;
#define MAXX 1000001
struct data{
	long long beg,en;
}a[MAXX];
int n,tim[MAXX],tot;//n是总数
bool cmp(data x,data y)
{
	return (x.en<y.en);//记忆一下
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&a[i].beg,&a[i].en);
	/*for(int i=1;i<=n;i++)
	{
		int k=i;//k表示最小的end值
		for(int j=i;j<=n;j++)
			if(a[k].en>a[j].en) k=j;
		swap(a[i],a[k]);
	}*/
	sort(a+1,a+1+n,cmp);
	int las=0;//表示上一个结束的时间
	for(int i=1;i<=n;i++)
	{//找起始时间大于上一个的结束的时间的就OK了
		if(a[i].beg>=las){
			tot++;
			las=a[i].en;
		}
	}
	printf("%d",tot);
	return 0;
}