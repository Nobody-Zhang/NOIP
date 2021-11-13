#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

int rd(int l,int r){
	return (unsigned)rand()*rand()%(r-l+1)+l ;
}

const int MAXN=100005 ;
int A[MAXN] ;
map <long long, bool> mp ;

int main(){
	srand(time(NULL)+(long long)new int) ;
	int n , m , T=3 ;
	switch (T){
		case 1:
			n=10;
			m=10;
			break ;
		case 2:
			n=1500 ;
			m=rd(1,5000) ;
			break ;
		case 3:
			n=100000 ;
			m=rd(1,300000) ;
			break ;
	}
	cout << n << ' ' << m << '\n' ;
	for(int i=1;i<=n;++i)
		cout << (char)rd('a','c') ;
	cout << '\n' ;
	for(int i=1;i<=m;++i){
		int a=rd(1,n-1) , b=rd(a+1,n) ;
		cout << a << ' ' << b << '\n' ;
	}
	return 0 ;
}
