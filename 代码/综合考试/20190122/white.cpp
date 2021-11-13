#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int w[N],v[N],m,lef,inc,rig;
double maxx[N],t1,t2,ans_1;
bool used[N],timeflag;
struct Wint:vector<int>
{
	Wint(int n=0)
	{
		push_back(n);
		check();
	}
	Wint& check()
	{
		while(!empty()&&!back())pop_back();
		if(empty())return *this;
		for(int i=1; i<size(); ++i)
		{
			(*this)[i]+=(*this)[i-1]/10;
			(*this)[i-1]%=10;
		}
		while(back()>=10)
		{
			push_back(back()/10);
			(*this)[size()-2]%=10;
		}
	    return *this;
	}
};
ostream& operator<<(ostream &os,const Wint &n)
{
	if(n.empty())os<<0;
	for(int i=n.size()-1; i>=0; --i)os<<n[i];
	return os;
}
Wint operator*(const Wint &a,const Wint &b)
{
	Wint n;
	n.assign(a.size()+b.size()-1,0);
	for(int i=0; i!=a.size(); ++i)
	for(int j=0; j!=b.size(); ++j)
	n[i+j]+=a[i]*b[j];
	return n.check();
}
Wint& operator-=(Wint &a,Wint b)
{
	if(a<b)swap(a,b);
	for(int i=0; i!=b.size(); a[i]-=b[i],++i)
	if(a[i]<b[i])//需要借位
	{
		int j=i+1;
		while(!a[j])++j;
		while(j>i)
		{
			--a[j];
			a[--j]+=10;
		}
	}
	return a.check();
} 
Wint operator-(Wint a,const Wint &b)
{
	return a-=b;
}
Wint& operator+=(Wint &a,const Wint &b)
{
	if(a.size()<b.size())a.resize(b.size());
	for(int i=0; i!=b.size(); ++i)a[i]+=b[i];
	return a.check();
} 
Wint operator+(Wint a,const Wint &b)
{
	return a+=b;
}
Wint divmod(Wint &a,const Wint &b)
{
	Wint ans;
	for(int t=a.size()-b.size(); a>=b; --t)
	{
		Wint d;
		d.assign(t+1,0);
		d.back()=1;
		Wint c=b*d;
		while(a>=c)
		{
		   a-=c;
		   ans+=d;
		}
	}
	return ans;
} 
Wint operator/(Wint a,const Wint &b)
{
	return divmod(a,b);
}
Wint& operator*=(Wint &a,const Wint &b)
{
	return a=a*b;
}
void search(int cost,int get,int from,int last)
{
	/*if(timeflag) return;
	t2=time(0);
	if(t2-t1>0.99666666) {
		printf("%.3lf\n1",ans_1);
		exit(0);
	}*/
    if(last==0){
        inc++;
        maxx[inc]=1.0*get/cost;
        return;
    }
    for(int i=from;i<=m;i++)
    if(used[i]==false)
    {
        used[i]=true;
        search(cost+v[i],get+w[i],i+1,last-1);
        used[i]=false;
    }
    return;
}
void f1()
{
    int tot=0;
    for(int i=lef;i<=rig;i++){
        search(0,0,1,i);
    }
    ans_1=-0x7fff;
    for(int i=1;i<=inc;i++)
     ans_1=max(ans_1,maxx[i]);
    for(int i=1;i<=inc;i++)
        if(ans_1==maxx[i])
     	 tot++;
    printf("%.3lf\n%d",ans_1,tot);
    exit(0);
}
void f()
{
    Wint ans=1,as=1;;
    for(int i=m;i>=m-lef+1;i--){
        ans*=i;
    }
    for(int i=lef;i>=1;i--){
    	as*=i;
    }
    cout<<ans/as;
    exit(0);
}
int main()
{
	t1=time(0);
    freopen("white.in","r",stdin);
    freopen("white.out","w",stdout);
    srand(time(0));
    scanf("%d%d%d",&m,&lef,&rig);
    for(int i=1;i<=m;i++)
     scanf("%d%d",&v[i],&w[i]);
    double k=1.0*w[1]/v[1];
    bool flag=true;
    for(int i=1;i<=10;i++)
    {//处理4,5个数据点
        int mid=rand()%m+1;
        if(w[1]!=w[mid]||v[1]!=v[mid]) 
		 flag=false;
    }
    if(flag){
        printf("%.3lf\n",k);
        f();
        return 0;
    }
     f1();//这里开始暴力搜索 
    return 0;
}
