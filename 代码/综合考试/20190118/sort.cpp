#include<bits/stdc++.h>
using namespace std;
int m,n,ans[20001],many;
void print()
{
	for(int i=1;i<=ans[0];i++)
	 cout<<ans[i]<<" ";
	exit(0);
}
void dfs(int last)
{//ǰ���ʾ�Ӽ���ʼ��������ĵڶ��ٸ� 
	if(many<=0)
	 print();
	for(int i=last+1;i<=m;i++)
	 {
	 	ans[0]++;
	 	ans[ans[0]]=i;
	 	many--;
	 	dfs(i);
		ans[0]--;
	 }
	return;
}
int main()
{
	scanf("%d%d",&m,&n);
	if(n==0||n==1) {
		cout<<"0"<<endl;
		return 0;
	}
	int tmp=n-1;
	int inc=1;
	for(int i=m-1;i>=0;i--)
	{
		if(tmp<=0) 
		{
			tmp+=pow(2,i+1);//�ָ�ԭ���� 
			inc--;//�Լ���ͷ���� 
			break;
		}
		tmp-=pow(2,i);
		inc++;
	}
	ans[0]++;
	ans[ans[0]]=inc;
	many=tmp-1;//��ǰΪ��һ�� 
	dfs(inc);
}
