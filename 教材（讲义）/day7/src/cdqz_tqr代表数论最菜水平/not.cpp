#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[15];

int nbgcd2(int a,int b) {return b==0 ? a:nbgcd2(b,a%b);}
int nbgcd3(int a,int b,int c) {int gc=nbgcd2(a,b);return nbgcd2(gc,c);}
int nbgcd4(int a,int b,int c,int d) {int gc=nbgcd3(a,b,c);return nbgcd2(gc,d);}
int nbgcd5(int a,int b,int c,int d,int e) {int gc=nbgcd4(a,b,c,d);return nbgcd2(gc,e);}
int nbgcd6(int a,int b,int c,int d,int e,int f) {int gc=nbgcd5(a,b,c,d,e);return nbgcd2(gc,f);}
int nbgcd7(int a,int b,int c,int d,int e,int f,int g) {int gc=nbgcd6(a,b,c,d,e,f);return nbgcd2(gc,g);}
int nbgcd8(int a,int b,int c,int d,int e,int f,int g,int h) {int gc=nbgcd7(a,b,c,d,e,f,g);return nbgcd2(gc,h);}
int nbgcd9(int a,int b,int c,int d,int e,int f,int g,int h,int i) {int gc=nbgcd8(a,b,c,d,e,f,g,h);return nbgcd2(gc,i);}
int nbgcd0(int a,int b,int c,int d,int e,int f,int g,int h,int i,int j) {int gc=nbgcd9(a,b,c,d,e,f,g,h,i);return nbgcd2(gc,j);}

template<class T> inline void read(T &re)
{
	re=0;T sign=1;char tmp;
	while((tmp=getchar())&&(tmp<'0'||tmp>'9')) if(tmp=='-') sign=-1;re=tmp-'0';
	while((tmp=getchar())&&(tmp>='0'&&tmp<='9')) re=re*10+(tmp-'0');re*=sign;
}





int main()
{
	freopen("not.in","r",stdin);
	freopen("not.out","w",stdout);

	//+1-2+3-4+5-6+7-8+9-10
	read(n);read(m);int ans=m;
	for (int i=1;i<=n;i++)
	{
		read(a[i]);
		ans-=m/a[i];
	}

	if (n>=2)
	{
		for (int i=1;i<=n-1;i++)
			for (int j=i+1;j<=n;j++)
				ans+=m/(nbgcd2(a[i],a[j])*a[i]*a[j]);
	}
	
	if (n>=3)
	{
		for (int i=1;i<=n-2;i++)
			for (int j=i+1;j<=n-1;j++)
				for (int k=j+1;k<=n;k++)
					ans-=m/((a[i]*a[j]*a[k])/(max(max(nbgcd2(a[i],a[j]),nbgcd2(a[j],a[k])),nbgcd2(a[i],a[k]))));
				ans+=1;
	}
	// cout<<((a[1]*a[2]*a[3])/(max(max(nbgcd2(a[1],a[2]),nbgcd2(a[2],a[3])),nbgcd2(a[1],a[3]))));
	printf("%d\n",ans);
	

	return 0;
}