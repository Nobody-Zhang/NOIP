#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

int rd(int l,int r){
	return (long long)rand()*rand()*rand()%(r-l+1)+l ;
}

int main(){
	set<int> st ;
	
	
	srand(time(NULL)+(long long)new int) ;
	int n, K, T=4 ;
	switch (T){
		case 1:
			n=10 ;
			K=rd(2,3) ;
			break ;
		case 2:
			n=200 ;
			K=rd(5,10) ;
			break ;
		case 3:
			n=100000 ;
			K=rd(10,100) ;
			break ;
		case 4:
			n=2000000 ;
			K=rd(100,1000) ;
			break ;
	}
	cout << n << ' ' << K << '\n' ;
	const int INF=100000 ;
	for(int i=1;i<=n;++i){
		cout << rd(0,INF) << ' ' ;
	}
	cout << '\n' ;
	return 0 ;
}
