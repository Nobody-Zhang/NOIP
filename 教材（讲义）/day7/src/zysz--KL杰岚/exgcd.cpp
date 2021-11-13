#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
const int maxn=100000005;
int T;
int a,b,c;
int ans[maxn];
int main(){
	freopen("exgcd.in","r",stdin);
	freopen("exgcd.out","w",stdout);
	scanf("%d",&T);
	for(register int i=1;i<=T;i++){
		scanf("%d%d%d",&a,&b,&c);
		if(c%a==0){
		ans[i]=c/a;
		}
	    else {
	    	
	    	
	    	
	    	int temp=b+c;
	    	if(temp%a==0)
	    	ans[i]=temp/a;
	    	else{
	    		for(register int j=2;j<=50;j++){
	    			int temp1=j*a;
	    			if(temp1%b==c){
	    			ans[i]=j;
					break;
					}
					if(j==50&&temp1%b!=c)
					ans[i]=0;
	    		}
	    	}
	    }   
	}
	for(int i=1;i<=T;i++){
		if(ans[i]==0){
			cout<<"no"<<endl;
		}
		else
		cout<<ans[i]<<endl;
	}
	return 0;
}
