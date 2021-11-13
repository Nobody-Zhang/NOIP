#include<bits/stdc++.h>
using namespace std;
int a[10000];
void qsort(int l,int r)
{
	int i=l,j=r,m;
	m=a[(l+r)/2];
	do{
		while (a[i]<m) i++;
		while (a[j]>m) j--;
		if(i<=j){
			swap(a[i],a[j]);
			i++,j--;
		}
	}while(i<=j);
	if(i<r) qsort(i,r);
	if(j>l) qsort(l,j);
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	qsort(1,n);
	for(int i=1;i<=n;i++)
	 cout<<a[i]<<" ";
	cout<<"\n";
	return 0;
}
