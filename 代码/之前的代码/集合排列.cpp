#include<bits/stdc++.h>
using namespace std;
long long n,r;
long long as[100001];
long long used[100001];//�Ѿ��ù��� 
long long total;//�ܹ������� 
void pr()//��ӡ
{
	for(int i=1;i<=r;i++)
	 {
	 	cout<<as[i]<<" ";
	 	total++;
	 }
	cout<<"\n";
} 
void dfs(int j)//j�ǵڼ��� 
{
	if(j>r)
	 {
	 	pr();
	 	return ;
	 }
	for(int i=1;i<=n;i++)
	if(used[i]==0)
	{
		as[j]=i;
		used[i]=1;
		dfs(j+1);
		used[i]=0;
		
	}
}
int main()
{
	cout<<"����������n��r";//n�Ƕ��ٸ�r��ѡ���ٸ�
	cin>>n>>r;
	dfs(1);
	return 0;
}
