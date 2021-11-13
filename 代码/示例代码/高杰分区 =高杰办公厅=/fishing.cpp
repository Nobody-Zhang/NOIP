#include<bits/stdc++.h>
 
using namespace std;
#define fish first 
#define bianhao second
int n,f[105],d[105],ti[105],m,paolu[105],Time,ans,max1=-1;
priority_queue< pair<int,int> > heap;
int main()
{
	freopen("fishing.in","r",stdin);
	freopen("fishing.out","w",stdout);
	scanf("%d",&n);
   for(int t=1;t<=n;t++)
   scanf("%d",&f[t]);
   for(int t=1;t<=n;t++)
   scanf("%d",&d[t]);
   for(int t=1;t<n;t++)
   scanf("%d",&ti[t]);
   
   scanf("%d",&m);
   
   for(int k=2;k<=n;k++)
   for(int t=1;t<=k-1;t++)
   	paolu[k]+=ti[t];
    
	for(int k=1;k<=n;k++)
    {
      	Time=m-paolu[k];
      	if(Time>0)
      {
      	while( !heap.empty() )
         heap.pop();
        ans=0;
      	for(int i=1;i<=k;i++)
      	heap.push(make_pair(f[i],i));
      	while(Time>0&&heap.top().first>0)
      	{
      		pair<int,int> a=heap.top();
			  heap.pop(); 
			ans=ans+a.first;
			a.first=a.first-d[a.second];
			heap.push(a);
      		Time--;
      	}
      	max1=max(max1,ans);
      }
    }
   printf("%d",max1);
   
}
