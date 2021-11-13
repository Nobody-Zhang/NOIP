#include<cstdio>
#include<iostream>
using namespace std;

long long int n,m;
long long int arr[13];

long long int gcd(long long int a,long long int b){
	if(b==0) return a;
   	return gcd(b,a%b); 
}
long long int lcm(long long int a,long long int b){
	return a*b/gcd(a,b);
}


long long int t;
void subset(int x){
	int cnt=0;
	long long int b=1;
	
	for(int i=0;i<n;i++){
		if((x>>i)&1==1){	
		   cnt++;
		   b=lcm(b,arr[i]);
		}
		
	}
	if(cnt&1) t-=(m/b); 
	else t+=(m/b);
}

int main(){
	
	freopen("not.in","r",stdin);
	freopen("not.out","w",stdout);
	scanf("%I64d%I64d",&n,&m);
	t=m;
	for(int j=0;j<n;j++){
		scanf("%I64d",&arr[j]);
	}
	for(int i=1;i<(1<<n);i++){
		subset(i);
	}
	cout<<t;
	
	
	
	
	return 0;
}
