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
	int n , T=3 ;
	switch (T){
		case 1:
			n=300 ;
			break ;
		case 2:
			n=1000 ;
			break ;
		case 3:
			n=100000 ;
			break ;
	}
	cout << n << '\n' ;
	for(int i=1;i<=n;++i) A[i]=i ;		
	random_shuffle(A+1, A+n+1) ;
	for(int i=1;i<=n;++i) cout << A[i] << ' ';
	cout << '\n'; 
	random_shuffle(A+1, A+n+1) ;
	for(int i=1;i<=n;++i) cout << A[i] << ' ';
	cout << '\n'; 
	return 0 ;
}
