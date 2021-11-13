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
	int n , K , T=1 ;
	switch (T){
		case 1:
			n=18 ;
			break ;
		case 2:
			n=200 ;
			break ;
		case 3:
			n=1000 ;
			break ;
	}
	K=rd(1,n) ;
	cout << n << ' ' << K << '\n' ;
	for(int i=2;i<=n;++i){
		cout << i << ' ' << rd(1,i-1) << '\n' ;
	}
	return 0 ;
}
