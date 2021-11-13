#include<cstdio>
#include<iostream>
using namespace std;

int n,m;
typedef long long ll;
int gcd(int a,int b){
	if(b==0) return a;
   	return gcd(b,a%b); 
}

void exgcd(int a,int b,int &x,int &y,int &c){
	if(!b){
		y=0; x=1;c=a;
		return;
	}
	c=gcd(a,b);
	exgcd(b,a%b,y,x,c);
	y-=a/b*x;
	
}


int t,a,b,c;

int main(){
	
	freopen("exgcd.in","r",stdin);
	freopen("exgcd.out","w",stdout);
	scanf("%d",&t);
	int x,y;
	while(t--){
		bool flag=false;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=1;i<=10000000;i++){
			if(a*i%b==c){
				cout<<i<<endl;
				flag=true;
				break;
			}
		}
		if(!flag) cout<<"no";
		
	}
	
	
	
	return 0;
}
