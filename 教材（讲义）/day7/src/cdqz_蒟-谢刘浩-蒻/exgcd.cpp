#include<bits/stdc++.h>

inline void read(int &x){
	char s=getchar();x=0;
	while(s<'0'||s>'9')s=getchar();
	while(s>='0'&&s<='9')
	{x=(x<<1)+(x<<3)+s-'0';s=getchar();}
}
inline void print(int x){
	if(x>9)print(x/10);
	putchar(x%10+48);
}

int w[100000002],id=0;

int main(){
	int T,a,b,c,x=0;
	freopen("exgcd.in","r",stdin);
	freopen("exgcd.out","w",stdout);
	read(T);
	while(T--){
		read(a);read(b);read(c);
		for(int i=1;i<=c;i++)w[i]=0;x=0;
		if(a%b==c){print(1);putchar('\n');continue;}
		while(++x){
			if(w[a*x%b])
			{puts("no");break;}
			if(a*x%b==c)
			{print(x);putchar('\n');break;}
			w[a*x%b]=1;
		}
	}
}
