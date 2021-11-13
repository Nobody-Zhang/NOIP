#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int heap[100000],f[10001][4];
int re[10001][3],t;
int heap_size;
int qz(int i,int j)
{
	return f[i][1]*j*j+f[i][2]*j+f[i][3];
}
/*void put(int i)
{
	heap[++heap_size]=i;
	push_heap(heap+1,heap+heap_size+1);
}
int get()
{
	pop_heap(heap+1,heap+1+heap_size);
	return heap[heap_size--];
}*/
int main()
{
	freopen("minval.in","r",stdin);
	freopen("minval.out","w",stdout);
	int m,n;
	ios::sync_with_stdio(false);
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	 for(int j=1;j<=3;j++)
	  cin>>f[i][j];
	while(1)
	{
		if(t>=n) break;
		int minn=0x7fffffff,tmp;
		//memset(re,0,sizeof(re));
		for(int i=1;i<=m;i++)
		 re[i][1]=qz(i,re[i][2]+1);
		for(int i=1;i<=m;i++)
		 if(minn>re[i][1])
		  minn=re[i][1],tmp=i;
		re[tmp][2]++;
		t++;
		cout<<minn<<" ";
	}
	return 0;
}
