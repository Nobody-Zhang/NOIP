#include<bits/stdc++.h>
using namespace std;
int m,d1[30005],d2[30005],total;
int main()
{
	freopen("fruit.in","r",stdin);
	freopen("fruit.out","w",stdout);
	cin>>m;
	for(int i=1;i<=m;i++)
	 cin>>d1[i];
	sort(d1+1,d1+1+m);
	int l1=0,r1=m,l2=0,r2=0;
	while(r1-l1+r2-l2>1)
	{
		int t=0;
		if(l1==r1||l2<r2&&d2[l2+1]<d1[l1+1])
		 t+=d2[++l2];
		else
		 t+=d1[++l1];
		if(l1==r1||l2<r2&&d2[l2+1]<d1[l1+1])
		 t+=d2[++l2];
		else
		 t+=d1[++l1];
		d2[++r2]=t;
		total+=t;
	}
	cout<<total<<endl;
	return 0;
}
