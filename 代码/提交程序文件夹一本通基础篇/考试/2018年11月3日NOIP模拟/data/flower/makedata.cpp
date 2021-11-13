#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<ctime>
#define SF scanf
#define PF printf
#define MAXL 100000
#define MAXS 100000
#define DELTA 200
using namespace std;
int get_rand(int x){
	return rand()*rand()%x+1;	
}
int main(){
	srand(time(0));
	int t=5;
	PF("%d\n",t);
	while(t--)
		PF("%d %d\n",MAXL-get_rand(DELTA),get_rand(MAXS));
}
