#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<algorithm>
using namespace std;

long long rd(long long l,long long r){
	return (long long)rand()*rand()*rand()%(r-l+1)+l ;
}

int main(){
	srand(time(NULL)+(int)new int*) ;
	long long n = 50 , m=rd(1,1000000000000000000ll), K=rd(1,n*n) ;
	//n=K=4 ;
	cout << n << ' ' << m << ' ' << K << '\n' ;
	return 0 ;
}
