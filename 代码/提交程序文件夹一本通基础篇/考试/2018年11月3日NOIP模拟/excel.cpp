//#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int n,gs;
int mp[10005][10005];
int dabiao[100005];
int maxx_x,maxx_y;
bool tp=true;
struct size_s
{
	//int size;
	int x1,x2,y1,y2;
}s[100005];
/*bool cmp(size_s a,size_s b)
{
	return a.size>b.size;
}*/
void search_mp(int l_x,int l_y,int r_x,int r_y)
{
	for(int i=l_x;i<=r_x;i++)
	 for(int j=l_y;j<=r_y;j++)
	  dabiao[mp[i][j]]=1;
	int as=0;
	for(int i=1;i<=n;i++)
	 as+=dabiao[i];
	cout<<as+1<<endl;
	return;
}
void out(int l_x,int l_y,int r_x,int r_y)
{
	for(int j=l_y;j<=r_y;j++)
	 {
	 	for(int i=l_x;i<=r_x;i++)
	 	cout<<mp[i][j]<<" ";
	 	cout<<endl;
	 }
}
void test_1()
{
	int l_x=0x7f,l_y=0x7f,r_x=0,r_y=0;
	memset(mp,0,sizeof(mp));
	for(int i=1;i<=n;i++)
	{
		for(int j=s[i].x1;j<=s[i].x2;j++)
		 for(int k=s[i].y1;k<=s[i].y2;k++)
		  {
		  	mp[j][k]=i;
		  }
		l_x=min(l_x,s[i].x1);
		l_y=min(l_y,s[i].y1);
		r_x=max(r_x,s[i].x2);
		r_y=max(r_y,s[i].y2);
		//out(0,0,9,9);
		//cout<<endl;
	}
	//cout<<l_x<<" "<<l_y<<" "<<r_x<<" "<<r_y<<endl;
	search_mp(l_x,l_y,r_x,r_y);
	//cout<<endl;
	//out(l_x,l_y,r_x,r_y);
	return;
}
int main()
{
	freopen("excel.in","r",stdin);
	freopen("excel.out","w",stdout);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	 {
	 	cin>>s[i].x1>>s[i].y1>>s[i].x2>>s[i].y2;
	 	//s[i].size=abs(s[i].x2-s[i].x1)*abs(s[i].y2-s[i].y1);
	 	if(s[i].x1<0) maxx_x=min(maxx_x,s[i].x1);
	 	if(s[i].y1<0) maxx_y=min(maxx_y,s[i].y1);
	 }
	//sort(s+1,s+n+1,cmp);
	/*for(int i=1;i<=n;i++)
	 cout<<s[i].size<<" ";*/
	maxx_x=-maxx_x;
	maxx_y=-maxx_y;
	if(maxx_x>0||maxx_y>0)
	{
		for(int i=1;i<=n;i++)
	 	 {
	 	 	s[i].x2+=maxx_x;
			s[i].x1+=maxx_x;
			s[i].y2+=maxx_y;
			s[i].y1+=maxx_y;
	 	 }
	}
	test_1();
	return 0;
}
