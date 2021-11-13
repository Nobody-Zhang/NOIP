#include <cstdio>
#include <algorithm>
#define input(x) freopen(x,"r",stdin)
#define output(x) freopen(x,"w",stdout)

int book[1005];

int power(int a,int b)
{
	int ret=1;
	for(;b;b>>=1)
	{
		if(b&1) ret*=a;
		a*=a;
	}
	
	return ret;
}

int main()
{
	input("librarian.in");
	output("librarian.out");
	int n,q;
	
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",&book[i]);
	
	std::stable_sort(book+1,book+n+1);
	while(q--)
	{
		int len,code,p=-1;
		
		scanf("%d%d",&len,&code);
		
		for(int i=1;i<=n;i++)
			if(book[i]%power(10,len)==code)
			{
				p=book[i];
				break;
			}
		
		printf("%d\n",p);
	}
	
	return 0;
}
