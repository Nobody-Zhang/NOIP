#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100005;
int bl[N],c[N];
struct data{
	int l,r,id;
	bool operator < (const data &rhs)const{
		return bl[l]==bl[rhs.l]?(r<rhs.r):bl[l]<bl[rhs.l];
	}
}a[N];
long long n,m,sqrtn,num[N],tmp,ans[N];
template<class T>inline void read(T &res){
	static char ch;T flag=1;
	while((ch=getchar())<'0'||ch>'9')if(ch=='-')flag=-1;res=ch-48;
	while((ch=getchar())>='0'&&ch<='9')res=res*10+ch-48;res*=flag;
}
void update(int x,int d){
	if(d==1){
		num[c[x]]++;
		if(num[c[x]]==2)tmp-=c[x];
		else if(num[c[x]]==3)tmp+=3*c[x];
		else tmp+=c[x];
	}else{
		num[c[x]]--;
		if(num[c[x]]==2)tmp-=3*c[x];
		else if(num[c[x]]==1)tmp+=c[x];
		else tmp-=c[x];
	}
}
int main(){
	freopen("abnormal.in","r",stdin);
	freopen("abnormal.out","w",stdout);
	read(n),read(m);sqrtn=sqrt(n+5);
	for(register int i=1;i<=n;i++)bl[i]=(i-1)/sqrtn+1,read(c[i]);
	for(register int i=1;i<=m;i++)
		read(a[i].l),read(a[i].r),a[i].id=i;
	sort(a+1,a+1+m);
	int l=a[1].l,r=a[1].l;
	update(l,1);
	for(register int i=1;i<=m;i++){
		int lt=a[i].l,rt=a[i].r;
		while(rt<r)update(r--,0);
		while(lt>l)update(l++,0);
		while(rt>r)update(++r,1);
		while(lt<l)update(--l,1);
		ans[a[i].id]=tmp;
	}
	for(register int i=1;i<=m;i++)cout<<ans[i]<<endl;
	return 0;
}
