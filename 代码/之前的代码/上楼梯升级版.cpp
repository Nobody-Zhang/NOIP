#include<bits/stdc++.h>
using namespace std;
int way[102],total=0,k;
void print(int s)
{
	for(int i=1;i<=s;i++)
	 printf("%d",way[i]);
	printf("\n");total++;
}
void search(int s1,int n1)//s1 第几步，n1剩余几步 
{
	if(n1==0)
	 {
	 	print(s1);
	 	return;
	 }
	 way[s1+1]=1;
	 search(s1+1,n1-1);//解决一步 
	 for(int t=1;t<k;t++)
	 {
		if(n1>t)
	 	{
	 		way[s1+1]=t+1;
	 		search(s1+1,n1-t-1);
	 	}
	 }
}
int main()
{
	int n;
	scanf("%d%d",&n,&k);
	search(0,n);
	printf("%d\n",total);
	return 0;
}
