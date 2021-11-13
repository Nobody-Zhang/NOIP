#include<bits/stdc++.h>
using namespace std;
int tt;
struct aaa
{
	int len,f1,f2;
}k[9905];
int n,e;
int w[101][101];
int father[101],all;
int find(int i)
{
	if(father[i]!=i) father[i]=find(father[i]);
	return father[i];
}
int how[9905][3];
int cmp(const aaa &a,const aaa &b)
{
	return a.len<b.len;
}
void unionn(int i,int j)
{
	i=find(i);
	j=find(j);
	father[i]=j;
}
int main()
{
	cin>>n;
	e=n;
	for(int i=1;i<=n;i++)
	 father[i]=i;
	for(int i=1;i<=e;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		k[i].f1=x;
		k[i].f2=y;
		k[i].len=z;
		w[x][y]=z;
	}
	sort(k+1,k+1+e,cmp);
	/*for(int i=1;i<=e;i++)
	 cout<<k[i].len<<" ";*/
	for(int i=1;i<=e;i++)
	{
		int x=k[i].f1,y=k[i].f2,z=k[i].len;
		int last_1=find(x);
		int last_2=find(y);
		if(last_1==last_2) continue;
		 unionn(last_1,last_2);
		tt+=z;
		all++;
		how[all][1]=x;
		how[all][2]=y;
	}
	for(int i=1;i<=all;i++)
	 {
	 	if(how[i][1]>how[i][2]) swap(how[i][1],how[i][2]);
	 	for(int j=i;j<=all;j++)
	 	 {
	 	 	if(how[i][1]>how[j][1]||(how[i][1]==how[j][1]&&how[i][2]>how[j][2]))
	 	 	{
	 	 		swap(how[i][1],how[j][1]);
	 	 		swap(how[i][2],how[j][2]);
	 	 	}
	 	 }
	 }
	/*for(int i=1;i<=all;i++)
	 cout<<how[i][1]<<" "<<how[i][2]<<endl;*/
	cout<<tt<<endl;
	return 0;
}
/*
5 8
1 2 2
2 5 9
5 4 7
4 1 10
1 3 12
4 3 6
5 3 3
2 3 8
*/
