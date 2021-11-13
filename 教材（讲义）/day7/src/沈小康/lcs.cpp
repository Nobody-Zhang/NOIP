#include<bits/stdc++.h>
#define N 10005
using namespace std;
int n,m;
int f[2][N];
char a[N],b[N];

template <class T>
void read(T &x)
{
	char c;int sign=1;
	while((c=getchar())>'9'||c<'0') if(c=='-') sign=-1; x=c-48;
	while((c=getchar())>='0'&&c<='9') x=(x<<1)+(x<<3)+c-48; x*=sign;
}

int main()
{
	freopen("lcs.in","r",stdin);
	freopen("lcs.out","w",stdout);
	read(n);read(m);
	cin>>a+1;
	cin>>b+1;
	for(int i=1;i<=n;++i)
	{
		int nowi=i&1,lasti=nowi^1;
		for(int j=1;j<=m;++j)
		{
			f[nowi][j]=max(f[nowi][j-1],f[lasti][j]);
			if(a[i]==b[j]) f[nowi][j]=f[lasti][j-1]+1;
		}
		
	}
	cout<<f[n&1][m]<<endl;
	return 0;
}
/*
5 6
abdac
adabac
*/
