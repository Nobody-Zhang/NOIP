#include<bits/stdc++.h>
using namespace std;
double ans=1000000005;
int pos,n;
double l,km,s;
struct point{
	int dis;
	double val;
}t[55];
void dfs(int p,double rest,double ans1)
{
	if(ans1>=ans)  return ;
	if(p>n){
		ans=ans1;return ;
	}
	double can=rest*km;
	if(t[p+1].dis-t[p].dis>can)//不能到达 
	  dfs(p+1,l-(t[p+1].dis-t[p].dis)/km,ans1+20+t[p].val*(l-rest));
	  else if(rest>=l/2)//可以到达但油箱里面油不能加 
	  	dfs(p+1,rest-(t[p+1].dis-t[p].dis)/km,ans1);
	  	 else{//可加可不加 
	  	 	dfs(p+1,l-(t[p+1].dis-t[p].dis)/km,ans1+20+t[p].val*(l-rest));
	  	    dfs(p+1,rest-(t[p+1].dis-t[p].dis)/km,ans1);
	  	 }
}
int main()
{
	freopen("tour.in","r",stdin);
	freopen("tour.out","w",stdout);
	scanf("%d%lf%lf%lf%d",&pos,&l,&km,&s,&n);
	for(int i=1;i<=n;i++)
	  scanf("%d%lf",&t[i].dis,&t[i].val);
	t[n+1].dis=pos;
	dfs(0,l,s);
	printf("%.1lf",ans);
}
