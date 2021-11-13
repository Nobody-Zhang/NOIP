#include<bits/stdc++.h>
using namespace std;
int tree[1<<20];
int ans,d,i,p;
void chuli(){
    p=1;
	for(int t=2;t<=d;t++)
	{
		if(tree[p]==0)
		tree[p]=1,p=p*2;
	     else
		tree[p]=0,p=p*2+1;
	}
}
int main()
{
//	freopen("drop.in","r",stdin);
//	freopen("drop.out","w",stdout);
	scanf("%d%d",&d,&i);
	for(int t=1;t<=i;t++)
	chuli();
	printf("%d",p);
}
