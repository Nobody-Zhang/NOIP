#include<bits/stdc++.h>
#define N 500001 
#define INF 100000000000 
using namespace std;
typedef long long ll;
int n;  ll d,k,ans;

int now;//��ǰ���е���λ�� 
int q[N*2];//�����е�Ԫ��λ��
ll loc[N],point[N];
ll f[N];//��ʾ����ǰλ�ÿ��Դﵽ����߷� 

template <class T>
void read(T &x)
{
	char c;int sign=1;
	while((c=getchar())>'9'||c<'0') if(c=='-') sign=-1; x=c-48;
	while((c=getchar())>='0'&&c<='9') x=(x<<1)+(x<<3)+c-48; x*=sign;
}

bool check(ll g)
{
	ll maxx=0;
	ll l=max(1LL,d-g),r=d+g;//���˵� 
	f[0]=0;//������Ϊ0 
	now=0;
	
	int head=1,tail=0;
	
	for(int i=1;i<=n;++i)
	{
		f[i]=-INF;
		ll L=loc[i]-r,R=loc[i]-l;//ά�������ݼ�������
		while(now<=n&&loc[now]<=R)//��ǰ������λ�����Ҷ˵����
		{
			while(head<=tail&&f[q[tail]]<f[now]) tail--;
			q[++tail]=now++;
		}
		while(head<=tail&&loc[q[head]]<L) head++;//���� 
		
		if(head>tail) continue;//�ն��� 
		
		f[i]=f[q[head]]+point[i];
		maxx=max(maxx,f[i]);
	}
	return maxx>=k;
}

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	read(n);read(d);read(k);
	ans=INF;
	ll num=0;
	for(int i=1;i<=n;++i)
	{
		read(loc[i]);read(point[i]);
		if(point[i]>0) num+=point[i];
	}
	if(num<k)//����������������Ȼ��Ŀ��С 
	{
		cout<<-1<<endl;
		return 0;
	}
	ll l=0,r=1000000001;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(check(mid)) r=mid-1,ans=min(ans,mid);
		else l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}
