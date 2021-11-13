#include<bits/stdc++.h>
using namespace std;
int a,b,c;
template <class T>
void read(T &x)
{
	char c;int sign=1;
	while((c=getchar())>'9'||c<'0') if(c=='-') sign=-1; x=c-48;
	while((c=getchar())>='0'&&c<='9') x=(x<<1)+(x<<3)+c-48; x*=sign;
}

int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	read(a);read(b);read(c);
	cout<<a*0.2+b*0.3+c*0.5<<endl;
	return 0;
}
