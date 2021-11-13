#include<bits/stdc++.h>
using namespace std;
int heap[1001],m,heap_size,as[1001],as_size;
void put(int i)
{
	int now,next;
	heap[++heap_size]=i;
	now=heap_size;//儿子节点 
	while(now>1)
	{
		next=now>>1;//父亲节点 
		if(heap[now]>=heap[next]) break;
		swap(heap[now],heap[next]);
		now=next;
	}
}
int get()
{
	int re,size,now,next;
	re=heap[1];//存储数据 
	heap[1]=heap[heap_size--];//将最后一位移动到最上面 
	now=1;//父亲节点 
	while(now*2<=heap_size)//还有儿子 
	{
		next=now*2;
		if(next<heap_size&&heap[next+1]<heap[next]) next++;
		if(heap[now]<heap[next]) break;
		swap(heap[now],heap[next]);
		now=next;
	}
	return re;
}
int main()
{
	freopen("btree.in","r",stdin);
	freopen("btree.out","w",stdout);
	//std::ios::sync_with_stdio(false);
	//cin.tie(0);
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int k;
		scanf("%d",&k);
		put(k);
	}
	//for(int i=1;i<=m;i++)
	 //cout<<heap[i]<<" ";
	//cout<<endl;
	for(int i=1;i<=m;i++)
	 {
	 	int j=get();
	 	//cout<<endl;
	 	 //cout<<j<<endl;
	 	as[++as_size]=j;
	    //for(int k=1;k<=m-i;k++)
	     //cout<<heap[k]<<" ";
	 }
	//cout<<endl;
	for(int i=1;i<=m;i++)
	 cout<<as[i]<<" ";
	return 0;
}
