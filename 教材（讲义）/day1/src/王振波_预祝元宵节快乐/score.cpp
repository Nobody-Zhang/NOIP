#include<cstdio>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	double a,b,c,s=0;
	scanf("%lf%lf%lf",&a,&b,&c);
	s=0.2*a+0.3*b+0.5*c;
	printf("%0.0lf",s);
	return 0;
}
