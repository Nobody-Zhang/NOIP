#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n , K , A[1000005] ;

int main(){
	cin >> n >> K ;
	for(int i=1;i<=K;++i){
		int l , r , c;
		cin >> l >> r >> c ;
		for(int j=l;j<=r;++j){
			A[j]=c ;
		}
	}
	for(int i=1;i<=n;++i){
		cout << A[i] << ' ';
	}
	cout << '\n' ;
	return 0;
}
