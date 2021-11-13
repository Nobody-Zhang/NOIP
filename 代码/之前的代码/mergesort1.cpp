#include<bits/stdc++.h>
using namespace std;
#define maxN 100010
int a[maxN],b[maxN];

void merge(int l,int m,int r)
{
	int i=l,k=l,j=m+1;
	memcpy(b+l,a+l,sizeof(int)*(r-l+1));
    while(i<=m&&j<=r)
       if (b[i]<=b[j])
          a[k++]=b[i++];
       else 
          a[k++]=b[j++];
    while(i<=m) a[k++]=b[i++];
    while(j<=r) a[k++]=b[j++];
       
}
void mergesort(int l,int r)
{
	if(l<r)
	{
       int m=(l+r)>>1;
       mergesort(l,m);
       mergesort(m+1,r);
       merge(l,m,r);
       
	}      
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  scanf("%d",&a[i]); 
	mergesort(1,n);
	for(i=1;i<=n;i++)
	  printf("%d ",a[i]); 
	return 0;
}
