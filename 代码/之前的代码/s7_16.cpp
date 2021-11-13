#include<bits/stdc++.h>
using namespace std;
const int maxn=2000000+5;
char name[maxn][25],s[25];
int search(int a,int b)
{
	int mid=(a+b)/2;
	if(strcmp(s,name[mid])==0) return mid;
	else if(strcmp(s,name[mid])>0) return search(mid+1,b);
	else return search(a,mid-1);
}
int main()
{
	int u,v;
	scanf("%d",&u);
	for(int i=1;i<=u;i++)
	 scanf("%s",&name[i]);
	scanf("%d",&v);
	for(int i=1;i<=v;i++)
	 {
	 	scanf("%s",s);
	 	printf("%d\n",search(1,u));
	 }
	 return 0;
}
