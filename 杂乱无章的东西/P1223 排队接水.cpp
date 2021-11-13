#include<bits/stdc++.h>
using namespace std;
struct tim{
	long long t,th;//t是时间，th是序号
}in[1002];
int sor[1002];
void qsort(int l,int r)
{//左侧和右侧
	if(l>=r) return;
	int tmp=in[l].t ;
	int i=l,j=r;
	while(i!=j)
	{
		while(in[j].t>=tmp&&i<j)j--;
		while(in[i].t<=tmp&&i<j)i++;
		swap(in[i],in[j]);
	}
	swap(in[l],in[i]);
	qsort(l,i-1);
	qsort(i+1,r);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&in[i].t);
		in[i].th=i;
	}
	qsort(1,n);
	double tot=0;
	for(int i=1;i<=n;i++)
	{
		printf("%d ",in[i].th);
		//cout<<in[i].t<<" "<<in[i].th<<endl;
		sor[i]=sor[i-1]+in[i-1].t;
		tot+=sor[i];
	}
	cout<<endl;
	tot=tot*1.0/n;
	printf("%.2lf",tot);
	return 0;
}