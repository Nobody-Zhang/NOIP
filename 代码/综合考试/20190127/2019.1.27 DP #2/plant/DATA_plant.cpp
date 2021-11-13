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
	int n, m, T=3 ;
	switch (T){
		case 1:
			n=5 ;
			m=5 ;
			break ;
		case 2:
			n=rd(9,10) ;
			m=10 ;
			break ;
		case 3:
			n=rd(11,12) ;
			m=12 ;
			break ;
	}
	cout << n << ' ' << m << '\n' ;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			int t=rd(1,15) ;
			if(t==1) t=0;
			else t=1 ;
			cout << t << ' ';
		}
		cout << '\n' ;
	}
	return 0 ;
}
