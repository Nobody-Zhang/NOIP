#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=100000005;
int n,m;
int a[maxn];
int main(){
	freopen("not.in","r",stdin);
	freopen("not.out","w",stdout);
	scanf("%d%d",&n,&m);
	int num=m;
	for(register int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(register int i=a[1];i<=m;i++){
		for(register int j=1;j<=n;j++){
			if(a[j]>i)break;
			if(i%a[j]==0){
			num--;
			//printf("%d\n",num);
			break;
			}
			/*if(i==m)
			ans=num;
			*/
		}
	}
		printf("%d\n",num);
		return 0;
}
