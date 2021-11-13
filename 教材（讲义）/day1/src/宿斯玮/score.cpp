#include<bits/stdc++.h>
using namespace std;

int   m1 , m2 , m3 , ans ;

int  main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d" , &m1 , &m2 , &m3 );
	ans = m1/10*2 + m2/10*3 + m3/2 ;
	cout<<ans;
	return 0 ;
}