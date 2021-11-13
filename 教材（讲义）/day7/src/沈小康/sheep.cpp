#include<bits/stdc++.h>
#define N 100005
#define M 1005
using namespace std;
int T,n,m;
int nxt[N];
double f[N];

template <class T>
void read(T &x)
{
	char c;int sign=1;
	while((c=getchar())>'9'||c<'0') if(c=='-') sign=-1; x=c-48;
	while((c=getchar())>='0'&&c<='9') x=(x<<1)+(x<<3)+c-48; x*=sign;
}

int main()
{
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	read(T);
	while(T--)
	{
		read(n);read(m);
		for(int i=0;i<n;++i) nxt[i]=i;
		memset(f,0,sizeof(f));
		for(int i=1;i<=m;++i)
		{
			int x,y;
			read(x);read(y);
			nxt[x]=y;
		}
		for(int i=n-1;i>=0;--i)
		{
			if(nxt[i]!=i) f[i]=f[nxt[i]];
			else 
			{
				for(int j=1;j<=6;++j) f[i]+=f[i+j]/6;
				f[i]++;
			}
		}
		cout<<fixed<<setprecision(2)<<f[0]<<endl;
	}
	return 0;
}
/*
2
2 0
8 3
2 4
4 5
7 8
*/

