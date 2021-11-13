#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int rd(int l,int r){
	return (long long)rand()*rand()*rand()%(r-l+1)+l ;
}

int jmp[100005] ;
int main(){
	srand(time(NULL)+(long long)new int) ;
	int cases=10, maxn, m, T=2 ; //T勿取1
	switch (T){
		case 1:
			maxn=10 ;
			m=0 ;
			break ;
		case 2:
			maxn=100000 ;
			m=0 ;
			break ;
		case 3:
			maxn=100000 ;
			m=1000 ;
			break ;
	}
	cout << cases << '\n' ;
	while(cases--){
		memset(jmp,0,sizeof(jmp)) ;
		int n=rd(maxn-1000,maxn) ;
		cout << n << ' ' << m << '\n' ;
		for(int i=1;i<=m;++i){
			int a=rd(1,n), b=min(rd(a+1,a+100),n) ;
			if(jmp[a]) { --i; continue ; }
			jmp[a]=b ;
			cout << a << ' ' << b << '\n' ;
		}
	}
	return 0 ;
}
