#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

int n,m,a,tot;
int w[12],id;

inline void print(int x){
	if(x>9)print(x/10);
	putchar(x%10+48);
}
inline void read(int &x){
	char s=getchar();x=0;
	while(s<'0'||s>'9')s=getchar();
	while(s>='0'&&s<='9')
	{x=(x<<1)+(x<<3)+s-'0';s=getchar();}
}

inline bool can(int x){
	for(int i=0;i<id;i++)
		if(!(x%w[i]))return false;
	return true;
}

int main(){
	freopen("not.in","r",stdin);
	freopen("not.out","w",stdout);
	read(n);read(m);tot=m;
	for(int i=1;i<=n;i++){
		read(a);
		for(int i=a;i<=m;i+=a){
			if(can(i))tot--;
		}
		w[id++]=a;
	}
	print(tot);
}
