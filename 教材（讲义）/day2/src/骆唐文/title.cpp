#include<cstdio>
#include<cstring>
using namespace std;

char op[5001];
int len,ans;

int main()
{
	freopen ("title.in","r",stdin);
	freopen ("title.out","w",stdout);
	gets (op);
	len=strlen (op);
	ans=len;
	for (register int i=0;i<=len-1;i++)
		if (op[i]==' '||op[i]=='\n')
			ans--;
	printf ("%d",ans);
	return 0;
}
