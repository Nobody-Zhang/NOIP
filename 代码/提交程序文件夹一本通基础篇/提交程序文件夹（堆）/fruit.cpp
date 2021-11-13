#include<bits/stdc++.h>
using namespace std;
int heap[30001],heap_size,m,total;
void put(int d)
{
	heap[++heap_size]=d;
	push_heap(heap+1,heap+1+heap_size,greater<int>());
}
int get()
{
	pop_heap(heap+1,heap+1+heap_size,greater<int>());
	return heap[heap_size--];
}
int main()
{
	freopen("fruit.in","r",stdin);
	freopen("fruit.out","w",stdout);
	cin>>m;
	for(int i=1;i<=m;i++)
	 {
	 	int x;
	 	cin>>x;
	 	put(x);
	 }
	for(int i=1;i<=m-1;i++)
	 {
	 	int x=0;
	 	for(int j=1;j<=2;j++)
	 	{
	 		x+=get();
	 	}
	 	total+=x;
	 	put(x);
	 }
	cout<<total;
	return 0;
}
