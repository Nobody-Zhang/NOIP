#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<ctime>
#define SF scanf
#define PF printf
#define MAXN 100000
#define MAXV 100000
using namespace std;
int get_rand(int x){
	return 1ll*rand()*rand()*rand()*rand()%x+1;	
}
int main(){
	srand(time(0));	
	int n=MAXN;
	PF("%d\n",n);
	for(int i=1;i<=n;i++){
		int xr=get_rand(2*MAXV-1)+1;	
		int yr=get_rand(2*MAXV-1)+1;
		int xl=get_rand(xr-1);
		int yl=get_rand(yr-1);
		xr-=MAXV;
		yr-=MAXV;
		xl-=MAXV;
		yl-=MAXV;
		PF("%d %d %d %d\n",xl,yl,xr,yr);
	}
}
