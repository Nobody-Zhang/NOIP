#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;

int rd(int l,int r){ return (unsigned)rand()*rand()%(r-l+1)+l ;}

int main(){
	srand(time(NULL)+(long long)(new int)+990513) ;
	int n=100 , K=100 ;
	cout << n << ' ' << K << '\n' ;
	for(int i=1;i<=K;++i){
		int l=rd(1,n) , r=rd(l,n) , c=rd(1,1000000) ;
		cout << l << ' ' << r << ' ' << c << '\n' ;
	}
	return 0 ;
}
