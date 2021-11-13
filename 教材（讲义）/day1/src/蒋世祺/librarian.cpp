#include<bits/stdc++.h>
using namespace std;

const int maxn=1005;
int n,q;
int cnt[10];
struct po{
	int shu,belong;
}st[10][maxn];

int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		int xx=x,w=0;
		while(xx){
			w++;
			xx/=10;
		}
		for(int i=1;i<=w;i++){
			int wei=pow(10,i);
			st[i][++cnt[i]].shu=x%wei;
			st[i][cnt[i]].belong=x;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y,ans=1e9;;
		scanf("%d%d",&x,&y);
		for(int i=1;i<=cnt[x];i++)
		  if(st[x][i].shu==y&&st[x][i].belong<ans)  ans=st[x][i].belong;
		if(ans!=1e9) printf("%d\n",ans);
		else printf("-1\n");
	}
}
/*5 5
2123
1123
23
24
24
2 23
3 123
3 124
2 12
2 12*/
