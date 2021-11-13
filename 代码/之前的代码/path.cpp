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
int main()
{
  g[7]=0;path[7]=0;
  for (int i=6;i>=1;i--)
  {
    g[i]=maxlen;path[i]=0; 
    for (int j=i+1;j<=7;j++)
      if (m[i][j]!=0&&m[i][j]+g[j]<g[i])
      { 
         g[i]=m[i][j]+g[j];//计算出的值小于当前保存的g[i]，则更新g[i] 
         path[i]=j;//新的g[i]值是经过点j产生的, 因此点i的上一点是点j
      }
  }
  printf("%d\n",g[1]);
  //输出最优解的路径 
  for (int i=1;path[i]!=0;)
   {
     printf("%d ",i);
     i=path[i];
   }
  printf("%d",7);
  return 0;
}

