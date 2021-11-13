#include<bits/stdc++.h>
using namespace std;
int a[30015],heap_size,heap[30015],ans=0;
int na();
void put(int d)
{
	int now,father;
	heap[++heap_size]=d;
		now=heap_size;
		while(now>1)
		{
			father=now/2;
			if(heap[now]>=heap[father]) break;
			swap(heap[now],heap[father]);
			now=father;
		}
}
int  na()
{
	int geng,now,son;
	geng=heap[1];
	heap[1]=heap[heap_size];
	heap_size--;
	now=1;
	while(now*2<=heap_size)
	{
		son=now*2;
		if(son+1<=heap_size&&heap[son]>heap[son+1]) son++;
		if(heap[son]>heap[now]) return geng;
		swap(heap[now],heap[son]);
		now=son;
	}
	return geng;
}
int main()
{
	freopen("fruit.in","r",stdin);
	freopen("fruit.out","w",stdout);
	int n,s1,s2;
	scanf("%d",&n);
	for(int t=1;t<=n;t++)
	scanf("%d",&a[t]),put(a[t]);
	
	for(int t=1;t<n;t++)
	{
		s1=na();
		s2=na();
		ans=ans+s1+s2;
		put(s1+s2);
	}
	printf("%d\n",ans);
	return 0;
}
