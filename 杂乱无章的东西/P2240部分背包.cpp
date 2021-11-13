#include<bits/stdc++.h>
using namespace std;
int n,t,rest;
struct data{
	double m,v,aver;//m是重量，v是价值,aver是比例
}a[101];
double tot;
int main()
{
	scanf("%d%d",&n,&t);
	rest=t;
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&a[i].m,&a[i].v);
		a[i].aver=a[i].v/a[i].m;//aver表示比价值（价值/重量）
	}
	for(int i=1;i<=n;i++)
	{
		int maxx=i;
		for(int j=i;j<=n;j++)
			if(a[j].aver>a[maxx].aver) maxx=j;
		swap(a[i],a[maxx]);
	}//以比价值降序排序
	/*for(int i=1;i<=n;i++)
	{
		cout<<a[i].m<<" "<<a[i].v<<endl;
	}*/
	for(int i=1;i<=n;i++)
	{
		rest-=a[i].m;
		if(rest<0){//如果剩余没钱了（不能一整个都拿走）
			rest+=a[i].m;
			tot=tot+rest*a[i].aver;
			break;
		}
		tot+=a[i].v;
	}
	printf("%.2lf",tot);
	return 0;
}