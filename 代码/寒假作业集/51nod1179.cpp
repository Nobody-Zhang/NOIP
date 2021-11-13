#include<bits/stdc++.h>
using namespace std;
#define maxn 50000
#define maxin 1000000
int num[maxn],n,inc[maxin],maxx,from;
void f()
{
	for(int i=1;i<=n;i++){
		int m=num[i];
		for(int j=1;j*j<=m;j++)
		if(m%j==0){
			inc[m/j]++;
			inc[j]++;
		}
	}
	for(int i=maxx;i>=1;i--){
		if(inc[i]>=2){
			printf("%d",i);
			break; 
		}
	}
	exit(0);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
		//inc[num[i]]++;
		maxx=max(maxx,num[i]);
	}
	sort(num+1,num+n+1);
	from=1;
	if(maxx>1000) f();
	for(int i=1;i<=maxx;i++)
	{
		for(int j=from;j<=n;j++){
			if(num[j]%i==0){
				inc[i]++;
				inc[num[j]/i]++;
			}
		}
	}
	for(int i=maxx;i>=1;i--){
		if(inc[i]>=2){
			printf("%d",i);
			break; 
		}
	}
	return 0;
}
