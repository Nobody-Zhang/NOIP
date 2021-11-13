#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[4][6],j,i,max=0;
	double yw=0,sx=0,wy=0,q=0,w=0,e=0,r=0,t=0,p,o;
	for(i=1;i<=3;i++)
		for(j=1;j<=5;j++)
		{
			scanf("%d",&a[i][j]);//输入数据 
			if(a[i][j]>max)
				max=a[i][j];//最大值
				
			switch (i)
				{
				case 1:yw+=a[i][j];break;
				case 2:sx+=a[i][j];break;
				case 3:wy+=a[i][j];break;
				default:break;
				}
			switch (j)
				{
				case 1:q+=a[i][j];break;
				case 2:w+=a[i][j];break;
				case 3:e+=a[i][j];break;
				case 4:r+=a[i][j];break;
				case 5:t+=a[i][j];break;
				default:break;
				}
		}
	yw/=5*1.0; sx/=5*1.0; wy/=5*1.0; q/=3*1.0; w/=3*1.0;
	e/=3*1.0; r/=3*1.0;t/=3*1.0;
		printf("%.2lf %.2lf %.2lf",yw,sx,wy);
		printf("\n");
		printf("%.2lf %.2lf %.2lf %.2lf %.2lf",q,w,e,r,t);
		printf("\n");
		printf("max=%d",max);
		return 0; 
	
}
