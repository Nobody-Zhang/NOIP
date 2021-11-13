#include<bits/stdc++.h>
using namespace std;
#define maxn 1000001
#define maxm 10001 
int tot,len1,len2;
int s1[maxn],s2[maxm],fail[maxm];
void getfail()
{
	fail[0]=fail[1]=0;
	for(int i=1;i<len2;i++)
	{
		int t=fail[i];
		while(t&&s2[t]!=s2[i]) t=fail[t];
		fail[i+1]=(s1[t]==s2[i])?t+1:0;
	}
	return;
}
int kmp()
{
	int now=0,ans=0;
	for(int i=0;i<len1;i++)
	{
		while(now&&s1[i]!=s2[now]) now=fail[now];
		if(s1[i]==s2[now]) now++;
		if(now==len2)
		{
			return i+2-len2;
			now=fail[now];
			ans++;//这两句表示我还要找出现的次数 
		}
	}
	return -1;
}
void solve()
{
	getfail();
	cout<<kmp()<<endl;
}
int main()
{
	scanf("%d",&tot);
	for(int i=1;i<=tot;i++)
	{
		scanf("%d%d",&len1,&len2);
		for(int j=0;j<len1;j++)
			scanf("%d",&s1[j]);
		for(int j=0;j<len2;j++)
			scanf("%d",&s2[j]);
		solve();
	}
}
