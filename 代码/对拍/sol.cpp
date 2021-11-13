#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
const int maxl=-2147483648,maxr=2147483647;
//#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
//char buf[1<<21],*p1=buf,*p2=buf;
template <typename T> inline void redi(T& t)
{
	register int c=getchar();t=0;
	bool flag=false;
	if(c=='-') flag=true;
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) t=t*10+c-'0',c=getchar();
	if(flag) t=-t;
}
template <typename T,typename... Args>inline void redi(T& t,Args&... args)
{
	redi(t);
	redi(args...);
}
struct Node{
	int size;
	Node *ls,*rs;
	Node(){
		ls=rs=NULL;
		size=0;
	}
}tree[maxn*33],*root,*tail=tree;

char getChar(){
	char c ;
	while((c=getchar()) != EOF && isspace(c)) ;
	return c ;
}

int n,m,in[maxn];
/*Node *news()
{
	tail->ls=tail->rs=nul;
	return tail++;
}*/
void add(Node *(&nd),int l,int r,int x,int sum)
{
	if(!nd) nd=tail++;
	if(l==r){nd->size+=sum; return;}
	int mid=((long long)l+r)>>1;
	if(x<=mid) add(nd->ls,l,mid,x,sum);
	else add(nd->rs,mid+1,r,x,sum);
	if(nd->ls&&nd->rs) nd->size=nd->ls->size+nd->rs->size;
	else if(nd->ls) nd->size=nd->ls->size;
	else if(nd->rs) nd->size=nd->rs->size;
	return;
}
int query(Node *nd,int l,int r,int pos)
{
	if(l==r) return l;
	long long tmp=(long long)l+r;
	int mid=(tmp)>>1;
	if(nd->ls)
	{
		if(nd->ls->size>=pos) return query(nd->ls,l,mid,pos);
		else return query(nd->rs,mid+1,r,pos-nd->ls->size);
	}
	else{
		return query(nd->rs,mid+1,r,pos);
	}
}
int main()
{
	//freopen("test.in","r",stdin);
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	redi(n,m);
	//scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		//scanf("%d",&in[i]);
		redi(in[i]);
		add(root,maxl,maxr,in[i],1);
	}
	for(int i=1;i<=m;i++){
		char op = getChar() ;
		if(op=='Q'){
			int pos;
			redi(pos);
			printf("%d\n",query(root,maxl,maxr,pos));
			//cout<<query(root,maxl,maxr,pos)<<endl;
		}
		if(op=='M'){
			int a,b;
			redi(a,b);
			//scanf("%d%d",&a,&b);
			add(root,maxl,maxr,in[a],-1);
			add(root,maxl,maxr,b,1);
			in[a]=b;
		}
	}
	return 0;
}
