#include<bits/stdc++.h>
#define mod 1000000000000000000
using namespace std;
long long a0,a1,a2,b,c,d,e,n;
struct Mat
{
	long long w[5][5];
	Mat() {memset(w,0,sizeof(w));}
}x;


long long mul(long long a,long long b)
{
	long long ret=0;
	while(b)
	{
		if(b&1) { --b; ret=(ret+a)%mod; }
		else { b>>=1; a=(a+a)%mod; }
	}
	return ret;
}

Mat Mmul(Mat a,Mat b)
{
	Mat ret;
	for(int i=1;i<=4;++i)
	{
		for(int j=1;j<=4;++j)
		{
			for(int k=1;k<=4;++k)
			{
				ret.w[i][j]=(ret.w[i][j]+mul(a.w[i][k],b.w[k][j])%mod)%mod;
			}
		}
	}
	return ret;
}
Mat quickpow(Mat a,long long b)
{
	Mat ret;
	for(int i=1;i<=4;++i) ret.w[i][i]=1;
	while(b)
	{
		if(b&1) ret=Mmul(ret,a);
		a=Mmul(a,a);
		b>>=1;
	}
	return ret;
}

int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	cin>>a0>>a1>>a2>>b>>c>>d>>e>>n;
	if(n==0) {cout<<a0<<endl;return 0;}
	if(n==1) {cout<<a1<<endl;return 0;}
	if(n==2) {cout<<a2<<endl;return 0;}
	x.w[1][1]=b;x.w[2][1]=c;x.w[3][1]=d;x.w[4][1]=1;x.w[1][2]=1;x.w[2][3]=1;x.w[4][4]=1;
	Mat s=quickpow(x,n-2);
	Mat ans;
	ans.w[1][1]=a2;ans.w[1][2]=a1;ans.w[1][3]=a0;ans.w[1][4]=e;
	ans=Mmul(ans,s);
	long long anss=ans.w[1][1]%mod;
	long long t=anss,p=0;
	while(t)
	{
		++p;
		t/=10;
	}
	for(int i=1;i<=18-p;++i) cout<<0;
	if(p) cout<<anss<<endl;
	return 0;
}
