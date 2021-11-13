#include<bits/stdc++.h>
using namespace std;

const int oo=1047483647;

int pow_10[16]={1,10,100,1000,10000,100000,1000000,10000000,100000000};
int a[1024];

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);

	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	while(q--){
		int len,num;
		scanf("%d%d",&len,&num);
		if(len>8){
			printf("-1\n");
			return 0;
		}
		int ans=oo;
		for(int i=0;i<n;i++){
			if(a[i]%pow_10[len]==num){
				if(a[i]<ans){
					ans=a[i];
				}
			}
		}
		printf("%d\n",ans==oo ? -1 : ans);
	}

	return 0;
}


/*#include<bits/stdc++.h>
using namespace std;

int go[10000][10],node_num=0,root;
bool endd[10000];

void ins(int data)
{
	int now=root,cha;
	while(data){
		cha=data%10;
		data/=10;
		if(!go[now][cha]) go[now][cha]=++node_num;
		now=go[now][cha];
	}
	endd[now]=1;
}

int ans[10],pos;
int search(int data)
{
	int now=root;
	pos=0;
	while(data){
		int cha=data%10;
		data/=10;
		if(!go[now][cha]) return -1;
		ans[pos++]=cha;
		now=go[now][cha];
	}
	return now;
}

void find_min(int tmp)
{
	int now=tmp;
	while(1){
		for(int i=0;i<=9;i++){
			if(endd[now]) return;
			if(go[now][i]){
				ans[pos++]=i;
				now=go[now][i];
				continue;
			}
		}
		break;
	}
}

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);

	root=++node_num;
	int num;
	for(int i=1;i<=n;i++){
		scanf("%d",&num);
		ins(num);
	}

	for(int i=1;i<=q;i++){
		scanf("%*d%d",&num);
		int re=search(num);
		if(re==-1){
			printf("-1\n");
		}else{
			find_min(re);
			while(pos){
				printf("%d",ans[--pos]);
			}
			printf("\n");
		}
	}
	return 0;
}*/