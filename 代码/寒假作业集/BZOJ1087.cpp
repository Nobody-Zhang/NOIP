#include<bits/stdc++.h>
using namespace std;
int n,k,top,mid[100002][3],dp[10][82][1024],tmp[1024];
bool judge(int in)
{
	if((in&(in<<1))||(in&(in>>1))) return false;
	return true;
}
int get1(int in)
{
	if(tmp[in]) return tmp[in];
	int tot=0;
	int tp=in;
	while(in)
	{
		if(in&1) tot++;
		in>>=1;
	}
	return tmp[tp]=tot;
}
bool attack(int x,int y)
{
	if(((x<<1)&y)||((x>>1)&y)||(x&y)) return true;
	return false; 
}
int main()
{
	//freopen("test.in","r",stdin);
	//freopen("wa.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(k==0){
		cout<<"1"<<endl;
		return 0;
	}
	int ed=(1<<n)-1;
	for(int i=0;i<=ed;i++)
	{
		if(judge(i)){
			top++;
			mid[top][0]=i;
			mid[top][1]=get1(i);
			dp[1][get1(i)][i]=1;
		}
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=top;j++)
		{//枚举现在的情况 
			int x=mid[j][0];
			for(int v=1;v<=top;v++)
			{//枚举上一次的情况 
				int y=mid[v][0];
				if(attack(x,y)) continue;
				for(int l=0;l<=k;l++){
					dp[i][mid[j][1]+l][x]+=dp[i-1][l][y];
				}
			}
		}
	}
	long long ans=0;
//	for(int i=0;i<=ed;i++)
//		cout<<dp[n][k][i]<<" ";
//	cout<<endl;
	for(int i=0;i<=ed;i++)
		ans+=dp[n][k][i];
	printf("%lld",ans);
	return 0; 
}
