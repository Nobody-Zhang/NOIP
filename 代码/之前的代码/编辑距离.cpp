#include<bits/stdc++.h>
using namespace std;
char s1[2002],s2[2002];
int f[2002][2002];//f���������s1 i��s2 j�༭����С���� 
int main()
{
	gets(s1);
	gets(s2);
	int m=strlen(s1);
	int n=strlen(s2);
	for(int i=1;i<=m;i++)
	 f[i][0]=i;//�����ʼ�� 
	 //����s1 i���ĵ�s2 0Ҫɾȥi����ĸ 
	for(int i=1;i<=n;i++)
	 f[0][i]=i;
	 //s1 0��s2 i����i 
	for(int i=1;i<=m;i++)
	 for(int j=1;j<=n;j++)
	  if(s1[i-1]==s2[j-1]) f[i][j]=f[i-1][j-1];// 
	  else f[i][j]=min(min(f[i-1][j-1]/*�����ַ�*/,f[i-1][j]/*������ĸ*/),
	  f[i][j-1]/*ɾ����ĸ*/)+1;
	cout<<f[m][n];
	return 0;
}
