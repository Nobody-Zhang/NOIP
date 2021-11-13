#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define N 300005
int n,m;
int point[N],maxx;
queue<int>q;
struct s{
	int data,last;
}edge[N];
int inc,indegree[N],head[N],mp[N],ans[N][30];
void add(int a,int b)
{
	inc++;
	edge[inc].last=head[a];
	edge[inc].data=b;
	head[a]=inc;
	return;
}
void topo()
{
	for(int i=1;i<=n;i++)
	 if(indegree[i]==0)
	   {
	   	ans[i][point[i]]++;
	   	q.push(i);
	   }
	int tmp;
	while(!q.empty())
	{
		tmp=q.front();
		q.pop();
		for(int i=head[tmp];i;i=edge[i].last)
		{
			int now=edge[i].data;
			indegree[now]--;
			if(indegree[now]<0){
				cout<<"-1"<<endl;
				exit(0);//就是重复选取了表示有环 
			}
			for(int j=1;j<=26;j++)
			 if(j!=point[now])
			  ans[now][j]=max(ans[now][j],ans[tmp][j]);
			 else
			  ans[now][j]=max(ans[now][j],ans[tmp][j]+1);
			if(indegree[now]==0) 
			 q.push(now);
		}
	}
}
int main()
{
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	//scanf("%d%d",&n,&m);
	//getchar();
	string str;
	cin>>n>>m>>str;
	for(int i=0;i<str.length();i++)
	 point[i+1]=str[i]-'a'+1;
	/*for(int i=1;i<=n;i++)
	 {
	 	char c;
	 	scanf("%c",&c);
	 	point[i]=c-'a'+1;
	 }*/
	for(int i=1;i<=m;i++)
	 {
	 	int a,b;
	 	scanf("%d%d",&a,&b);
	 	indegree[b]++;
	 	add(a,b);
	 }
	topo();
	for(int i=1;i<=n;i++)
	 {
	 	bool flag=false;
	 	for(int j=1;j<=26;j++)
	 	 {
	 	 	if(ans[i][j]!=0) flag=true;
	 	 	maxx=max(maxx,ans[i][j]);
	 	 }
	 	if(!flag) {
	 		cout<<"-1"<<endl;
	 		exit(0);
	 	}
	 }
	 cout<<maxx<<endl;
	 return 0;
}
