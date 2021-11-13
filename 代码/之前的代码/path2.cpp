#include<stdio.h>
const int m[10][10]={{},
                 {0, 0, 5, 2, 0, 0, 0, 0},
                 {0, 0, 0, 0, 3, 2, 0, 0},
				 {0, 0, 0, 0, 0, 7, 4, 0},
				 {0, 0, 0, 0, 0, 0, 0, 4},
				 {0, 0 ,0, 0, 0, 0, 0, 3},
				 {0, 0, 0, 0, 0, 0, 0, 5},
				 {0, 0, 0, 0, 0, 0, 0, 0}};
const int maxlen=210000000;
int g[10],path[10];
void print(int k)
{
	if (path[k]==0) {printf("%d ",k);return;	}
	print(path[k]);
	printf("%d ",k);
}
int main()
{
  g[1]=0;path[1]=0;
  for (int i=2;i<=7;i++)
  {
    g[i]=maxlen;path[i]=0; 
    for (int j=1;j<=i-1;j++)
      if (m[j][i]!=0&&m[j][i]+g[j]<g[i])
      { 
         g[i]=m[j][i]+g[j];//计算出的值小于当前保存的g[i]，则更新g[i] 
         path[i]=j;//新的g[i]值是经过点j产生的, 因此点i的上一点是点j
      }
  }
  printf("%d\n",g[7]);
  //输出最优解的路径 
  print(7);
 
  return 0;
}

