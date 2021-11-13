#include<cstdio>
#include<iostream>
using namespace std;

 int d;
int l,r;


inline int getys(int a){
	if(a==1) return 0;
	int ans=0;
	bool vis=false;
	for(int i=2;i*i<=a;i++){
		if(a%i==0){
			vis=true;
			 ans+=i;
			 if(i*i!=a){	
			 ans+=(a/i);
			 
	
			 }
			while(a%i==0) a/=i;
		}
		
	} 
	if(!vis) ans=1;
	
	return ans;
}                 
long long int temp;
inline int quickpow(int a,int b){
	if(b==0) return a;
	int ans=1;
	temp=a;
	while(b){
	
		if(b&1) ans=ans*temp%d;
		
		temp=temp*temp%d;
		b>>=1; 
	}
	
	return ans%d;
}
int main(){
	
	freopen("func.in","r",stdin);
	freopen("func.out","w",stdout);
	scanf("%d%d%d",&l,&r,&d);

	
	int ans;
	int cs;
		cs=quickpow(3,getys(l));
		ans=quickpow(2048,cs);
	for(int i=l+1;i<=r;i++){
		cs=quickpow(3,getys(i));
		ans^=quickpow(2048,cs);
		
	}
	
	cout<<ans;
	
	
	return 0;
}
