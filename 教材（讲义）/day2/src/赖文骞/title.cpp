#include <cstdio>
#include <cctype>
#define input(x) freopen(x,"r",stdin)
#define output(x) freopen(x,"w",stdout)

int main()
{
	input("title.in");
	output("title.out");
	int cnt=0;
	char c;
	
	while(~scanf("%c",&c))
		if(isalnum(c)) cnt++;
	
	printf("%d",cnt);
	return 0;
}
