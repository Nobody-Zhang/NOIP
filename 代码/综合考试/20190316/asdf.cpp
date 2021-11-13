#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("rotinv.in","w",stdout);
	srand(time(0));
	int tmp=5000;
	printf("%d\n",tmp);
	for(int i=1;i<=tmp;i++)
	{
		printf("%d ",(rand()%5000+1));
	}
	return 0;
}
