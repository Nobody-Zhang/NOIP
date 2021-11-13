#include<bits/stdc++.h>
const int MaxN=1000001;
using namespace std;
template<class T> void read(T &re);

int n;
int l[MaxN],r[MaxN],val[MaxN];//左右儿子
int size[MaxN];//子树大小

void init(int rt)
{
	size[rt]=1;
	if(l[rt]!=-1){
		init(l[rt]);
		size[rt]+=size[l[rt]];
	}
	if(r[rt]!=-1){
		init(r[rt]);
		size[rt]+=size[r[rt]];
	}
}

bool dfs(int ll,int rr)
{
	if(ll==-1&&rr==-1) return 1;//没节点
	else if(ll==-1||rr==-1) return 0;//有一边有
	else if(val[ll]==val[rr]) return dfs(l[ll],r[rr])&&dfs(r[ll],l[rr]);
	//都有
	else return 0;
}

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	read(n);

	for(int i=1;i<=n;++i) read(val[i]);
	for(int i=1;i<=n;++i) read(l[i]),read(r[i]);

	init(1);
	int ans=0;
	for(int i=1;i<=n;++i){
		if(dfs(l[i],r[i])) ans=max(ans,size[i]);
	}
	printf("%d\n",ans);
}

template<class T> void read(T &re)
{
	re=0;
	T sign=1;
	char tmp;
	while((tmp=getchar())&&(tmp<'0'||tmp>'9')) if(tmp=='-') sign=-1;
	re=tmp-'0';
	while((tmp=getchar())&&(tmp>='0'&&tmp<='9')) re=re*10+(tmp-'0');
	re*=sign;
}


/*#include<bits/stdc++.h>
using namespace std;
const int MaxN=1e3+5;
template<class T> void read(T &re);

struct data{
	int v,numb,L,R,pre_num,pre_end,anti_pre_num,anti_pre_end;
	data *lc,*rc;
	data(){v=0;lc=NULL;rc=NULL;}
}node[MaxN],*root=&node[1];

int cnt;

int ino[MaxN];
void in_order(data *no)
{
	if(no->lc!=NULL){
		in_order(no->lc);
		no->L=no->lc->L;
	}
	no->numb=++cnt;
	ino[cnt]=no->v;
	if(no->rc!=NULL){
		in_order(no->rc);
		no->R=no->rc->R;
	}

	if(no->lc==NULL) no->L=no->numb;
	if(no->rc==NULL) no->R=no->numb;
}

int pre[MaxN];
void pre_order(data *no)
{
	no->pre_num=++cnt;
	pre[cnt]=no->v;
	if(no->lc!=NULL){
		pre_order(no->lc);
	}
	if(no->rc!=NULL){
		pre_order(no->rc);
	}
	no->pre_end=cnt;
	//printf("%d ",no->pre_end);
}

//
// void tpre_order(data *no)
// {
// 	printf("%d ",no->pre_num);
// 	printf("%d \n",no->pre_end);
// 	if(no->lc!=NULL){
// 		tpre_order(no->lc);
// 	}
// 	if(no->rc!=NULL){
// 		tpre_order(no->rc);
// 	}
// }
//

int anti_pre[MaxN];
void anti_pre_order(data *no)
{
	no->anti_pre_num=++cnt;
	anti_pre[cnt]=no->v;
	if(no->rc!=NULL){
		anti_pre_order(no->rc);
	}
	if(no->lc!=NULL){
		anti_pre_order(no->lc);
	}
	no->anti_pre_end=cnt;
	//printf("%d ",no->anti_pre_end);
}

//
// void tanti_pre_order(data *no)
// {
// 	printf("%d ",no->anti_pre_num);
// 	printf("%d \n",no->anti_pre_end);
// 	if(no->rc!=NULL){
// 		tanti_pre_order(no->rc);
// 	}
// 	if(no->lc!=NULL){
// 		tanti_pre_order(no->lc);
// 	}
// }
//

bool judge(data *rt)
{
	if((rt->numb - rt->L +1)!=(rt->R-rt->numb+1)) return 0;
	for(int i=0; rt->L+i < rt->numb ;i++)
		if(ino[rt->L+i]!=ino[rt->R-i]) return 0;
	if(rt->lc!=NULL&&rt->rc!=NULL){
		for(int i=rt->lc->pre_num,j=rt->rc->anti_pre_num;i<=rt->lc->pre_end&&j<=rt->rc->anti_pre_end;i++,j++){
			if(pre[i]!=anti_pre[j]) return 0;
		}
	}
	return 1;
}

int ans=0;
void dfs(data *no)
{
	if(judge(no)){
		ans=max(ans,no->R-no->L+1);
		return;
	}
	if(no->lc!=NULL) dfs(no->lc);
	if(no->rc!=NULL) dfs(no->rc);
}

int main()
{
	// freopen("tree.in","r",stdin);
	// freopen("tree.out","w",stdout);
	int n,tlc,trc;
	read(n);
	for(int i=1;i<=n;i++)
		read(node[i].v);
	for(int i=1;i<=n;i++){
		read(tlc);read(trc);
		if(tlc!=-1) node[i].lc=&node[tlc];
		if(trc!=-1) node[i].rc=&node[trc];
	}

	cnt=0;
	in_order(root);
	cnt=0;
	pre_order(root);
	cnt=0;
	anti_pre_order(root);

	// printf("\n");
	// tpre_order(root);
	// printf("\n");
	// tanti_pre_order(root);
	// printf("\n");

	// //
	// printf("\n\npre:\n");
	// for(int i=1;i<=n;i++)
	// 	printf("%d ",pre[i]);
	// printf("\n");
	// printf("anti_pre:\n");
	// for(int i=1;i<=n;i++)
	// 	printf("%d ",anti_pre[i]);
	// printf("\n\n");
	// //

	dfs(root);

	printf("%d\n",ans);

	return 0;
}

template<class T> void read(T &re)
{
	re=0;
	T sign=1;
	char tmp;
	while((tmp=getchar())&&(tmp<'0'||tmp>'9')) if(tmp=='-') sign=-1;
	re=tmp-'0';
	while((tmp=getchar())&&(tmp>='0'&&tmp<='9')) re=re*10+(tmp-'0');
	re*=sign;
}
*/