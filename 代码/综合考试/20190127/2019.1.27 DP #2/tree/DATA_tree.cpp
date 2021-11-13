#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int rd(int l,int r){
	return (unsigned)rand()*rand()%(r-l+1)+l ;
}

const int MAXN=100005 ;
int A[MAXN] ;

int main(){
	srand(time(NULL)+(long long)new int) ;
	int n, Q, T=3 ;
	switch (T){
		case 1:
			n=10 ;
			Q=500 ;
			break ;
		case 2:
			n=500 ;
			Q=100000 ;
			break ;
		case 3:
			n=5000 ;
			Q=100000 ;
			break ;
	}
	cout << n << ' ' << Q << '\n' ;
	for(int i=2;i<=n;++i){
		cout << i <<  ' ' << rd(1,i-1) << '\n' ;
	}
	for(int i=1;i<=n;++i){
		if(rd(1,4)==1) cout << 1 << ' ';
		else cout << 0 << ' ' ;
	}
	cout << '\n' ;
	for(int i=1;i<=Q;++i){
		int a=rd(1,n) , b=rd(1,max(a/3,5)) ;
		cout << a << ' ' << b << '\n' ;
	}
	return 0 ;
}
