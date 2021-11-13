#include<stdio.h>
#include<algorithm>
#define N 1007
using namespace std;

int a[N],n,q,len[N],num[N];
inline int qpow(int a,int b){
	if(b==0) return 1;
	if(b==1) return a;
	int t=qpow(a,b>>1);
	t*=t;
	if(b&1) t*=a;
	return t;
}
inline bool check(int i,int j){
	int rest=a[j]-num[i];
	if(rest%qpow(10,len[i])) return false;
	return true;
}
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=q;i++) scanf("%d%d",&len[i],&num[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=q;i++){
		bool flag=false;
		for(int j=1;j<=n;j++)
			if(check(i,j)){
				printf("%d\n",a[j]);
				flag=true;
				break;
			}
		if(!flag) printf("-1\n");
	}
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
2 12
*/
