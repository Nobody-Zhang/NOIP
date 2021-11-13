#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int rd(int l,int r){
	return (long long)rand()*rand()*rand()%(r-l+1)+l ;
}

double rdDouble(double l, double r){
	return l + (double)rd(0,100000)/100000*(r-l) ;
}

int main(){
	srand(time(NULL)+(long long)new int) ;
	int n , T=2 ;
	switch (T){
		case 1:
			n=10 ;
			break ;
		case 2:
			n=100000 ;
			break ;
	}
	cout << n << '\n' ;
	for(int i=1;i<=n;++i){
		printf("%.4f ",rdDouble(0,1)) ;
	}
	cout << '\n' ;
	return 0 ;
}
