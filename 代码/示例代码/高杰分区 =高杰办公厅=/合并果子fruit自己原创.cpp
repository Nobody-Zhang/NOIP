#include<bits/stdc++.h>
using namespace std;
int a[30015],b[30015],t,tot=0;
int main()
{
	freopen("fruit.in","r",stdin);
	freopen("fruit.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(t=1;t<=n;t++)
	scanf("%d",&a[t]);
	
	sort(a+1,a+n+1);
	
	int s1=0,end1=n,s2=0,end2=0;//1 指未合并 2指已合并的 
	while(end1-s1+end2-s2>=2)
	{
       t=0;
    if (s1==end1||s2<end2&&b[s2+1]<a[s1+1])//选第1堆 
      t+=b[++s2];
    else 
      t+=a[++s1];
    if (s1==end1||s2<end2&&b[s2+1]<a[s1+1])//选第2堆 
      t+=b[++s2];
    else 
      t+=a[++s1];
    tot+=t;
    b[++end2]=t;    
  
	}
	printf("%d",tot);
	
}
