#include<bits/stdc++.h>
using namespace std;
int a[10001],b[10001],sum=0,n,m;
void qsort(int x,int y)
{
	int i,j,mid1,mid2;
	i=x,j=y,mid1=b[(x+y)/2],mid2=a[(x+y)/2];//取中间值 
	while(i<=j)//当两个指针之间还有元素时 
	{
		while(b[i]<mid1||((b[i]==mid1)&&(a[i]<mid2))) i++;
		while(b[j]>mid1||((b[j]==mid1)&&(a[j]>mid2))) j--;
		if(i<=j)
		{
			swap(b[j],b[i]);
			swap(a[j],a[i]);
			i++,j--;
		}
	}
	if(x<j) qsort(x,j);
	if(i<y) qsort(i,y);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	 cin>>a[i]>>b[i];
	qsort(1,n);
	for(int i=1,x=-1;i<=n;i++)
	{
		if(x>=a[i]) continue;
		sum++;x=b[i];
	}
	cout<<sum<<endl;
	return 0;
}
