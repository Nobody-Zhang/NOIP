#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,q;
	long long h;
	cin>>q;
	h=1;
	for(n=1;n<=q;n++)
		h*=n;	
	cout<<h<<endl;
	return 0;
}
