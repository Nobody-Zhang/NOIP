#include<bits/stdc++.h>
using namespace std;
const int MaxN=3e5+5;
const long long MOD=1e9+7;
template<class T> void read(T &re);

struct node{
	long long square_val,val,add,mul;
	node *lc,*rc;
	node(){lc=NULL;rc=NULL;}
	void mul_range(long long mul_val,int L,int R)
	{
		this->mul=(this->mul*mul_val)%MOD;
		this->add=(this->add*mul_val)%MOD;
		this->val=(this->val*mul_val)%MOD;
		this->square_val=(((this->square_val*mul_val)%MOD)*mul_val)%MOD;
	}
	void add_range(long long add_val,int L,int R)
	{
		this->square_val=( (this->square_val + (((2*(this->val))%MOD)*add_val)%MOD )%MOD + (((R-L+1)*add_val)%MOD*add_val)%MOD )%MOD;
		this->val=(this->val+(add_val*((R-L+1)%MOD))%MOD)%MOD;
		this->add=(this->add+add_val)%MOD;
	}
	void push_down(int L,int R)
	{
		if(this->mul!=1){
			int mid=(L+R)>>1;
			this->lc->mul_range(this->mul,L,mid);
			this->rc->mul_range(this->mul,mid+1,R);
			this->mul=1;
		}
		if(this->add!=0){
			int mid=(L+R)>>1;
			this->lc->add_range(this->add,L,mid);
			this->rc->add_range(this->add,mid+1,R);
			this->add=0;
		}
	}
	void update()
	{
		this->val=(this->lc->val + this->rc->val)%MOD;
		this->square_val=(this->lc->square_val + this->rc->square_val)%MOD;
	}
}pool[MaxN*2],*tmp=pool,*root;

node *build(int L,int R)
{
	node *no=++tmp;
	no->add=0;
	no->mul=1;
	if(L==R){
		read(no->val);
		no->square_val=(no->val)*(no->val)%MOD;
		return no;
	}
	int mid=(L+R)>>1;
	no->lc=build(L,mid);
	no->rc=build(mid+1,R);
	no->update();
	return no;
}

void modify_range(node * &no,int &aim_L,int &aim_R,long long &add_val,int L,int R)
{
	if(aim_L<=L && R<=aim_R){
		no->add_range(add_val,L,R);
		return;
	}
	no->push_down(L,R);
	int mid=(L+R)>>1;
	if(aim_L<=mid) modify_range(no->lc,aim_L,aim_R,add_val,L,mid);
	if(mid <aim_R) modify_range(no->rc,aim_L,aim_R,add_val,mid+1,R);
	no->update();
}

void multiply_range(node * &no,int &aim_L,int &aim_R,long long &mul_val,int L,int R)
{
	if(aim_L<=L && R<=aim_R){
		no->mul_range(mul_val,L,R);
		return;
	}
	no->push_down(L,R);
	int mid=(L+R)>>1;
	if(aim_L<=mid) multiply_range(no->lc,aim_L,aim_R,mul_val,L,mid);
	if(mid <aim_R) multiply_range(no->rc,aim_L,aim_R,mul_val,mid+1,R);
	no->update();
}

long long query_range(node * &no,int &aim_L,int &aim_R,int L,int R)
{
	if(aim_L<=L && R<=aim_R)
		return no->square_val;
	no->push_down(L,R);
	int mid=(L+R)>>1;
	long long re=0;
	if(aim_L<=mid) re=(re+query_range(no->lc,aim_L,aim_R,L,mid))%MOD;
	if(mid <aim_R) re=(re+query_range(no->rc,aim_L,aim_R,mid+1,R))%MOD;
	return re;
}

int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int n,q;
	read(n);read(q);
	root=build(1,n);

	int sign,L,R;
	long long value;
	while(q--){
		read(sign);
		if(sign==1){
			read(L);read(R);read(value);
			modify_range(root,L,R,value,1,n);
		}
		else if(sign==2){
			read(L);read(R);read(value);
			multiply_range(root,L,R,value,1,n);
		}
		else{
			read(L);read(R);
			printf("%lld\n",query_range(root,L,R,1,n));
		}
	}
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
