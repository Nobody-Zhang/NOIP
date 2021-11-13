#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;
int main()
{
	for(int t=1;t<=50;t++)
	 {
	 	system("F:\\编程\\代码\\对拍\\random.exe");
	 	double st=clock();
	 	system("F:\\编程\\代码\\对拍\\sol.exe");
	 	double ed=clock();
	 	system("F:\\编程\\代码\\对拍\\bf.exe");
	 	if(system("fc F:\\编程\\代码\\对拍\\data.out F:\\编程\\代码\\对拍\\data.ans")){
	 		puts("WA");
	 		getchar();
	 		return 0;
	 	}
	 	else{
	 		printf("AC	测试点#%d	用时%.0lfms\n",t,ed-st);
	 	}
	 }
	 getchar();
}  
