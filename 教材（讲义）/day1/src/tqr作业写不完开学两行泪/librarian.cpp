#include<bits/stdc++.h>
using namespace std;

int n,q;

struct book
{
	int ma,len;
}a[1005];

struct people
{
	int ne,len;
}b[1005];

int LEN(int ma)
{
	int x=ma;
	int len=0;
	while (x)
	{
		x/=10;
		len++;
	}
	return len;
}

int ten(int n)//10^n
{
	int ans=1;
	for (int i=1;i<=n;i++) ans*=10;
	return ans;
}

bool cmp (book x,book y) {return x.ma<y.ma;}

template<class T> inline void read(T &re)
{
	re=0;T sign=1;char tmp;
	while((tmp=getchar())&&(tmp<'0'||tmp>'9')) if(tmp=='-') sign=-1;re=tmp-'0';
	while((tmp=getchar())&&(tmp>='0'&&tmp<='9')) re=re*10+(tmp-'0');re*=sign;
}

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	read(n);read(q);
	for (int i=1;i<=n;i++)
	{
		read(a[i].ma);
		a[i].len=LEN(a[i].ma);
	}
	for (int i=1;i<=q;i++)
	{
		read(b[i].len);
		read(b[i].ne);
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=q;i++)
	{
		bool flag=0;
		for (int j=1;j<=n;j++)
		{
			if (a[j].len>=b[i].len&&a[j].ma%ten(b[i].len)==b[i].ne)//位数足够且满足
			{
				printf("%d\n",a[j].ma);
				flag=1;
				break;
			}
		}
		if (!flag) printf("-1\n");
		continue;
	}

	// for (int i=1;i<=n;i++)
	// 	cout<<a[i].ma<<" ";
	// cout<<endl;
	// for (int i=1;i<=n;i++)
	// 	cout<<a[i].len<<" ";

	return 0;

	// cin>>n;
	// cout<<LEN(n);
}