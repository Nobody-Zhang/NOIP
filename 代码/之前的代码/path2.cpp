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
         g[i]=m[j][i]+g[j];//�������ֵС�ڵ�ǰ�����g[i]�������g[i] 
         path[i]=j;//�µ�g[i]ֵ�Ǿ�����j������, ��˵�i����һ���ǵ�j
      }
  }
  printf("%d\n",g[7]);
  //������Ž��·�� 
  print(7);
 
  return 0;
}

