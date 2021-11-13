#include<bits/stdc++.h>
using namespace std;
int m,ans[500],maxx,every;
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
Wint& operator*=(Wint &a,const Wint &b)
{
	return a=a*b;
}
int judge()
{
	int tmp=0;
	for(int i=2;i;i++)
	{
		tmp+=i;
		if(tmp>m)
		{
			tmp-=i;
			maxx=tmp;
			return i-2;
		}
	}
}
int main()
{
	freopen("maxmul.in","r",stdin);
	freopen("maxmul.out","w",stdout);
	Wint ansans=1;
	scanf("%d",&m);
	int len=judge();
	maxx=m-maxx;//这里 
	every=maxx/len;//每个平均加上多少 
	int sing=maxx%len;
	for(int i=1;i<=len;i++)
	 ans[i]=i+1+every;
	int t=len+1;
	while(sing!=0)
	{
		sing--,t--;
		ans[t]++;
	}
	for(int i=1;i<=len-1;i++)
	 {
	 	printf("%d ",ans[i]);
	 	ansans*=ans[i];
	 }
	printf("%d",ans[len]);
	ansans*=ans[len];
	printf("\n");
	cout<<ansans;
	return 0; 
}
