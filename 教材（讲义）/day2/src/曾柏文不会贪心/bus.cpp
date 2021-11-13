#include<bits/stdc++.h>

using namespace std;

int read()
{
    int x=0,f=1;char ch=getchar();
    while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
    while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
    return x*f;
}

int n,m,t[505],mem[505][505];

int solve(int i,int st)
{
    if (i==n+1)
        return 0;
    if (st<t[i])
        return solve(i,t[i]);
    if (mem[i][st-t[i]])
        return mem[i][st-t[i]];
    int sum=0,j=i;
    while (j<=n && t[j]<=st)
        sum+=t[j++];
    int best=st*(j-i)-sum+solve(j,st+m); 
    for (;j<=n;j++)
    {
        sum+=t[j];
        best=min(t[j]*(j-i+1)-sum+solve(j+1,t[j]+m),best);
    }
    return mem[i][st-t[i]]=best;
}

int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
    n=read(),m=read();
    for (int i=1;i<=n;i++)
        t[i]=read();
    sort(t+1,t+n+1);
    cout << solve(1,0) << endl;
    return 0;
}
