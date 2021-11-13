#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int rd(int l,int r){
	return (unsigned)rand()*rand()%(r-l+1)+l ;
}

int main(){
	srand(time(NULL)+(long long)new int) ;
	int n, m, T=2 ;
	switch (T){
		case 1:
			n=1000 ;
			m=1000 ;
			break ;
		case 2:
			n=100000 ;
			m=100000 ;
			break ;
		case 3:
			break ;
	}
	cout << n << ' ' << m << '\n' ;
	int INF=1000000000 ;
	for(int i=1;i<=n;++i) cout << rd(1,INF) << ' ';
	cout << '\n' ;
	for(int i=1;i<=m;++i){
		int op=rd(1,3) ;
		int l=rd(1,n) , r=rd(l,n) ;
		if(op==1){
			cout << op << ' ' << l << ' ' << r << ' ' << rd(1,INF) << '\n' ;
		}
		else if(op==2){
			cout << op << ' ' << l << ' ' << r << ' ' << rd(1,INF) << '\n' ;
		}
		else if(op==3){
			cout << op << ' ' << l << ' ' << r << '\n' ;
		}
	}
	return 0 ;
}
