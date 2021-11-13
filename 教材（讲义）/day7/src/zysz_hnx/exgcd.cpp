#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int a,b,c,x,y;
/*long long gcd(long long a,long long b,long long &x,long long &y)
{
    if(!b){
    	x=1,y=0;return a;
    }
    long long d=gcd(b,a%b,x,y);
    long long z=x;x=y;y=z-y*(a/b);
    return d;
    
}*/
int main(){
    freopen("exgcd.in","r",stdin);
    freopen("exgcd.out","w",stdout);
	int a,b;
    int n;
    scanf("%d",&n);
while(n--){
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=b;i++){
		int x=i;
		if(a*x%b==c){
			printf("%d\n",x);
			break;
		}
		if(i==b) printf("no\n");	
	  }
	}
    return 0;
} 
