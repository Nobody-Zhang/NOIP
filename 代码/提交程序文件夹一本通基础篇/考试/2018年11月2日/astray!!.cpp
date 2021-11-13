#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int ax[101],ay[101];//可能到达的位置 
int bx[101],by[101];//可能到达的位置 
int x_1,x_2,y_1,y2,h1,h2;
int xx_1,xx_2,yy_1,yy2;
int js;
double maxx;
double len(int x,int y,int xx,int yy)
{
	return sqrt(pow(x-xx,2)+pow(y-yy,2));
}
void in()
{
	cin>>x_1>>y_1>>h1;
	xx_1=x_1,yy_1=y_1;
	for(int i=1;i<=h1;i++)
	 {
	 	int k1;
	 	char k2;
	 	cin>>k1>>k2;//前是每个的位置后面是哪个方向 
	 	if(k2=='X') xx_1+=k1;
	 	if(k2=='Y') yy_1+=k1;
	 	ax[i]=xx_1;
	 	ay[i]=yy_1;
	 }
	cin>>x_2>>y2>>h2;
	xx_2=x_2,yy2=y2;
	for(int i=1;i<=h2;i++)
	 {
	 	int k1;
	 	char k2;
	 	cin>>k1>>k2;//前是每个的位置后面是哪个方向 
	 	if(k2=='X') xx_2+=k1;
	 	if(k2=='Y') yy2+=k1;
	 	bx[i]=xx_2;
	 	by[i]=yy2;
	 }
}
void cmp()
{
	int jishu1=0,jishu2=0;
	double leng=4000.01;
	while(1)
	{
		maxx=min(leng,maxx);
		if(xx_1==x_1&&xx_2==x_2&&yy_1==y_1&&yy2==y2)
		{
			js++;
			if(js==2)
			 return;
		}
		jishu1++;
		jishu2++;
		if(jishu1>h1) jishu1=1;
		if(jishu2>h2) jishu2=1;
		leng=len(ax[jishu1],ay[jishu1],bx[jishu2],by[jishu2]);
	}
}
int main()
{
	//freopen("astray.in","r",stdin);
	//freopen("astray.out","w",stdout);
	maxx=4000.01;
	in();
	xx_2=x_2,yy2=y2;
	xx_1=x_1,yy_1=y_1;
	cmp();
	printf("%.2lf",maxx);
	return 0;
}
