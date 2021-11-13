#include<bits/stdc++.h>
using namespace std;
int A,B,C,tot;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout); 
	scanf("%d%d%d",&A,&B,&C);
	int tot=A/5+B*3/10+C/2;
	cout<<tot;
	return 0;
}
