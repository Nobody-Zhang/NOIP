#include<bits/stdc++.h>
using namespace std;
int f[20001],v[31],m,n;
int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	 cin>>v[i];
	for(int i=1;i<=n;i++)
	 for(int j=m;j>=v[i];j--)
	  f[j]=max(f[j],f[j-v[i]]+v[i]);
	cout<<m-f[m];
	return 0;
}
/*#include<stdio.h>
int f[20005];
int max(int a,int b)
{
  if (a>b) return a;
  return b;
}
int v,n,x;
int main()
{
  scanf("%d%d",&v,&n);
  for (int i=1;i<=n;i++)//ö������ 
    {
       scanf("%d",&x);
       for (int j=v;j>=x;j--)
         f[j]=max(f[j],f[j-x]+x);
       //ǰi-1���������j��װ����������ѡ��i���������j��װ����� 
       //���������ѡ���� 
    }
  printf("%d",v-f[v]);
  getchar();
  getchar();
  return 0;
}
*/
