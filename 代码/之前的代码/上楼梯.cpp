#include<bits/stdc++.h>
using namespace std;
int way[102],total=0;
void print(int s)
{
	for(int i=1;i<=s;i++)
	 printf("%d",way[i]);
	printf("\n");total++;
}
void search(int s1,int n1)
{
	if(n1==0)
	 {
	 	print(s1);
	 	return;
	 }
	 way[s1+1]=1;
	 search(s1+1,n1-1);
	 if(n1>1)
	 {
	 	way[s1+1]=2;
	 	search(s1+1,n1-2);
	 }
}
int main()
{
	int n;
	scanf("%d",&n);
	search(0,n);
	printf("%d\n",total);
	return 0;
}
