#include<bits/stdc++.h>
using namespace std;
int w[31],c[31],a[11][32],f[201],m,v,n;
int main()
{
	cin>>v>>n>>m;//v������n���� 
	for(int i=1;i<=n;i++)
	{
		int p;
		cin>>w[i]>>c[i]>>p;
		a[p][++a[p][0]]=i;
		//����a[p][0]�ǵڼ���ĸ��� 
		//a[p][1~a[p][0]�ǵڼ������� 
	}
	for(int i=1;i<=m;i++)
	 for(int k=v;k>=0;k--)
	  for(int j=1;j<=a[i][0];j++)//ö�ٸ��� 
	   //������������֮��ö�٣���֤ÿ�������� 
	   //����ֻ��һ�� 
	   if(w[a[k][j]]<=k)
	   //for(int k=v;k>=w[a[k][j]];k--)
	   {
	   	int tmp=a[i][j];
	   	f[k]=max(f[k],f[k-w[tmp]]+c[tmp]);
	   }
	cout<<f[v];
	return 0;
}
/*
10 6 3
2 1 1
3 3 1
4 8 2
6 9 2
2 8 3
3 9 3
*/
