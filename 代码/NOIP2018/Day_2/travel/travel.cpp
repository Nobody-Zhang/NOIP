#include<bits/stdc++.h>
using namespace std;
int point[5005],m,n;
int lian[5005][5005],now[5005];
int mp[5005][5005];
int as[5005];
void out()
{
	for(int i=1;i<=m;i++)
	 cout<<as[i]<<" ";
	return;
}
void search(int k)
{
	for(int i=1;i<=point[k];i++)
	 {
	 	if(now[lian[k][i]]==2)
	 	 continue;
	 	now[lian[k][i]]=1;
	 }
	 return;
}
void f()
{
	if(as[0]==m) {
		out();
		return;
	}
	int tmp;
	for(int i=1;i<=m;i++)
	 if(now[i]==1)
	  {
	  	tmp=i;
	  	break;
	  }
	as[++as[0]]=tmp;
	now[tmp]=2; 
	search(tmp);
	f();
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	 {
	 	int k,j;
	 	cin>>k>>j;
	 	point[k]++;
	 	point[j]++;
	 	lian[k][point[k]]=j;
	 	lian[j][point[j]]=k;
	 }
	as[++as[0]]=1;
	for(int i=1;i<=point[1];i++)
	 now[lian[1][i]]=1;
	now[1]=2;
	f();
	return 0;
} 
