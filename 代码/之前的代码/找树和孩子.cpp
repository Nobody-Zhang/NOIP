#include<bits/stdc++.h>
using namespace std;
int maxx,maxp,top;
struct tree1
{
	int parent,data;
	tree1(){
		data=parent=0;
	}
};
struct tree1 tree[101];
int main()
{
	int m,n;
	cin>>m>>n;
	int in1,in2;
	for(int i=1;i<=n;i++)
	 {
	 	cin>>in1>>in2;
	 	tree[in2].parent=in1;
	 }
	for(int i=1;i<=m;i++)
	 if(tree[i].parent==0)
	  top=i;
	 else
	  tree[tree[i].parent].data++;
	cout<<top<<endl;
	for(int i=1;i<=m;i++)
	 if(maxx<tree[i].data)
	  maxx=tree[i].data,maxp=i;
	cout<<maxp<<endl;
	for(int i=1;i<=m;i++)
	 if(maxp==tree[i].parent)
	  cout<<i<<" ";
	return 0;
}
/*
8 7
4 1
4 2
1 3
1 5
2 6
2 7
2 8
*/
