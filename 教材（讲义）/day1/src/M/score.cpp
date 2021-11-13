#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int _homework,_exam,_final;
	scanf("%d%d%d",&_homework,&_exam,&_final);
	printf("%d\n",(int)((_homework/10)*2+(_exam/10)*3)+(_final/10)*5);
	return 0;
}