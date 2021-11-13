#include<bits/stdc++.h>
using namespace std;
struct t{
	int data,last;
}tr[200];
int head[10],tmp,in[35],can[10],imp,m;//imp非常重要是第一位 
bool inc[10],notfir[10];
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
void add(int a,int b)
{//将b连接到a上面 
	tmp++;
	tr[tmp].data=b;
	tr[tmp].last=head[a];
	head[a]=tmp;
	return;
}
string s;
void dfs(int u,int papa)
{
	for(int i=head[u];i;i=tr[i].last)
	{
		int now=tr[i].data;
		if(now==papa||inc[now]==true) continue;//处理是一个环的情况 
		can[papa]++;
		inc[now]=true;
		if(now==0) notfir[papa]=true;
		dfs(now,papa);
	}
	return;
}
int main()
{
	freopen("build.in","r",stdin);
	freopen("build.out","w",stdout);
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++)
	 {
	 	in[i+1]=s[i]-'0';
	 	//num[in[i+1]]++;
	 }
	cin>>m;
	for(int i=1;i<=m;i++)
	 {
	 	int a,b;
	 	cin>>a>>b;
	 	add(a,b);
	 }
	imp=in[1];
	for(int i=0;i<=9;i++)
	 {
	 	memset(inc,false,sizeof(inc));//清除标记 
	 	dfs(i,i);
	 	can[i]++;//自己可以变成自己 
	 }
	Wint ans;
	if(notfir[imp]==true)//代表第一位可以为0
	 {
	 	ans=can[imp]-1;
	 } 
	else{
		ans=can[imp];
	}
	//if(ans==0) ans=1;
	for(int i=2;i<=len;i++)
	 {
	 	int now=in[i];
	 	if(can[now]==0) continue;
	 	ans*=can[now];
	 }
	 cout<<ans<<endl;
	 return 0;
}
