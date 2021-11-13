#include<bits/stdc++.h>
using namespace std;
struct aaa
{
	int len,f1,f2;
}k[900005];
int m,tt,father[101],total,la;
bool cmp(const aaa &a,const aaa &b)
{
	return a.len<b.len;
}
int find(int i)
{
	if(i!=father[i]) father[i]=find(father[i]);
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
	cin>>m;
	for(int i=1;i<=m;i++)
	 father[i]=i;
	for(int i=1;i<=m;i++)
	 for(int j=1;j<=m;j++)
	  {
	  	int a;
	  	cin>>a;
	  	tt++;
	  	k[tt].len=a;
	  	k[tt].f1=i;
	  	k[tt].f2=j;
	  }
	/*while(1)
	{
		if(la==m*m) break;
		la++;
		cout<<k[la].f1<<" "<<k[la].f2<<" "<<k[la].len<<endl;
	}*/
	//cout<<endl;
	//la=0;
	sort(k+1,k+m*m+1,cmp);
	/*while(1)
	{
		if(la==m*m) break;
		la++;
		cout<<k[la].f1<<" "<<k[la].f2<<" "<<k[la].len<<endl;
	}*/
	for(int i=1;i<=m*m;i++)
	{
		int x=k[i].f1,y=k[i].f2;
		int last_1=find(x);
		int last_2=find(y);
		if(last_1==last_2) continue;
		unionn(last_1,last_2);
		total+=k[i].len;
	}
	cout<<total<<endl;
	return 0;
}
/*
4
0 4 9 21
4 0 8 17
9 8 0 16
21 17 16 0
*/
