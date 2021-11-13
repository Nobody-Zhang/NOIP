#include<bits/stdc++.h>
#define mod 504
using namespace std;

int n,m;
int len[210];
int dp[210][210];

template<class T> inline void read(T &re)
{
	re=0;T sign=1;char tmp;
	while((tmp=getchar())&&(tmp<'0'||tmp>'9')) if(tmp=='-') sign=-1;re=tmp-'0';
	while((tmp=getchar())&&(tmp>='0'&&tmp<='9')) re=re*10+(tmp-'0');re*=sign;
}

int main()
{
	freopen("empire.in","r",stdin);
	freopen("empire.out","w",stdout);
    read(n);read(m);
    if(m>2*n-1){cout<<0;return 0;}
    for(int i=1;i<=n-1;i++) len[2*i-1]=len[2*i]=2*i-1;
    len[2*n-1]=2*n-1;
    for(int i=0;i<=2*n-1;i++) dp[i][0]=1;
    for(int i=1;i<=2*n-1;i++)
    for(int j=1;j<=len[i];j++)
    {
        dp[i][j]=dp[i-1][j]+dp[i-1][j-1]*(len[i]-j+1);
        dp[i][j]%=mod;
    }
    printf("%d",dp[2*n-1][m]);
    return 0;
}