#include<bits/stdc++.h>
using namespace std;
int n,maxx[21],len[21],ans;
string s[21];
void yes(int x,int y)
{
	for(int i=0;i<len[x];i++)
	{
		//char x1=s[x][i],x2=s[y][i];
		if(s[x][i]>s[y][i]){
			ans=x;return;
		}
		else if(s[x][i]==s[y][i]) continue;
		else return;
	}
}
int judge(int length)
{
	ans=maxx[1];
	for(int i=2;i<=maxx[0];i++)
	{
		yes(i,ans);
	}
	return ans;
}
int main()
{
	int len_max=-1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		len[i]=s[i].length();
		len_max=max(len_max,len[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(len[i]==len_max) {
			maxx[0]++;
			maxx[maxx[0]]=i;
		}
	}
	if(maxx[0]==1)
	{
		cout<<maxx[1]<<endl;
		cout<<s[maxx[1]]<<endl;
		return 0;
	}
	
	cout<<judge(len_max)<<endl;
	cout<<s[judge(len_max)]<<endl;
}