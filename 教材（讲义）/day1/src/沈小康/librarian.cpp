#include<bits/stdc++.h>
#define N 1001
using namespace std;
int n,q;
int a[N];

template <class T>
void read(T &x)
{
	char c;int sign=1;
	while((c=getchar())>'9'||c<'0') if(c=='-') sign=-1; x=c-48;
	while((c=getchar())>='0'&&c<='9') x=(x<<1)+(x<<3)+c-48; x*=sign;
}

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	read(n);read(q);
	for(int i=1;i<=n;++i) read(a[i]);
	sort(a+1,a+n+1);
	while(q--)
	{
		int p,req;
		read(p);read(req);
		p=(int)pow(10,p);
		int ans=-1;
		for(int i=1;i<=n;++i)
		{
			if(a[i]%p==req) {ans=a[i];break;}
		}
		printf("%d\n",ans);
	}
	return 0;
}

