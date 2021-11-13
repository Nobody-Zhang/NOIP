#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int rd(int l,int r){
	return (long long)rand()*rand()*rand()%(r-l+1)+l ;
}

int main(){
	srand(time(NULL)+(long long)new int) ;
	int n, m, T=2 ;
	switch (T){
		case 1:
			n=10 ;
			m=10 ;
			break ;
		case 2:
			n=rd(6400,6666) ;
			m=rd(6400,6666) ;
			break ;
	}
	cout << n << ' ' << m << '\n' ;
	int L='a', R='z' ;
	if(T==1) R='e' ;
	for(int i=1;i<=n;++i)
		cout << (char)rd(L,R) ;
	cout << '\n' ;
	for(int i=1;i<=m;++i)
		cout << (char)rd(L,R) ;
	cout << '\n' ;
	return 0 ;
}
