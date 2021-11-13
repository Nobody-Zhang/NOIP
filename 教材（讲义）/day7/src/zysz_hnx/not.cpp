#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,x,ans;
bool v[1000000000];
int main(){
	freopen("not.in","r",stdin);
    freopen("not.out","w",stdout);
	scanf("%d%d",&n,&m);
	while(n--){
		scanf("%d",&x);
		for(int i=x;i<=m;i+=x){
		  if(v[i]) continue;
		  else v[i]=true,ans++;
		}
	}
	cout<<m-ans;
	return 0;
}
