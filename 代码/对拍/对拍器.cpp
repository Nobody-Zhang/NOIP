#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;
int main()
{
	for(int t=1;t<=50;t++)
	 {
	 	system("F:\\���\\����\\����\\random.exe");
	 	double st=clock();
	 	system("F:\\���\\����\\����\\sol.exe");
	 	double ed=clock();
	 	system("F:\\���\\����\\����\\bf.exe");
	 	if(system("fc F:\\���\\����\\����\\data.out F:\\���\\����\\����\\data.ans")){
	 		puts("WA");
	 		getchar();
	 		return 0;
	 	}
	 	else{
	 		printf("AC	���Ե�#%d	��ʱ%.0lfms\n",t,ed-st);
	 	}
	 }
	 getchar();
}  
