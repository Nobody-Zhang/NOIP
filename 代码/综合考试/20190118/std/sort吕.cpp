#include<stdio.h>
int n,k,a[35],now=0;
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(k==1){
		printf("0");
		return 0;
	}
	int i=1,base=0;
	int t=k;
	while(1){
		int q;
		if(t==1) break;
		t--;i=a[now]+1;
		while(base<t){
			q=1<<(n-i);
			base+=q;
			i++;
		}
		i--;base-=q;
		t-=base;
		base=0;
		a[++now]=i;
	}
	for(int i=1;i<=now;i++)
		printf("%d ",a[i]);
}
