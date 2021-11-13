#include <cstdio>
#define input(x) freopen(x,"r",stdin)
#define output(x) freopen(x,"w",stdout)

int main()
{
	input("score.in");
	output("score.out");
	double a,b,c;
	
	scanf("%lf%lf%lf",&a,&b,&c);
	
	printf("%.0lf",a*0.2+b*0.3+c*0.5);
	return 0;
}
