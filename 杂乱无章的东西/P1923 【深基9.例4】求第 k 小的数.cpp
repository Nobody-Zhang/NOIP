#include<bits/stdc++.h>
using namespace std;
int a[5000001],m,k;
void qsort(int l,int r)
{
	if(l==r){
		cout<<a[k]<<endl;
		exit(0);
	}
	int i=l,j=r,tmp=a[l];
	while(i!=j)
	{
		while(a[j]>=tmp&&j>i) j--;
		while(a[i]<=tmp&&i<j) i++;
		swap(a[i],a[j]);
	}
	swap(a[l],a[i]);
	if(i==k){
		cout<<a[k]<<endl;
		exit(0);
	}
	if(i>k) qsort(l,i-1);
	if(i<k) qsort(i+1,r);
}
int main()
{
	scanf("%d%d",&m,&k);
	k++;
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	qsort(1,m);
}