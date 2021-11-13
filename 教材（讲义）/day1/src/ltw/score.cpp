#include<cstdio>
using namespace std;

int a,b,c;

int main()
{
	freopen ("score.in","r",stdin);
	freopen ("score.out","w",stdout);
	scanf ("%d%d%d",&a,&b,&c);
	printf ("%d",(a/10*2)+(b/10*3)+(c/10*5));
	return 0;
}
