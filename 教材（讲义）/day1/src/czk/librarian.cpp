#include<bits/stdc++.h>
using namespace std;
int a[10005],b[10005];
int n,x,y,q,z=0;
int f(int x){
	int nn=1;
	for(int i=1;i<=x;i++){
		nn*=10;
	}
	return nn;
}
int minn(){
	int m=10000000;
	for(int i=1;i<=z;i++){
		m=min(b[i],m);
	}
	return m;
}
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=q;i++){
		for(int i=1;i<=1005;i++){
			b[i]=10000000;
		}
	    z=1;
		cin>>x>>y;
		for(int j=1;j<=n;j++){
			if(a[j]%f(x)==y){
				b[z]=a[j];
				z++;
			}
		}
		if(z==1)printf("-1\n");
		else {
			int c=minn();
			cout<<c<<endl;
		}
	}
	return 0;
}
/*
5 5
2123
1123
23
24
24
2 23
3 123
3 124
2 12
2 12*/
