#include<bits/stdc++.h>
using namespace std;
char s1[2002],s2[2002];
int f[2002][2002];//f用来储存从s1 i到s2 j编辑的最小距离 
int main()
{
	gets(s1);
	gets(s2);
	int m=strlen(s1);
	int n=strlen(s2);
	for(int i=1;i<=m;i++)
	 f[i][0]=i;//将其初始化 
	 //就是s1 i更改到s2 0要删去i个字母 
	for(int i=1;i<=n;i++)
	 f[0][i]=i;
	 //s1 0到s2 i加上i 
	for(int i=1;i<=m;i++)
	 for(int j=1;j<=n;j++)
	  if(s1[i-1]==s2[j-1]) f[i][j]=f[i-1][j-1];// 
	  else f[i][j]=min(min(f[i-1][j-1]/*更改字符*/,f[i-1][j]/*插入字母*/),
	  f[i][j-1]/*删除字母*/)+1;
	cout<<f[m][n];
	return 0;
}
