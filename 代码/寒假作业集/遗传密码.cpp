#include<bits/stdc++.h>
using namespace std;
int m,deg[1001],fa[1001],point[1001],ans;
bool tag[10001];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]); 
}
//int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main()
{
	//freopen("�Ŵ�����.in","r",stdin);
	cin>>m;
	for(int i=1;i<=1000;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		deg[a]++;point[a]=1;
		deg[b]--;point[b]=1;
		fa[find(a)]=find(b);//��ͨ�� 
	}
	for(int i=1;i<=1000;i++)
		if(point[i]==1&&deg[i]!=0){
			tag[find(i)]=true;
			ans+=abs(deg[i]);
		}  
	ans/=2;
	for(int i=1;i<=1000;i++)
		if(point[i]==1&&find(i)==i&&tag[i]==false){
			ans++;//�����и���ͨ�������ŷ����· 
		}
	ans+=m;
	cout<<ans<<endl;
	return 0;
}
