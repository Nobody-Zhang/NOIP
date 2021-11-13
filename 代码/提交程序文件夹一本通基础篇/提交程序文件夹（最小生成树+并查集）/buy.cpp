#include<bits/stdc++.h>
using namespace std;
int father[10001],data[10001][3],m,n,w,money[10001];
int data_second[10001][3];
bool used[10001];
int tt;
int find(int i)
{
	if(father[i]!=i) father[i]=find(father[i]);
	return father[i];
}
void unionn(int i,int j)
{
	i=find(i);
	j=find(j);
	father[i]=j;
}
int main()
{
	cin>>n>>m>>w;
	for(int i=1;i<=n;i++)
	 father[i]=i;
	for(int i=1;i<=n;i++)
	 cin>>data[i][1]>>data[i][2];
	for(int i=1;i<=m;i++)
	 {
	 	int x,y;
	 	cin>>x>>y;
	 	int f1=find(x);
	 	int f2=find(y);
	 	if(f1!=f2) unionn(f1,f2);
	 }
	for(int i=1;i<=n;i++)
	 int j=find(i);
	for(int i=1;i<=n;i++)
	{
		if(used[father[i]]==false)
		{
			tt++;
			int allmoney=0,allnice=0;
			for(int j=1;j<=n;j++)
			 if(father[j]==father[i])
			  {
			  	allmoney+=data[j][1],allnice+=data[j][2];
			  }
			data_second[tt][1]=allmoney;
			data_second[tt][2]=allnice;
			used[father[i]]=true;
		}
	}
	for(int i=1;i<=n;i++)
	 int j=find(i);
	for(int i=1;i<=tt;i++)
	 for(int j=w;j>=data_second[i][1];j--)
	  {
	  	money[j]=max(money[j-data_second[i][1]]+data_second[i][2],money[j]);
	  }
	cout<<money[w]<<endl;
	return 0;
}
/*
5 3 10
3 10
3 10
3 10
5 100
10 1
1 3
3 2
4 2
*/
