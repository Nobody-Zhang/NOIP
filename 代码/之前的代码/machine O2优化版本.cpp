#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int n,k;//n������kʱ�� 
int in[21];//ÿ������ʱ�� 
int a[7];//�ڼ��������е��ۼ�ʱ�� 
int best=100000;//���ʱ�� 
void dfs(int q)//�ڼ������� 
{
	int max1=0,min1=999999;
	for(int i=1;i<=k;i++)
	 if(max1<a[i]) max1=a[i];  
	/*for(int i=1;i<=k;i++)
	 if(min1>a[i]) min1=a[i];*/
	if(q>n)
	 {
	 	if(max1<best) best=max1;
	 	return;
	 }
	if(max1>best) return;
	for(int i=1;i<=k;i++)
	  {
	 	 a[i]+=in[q];
	 	 dfs(q+1);
	 	 a[i]-=in[q];
	  }
}
int main()
{
	freopen("machine.in","r",stdin);
	freopen("machine.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	 cin>>in[i];
	dfs(1);
	cout<<best;
	return 0;
}
