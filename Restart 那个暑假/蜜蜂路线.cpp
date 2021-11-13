#include<bits/stdc++.h>
using namespace std;
long long mp[5][1000];//当前位置只能是-1和-2开始
void add(int x,int y,int z)//高精度加法
{//y是上一个，z是上上那个
	for(int i=0;i<=999;i++)
		mp[x][i]=0;
	for(int i=1;i<=mp[y][0];i++)
	{
		mp[x][i]=mp[x][i]+mp[y][i]+mp[z][i];
		if(mp[x][i]>=10){
			mp[x][i+1]+=1;
			mp[x][i]-=10;
		}
	}
	if(mp[x][mp[y][0]+1]) mp[x][0]=mp[y][0]+1;
	else mp[x][0]=mp[y][0];
	return;
}
void print(int x)
{
	for(int i=mp[x][0];i>=1;i--)
		printf("%d",mp[x][i]);
	return;
}
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);//从m到n
	mp[m%3][1]=1,mp[m%3][0]=1;
	for(int i=m+1;i<=n;i++)
		add(i%3,(i+2)%3,(i+1)%3);
	print(n%3);
	return 0;
}