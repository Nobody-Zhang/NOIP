#include<bits/stdc++.h>
#define N 501
#define INF 2000000000 
using namespace std;
int n,m;
int t[N];
int f[N][N*2];//��i���Լ���j����ʱ ǰi���ܹ��ĵȴ�ʱ�� 

template <class T>
void read(T &x)
{
	char c;int sign=1;
	while((c=getchar())>'9'||c<'0') if(c=='-') sign=-1; x=c-48;
	while((c=getchar())>='0'&&c<='9') x=(x<<1)+(x<<3)+c-48; x*=sign;
}

int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;++i) read(t[i]);
	sort(t+1,t+n+1);
	memset(f,100,sizeof(f));
	for(int i=0;i<=2*n;++i) f[1][i]=i;
	
	
	for(int i=2;i<=n;++i)
	{
		for(int j=0;j<=2*m;++j)
		{
			int temp=t[i]-t[i-1]+j;//��һ�˵ȴ�ʱ�� 
			if(temp<=2*m) f[i][j]=min(f[i][j],f[i-1][temp]+j);//i-1��iһ����
			int wait=INF;
			for(int k=0;k<=min(2*m,temp-m);++k)//i-1��i�������� 
			{
				wait=min(wait,f[i-1][k]);
			}
			f[i][j]=min(f[i][j],wait+j);
		}
	}
	int ans=INF;
	for(int i=0;i<=2*m;++i) ans=min(ans,f[n][i]);
	cout<<ans<<endl;
	return 0;
}
