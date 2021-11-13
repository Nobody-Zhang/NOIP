#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

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

inline int lenf(int len){
	int ansb=10;
	for(int i=2;i<=len;i++)ansb*=10;
	return ansb;
}

int n,q;
int book[1002],num,len;
int ans=-1;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	read(n);read(q);
	for(int i=1;i<=n;i++)read(book[i]);
	while(q--){
		read(len);read(num);ans=-1;
		for(int i=1;i<=n;i++){
			if(book[i]%lenf(len)==num)
				ans=(ans==-1?book[i]:min(ans,book[i]));
		}
		if(ans==-1)
		{printf("-1\n");continue;}
		print(ans);putchar('\n');
	}
}
/*
5 5
2123
1123
23
24
24
2 23
3 123
3 124
2 12
2 12

*/
