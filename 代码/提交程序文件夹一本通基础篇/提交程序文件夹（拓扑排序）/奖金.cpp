#include<bits/stdc++.h>
using namespace std;
int f[10001];//Ա�����Եõ���Ǯ 
int r[10001];//ÿ��Ա������� 
int c[10001];//ÿ��Ա���ĳ��� 
int a[10001][301];//Ա������Щ���� 
int mp[10001][10001];
//�����С���� 
int num[10001];
int bj[10001];
stack<int> as[10001];
int tt;
int m,n,total_money;//��������Ա����������Ǯ�� 
bool tof;
void pd(int i)
{
	if(bj[i]==1) 
	{
		tof=true;
		return;
	}
	bj[i]=1;
	if(tof==true) return;
	for(int j=1;j<=c[i];j++)
	 pd(a[i][j]);
}
int main()
{
	cin>>n>>m;//����Ա������(n)��������(m) 
	for(int i=1;i<=n;i++)
	 f[i]=100;
	for(int i=1;i<=m;i++)
	{
		int more,less;
		cin>>more>>less;
		c[less]++;//Ա������++
		r[more]++;
		a[less][c[less]]=more;
		mp[more][less]=1;
		mp[less][more]=1;
	}
	for(int i=1;i<=n;i++)
	 {
		memset(bj,0,sizeof(bj));
	 	tof=false;
	 	pd(i);
	 	if(tof)
	 	{
		 	cout<<"Poor Xed"<<endl;
		 	return 0;
	  	}
	 }
	memset(bj,0,sizeof(bj));
	/*for(int i=1;i<=n;i++)
	 if(r[i]==0)
	  as[++tt]=i;*/
	for(int i=1;i<=n;i++)
	 if(r[i]==0)
	  as.push(i);
	do
	{
		int tp=as.top()
		cout<<tp<<" ";
		as.pop();
		for(int i=1;i<=c[tp];i++)
		{
			r[a[tp][i]]--;
			if(c[a[tp]]==0)
			 push(a[tp][i]);
		}while()
	}
	return 0;
}
