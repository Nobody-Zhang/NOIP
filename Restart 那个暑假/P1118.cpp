#include<bits/stdc++.h>
using namespace std;
int C[100][100],tot,n,sum,answer[100];
void yanghui()
{
	C[1][1]=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			C[i][j]=C[i-1][j-1]+C[i-1][j];
		}
	/*for(int i=1;i<=x;i++){
		for(int j=1;j<=i;j++){
			cout<<C[i][j]<<" ";
	}
		}
		cout<<endl;*/
	}//用来检验杨辉三角是不是正确的
}
void dfs(int x)
{
	for(int i=1;i<=sum;i++){
		tot+=i*C[n][x];//tot是现在的总和，
		if(tot>=sum){
			tot-=i*C[n][x];
			return;
		}
		answer[x]=i;
		if(n==x&&tot==sum){
			for(int j=1;j<=n-1;j++){
				printf("%d ",answer[j]);
			}
			printf("%d",answer[n]);
			exit(0);
		}
		dfs(x+1);
		tot-=i*C[n][x];
	}
}
int main()
{
	scanf("%d%d",&n,&sum);
	yanghui();
	dfs(1);
	return 0;
}