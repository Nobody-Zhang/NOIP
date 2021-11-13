#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
/*int qpowg(int a,int b){
	int c=1;
	for(;b;b>>=1){	
		if(b&1) c=(long long)c*a;
		a=(long long)a*a;
	}
	return c;
}*/
int qpowf(int a,int b,int p){
	int c=1;
	for(;b;b>>=1){	
		if(b&1) c=(long long)c*a%p;
		a=(long long)a*a%p;
	}
	return c;
}
int g(int x){
	if(x<2) return 0;
	int m=0,res=0;
	for(int i=2;i<=sqrt(x);i++){
		if(x%i==0){
			res+=i;
			while(x%i==0) x/=i;
		}
	}
	if(x>1) res+=x;
	return res;
}
int main(){
    freopen("func.in","r",stdin);
    freopen("func.out","w",stdout);
	int l,p,r,tot=0;
	scanf("%d%d%d",&l,&r,&p);
	for(int i=l;i<=r;i++){
		tot^=qpowf(2048,3*g(i),p);
	}
	printf("%d",tot);
	return 0;
}
