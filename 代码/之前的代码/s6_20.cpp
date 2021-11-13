#include<bits/stdc++.h>
using namespace std;
int tree[10005];
int main()
{
	int l,m,x,y,c=0;
	cin>>l>>m;
	for(int o=0;o<=l;o++)
	 tree[o]=1;
	for(int o=1;o<=m;o++)
	 {
	 	cin>>x>>y;
	 	for(int p=x;p<=y;p++)
	 	 tree[p]=0;
	 }
	 for(int o=0;o<=l;o++)
	  if(tree[o]!=0)
	  c++;
	  cout<<c;
	return 0;
}
