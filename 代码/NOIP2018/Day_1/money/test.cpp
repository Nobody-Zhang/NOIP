#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;
int main()
{
	for(int i=1;i<=50;i++)
	{
		system("F:\\编程\\代码\\NOIP2018\\Day_1\\money\\random.exe");
		double st=clock();
		system("F:\\编程\\代码\\NOIP2018\\Day_1\\money\\money.exe");
		double ed=clock();
		system("F:\\编程\\代码\\NOIP2018\\Day_1\\money\\bf.exe");
		if(system("fc F:\\编程\\代码\\NOIP2018\\Day_1\\money\\money.out F:\\编程\\代码\\NOIP2018\\Day_1\\money\\money.ans"))
		 {
		 	puts("WA");
			getchar();
		 	return 0;
		 }
		else
		 printf("测试点%d AC 用时%0.lfms\n",i,ed-st);
	}
	getchar();
	return 0;
}
