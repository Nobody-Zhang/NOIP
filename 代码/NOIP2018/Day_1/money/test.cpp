#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;
int main()
{
	for(int i=1;i<=50;i++)
	{
		system("F:\\���\\����\\NOIP2018\\Day_1\\money\\random.exe");
		double st=clock();
		system("F:\\���\\����\\NOIP2018\\Day_1\\money\\money.exe");
		double ed=clock();
		system("F:\\���\\����\\NOIP2018\\Day_1\\money\\bf.exe");
		if(system("fc F:\\���\\����\\NOIP2018\\Day_1\\money\\money.out F:\\���\\����\\NOIP2018\\Day_1\\money\\money.ans"))
		 {
		 	puts("WA");
			getchar();
		 	return 0;
		 }
		else
		 printf("���Ե�%d AC ��ʱ%0.lfms\n",i,ed-st);
	}
	getchar();
	return 0;
}
