//货车载油 
#include<bits/stdc++.h>
using namespace std;
double o[1006],d[1006]; //油和距离（离终点距离）的东东
int u; 
int main()
{
	freopen("oil.out","w",stdout);
	int a=500;//最多500L油
	int b=1000; //总共100km
	o[0]=0;//终点没有任何油
	d[0]=0;//距离终点没有距离 
	o[1]=500;//倒数第一个存油点在路中央 
	d[1]=500;//这个时候距离终点可以一次走完
	//所以不用浪费
	int j=2;
	while(d[j-1]<1000.0)
	{
		o[j]=o[j-1]+500;//每次走油要加满 
		d[j]=d[j-1]+500.0/(2*j-1);
		j++;
	}
	/*for(int i=2;1;i++)//递归第n个储油点位置，
	//大于总距离的时候就完毕 
	{
		if(fabs(d[i])>1000) break;
		o[i]=o[i-1]+500;//每次走油要加满 
		d[i]=d[i-1]+500.0/(2*i-1);//每个加油点必须让下一次程的油加满？？
		//其实我也不知道为什么
		//老师讲的有点奇怪 
		u++; 
	} */
	cout<<"No. Distance Oil"<<endl;
	for(int i=j-1;i>=1;i--)//倒序输出，因为是相距终点的距离
	{
		double k=1000.0-d[i];
		//printf("   %lf   %lf   %lf\n",j-i-1,k,o[i]);
		//cout << fixed << showpoint << setprecision(15);
		if(j-i-1==7)break;
		if(j-i-1==0) cout<<" "<<"0 "<<"0.0000000000"<<" "<<o[i]<<endl;
		if(j-i-1!=0) cout<<" "<< setprecision(13)<<j-1-i<<" "<<k<<" "<<o[i]<<endl;
	} 
	cout<<" "<<"7 "<<"500.0000000000"<<" "<<"500"<<endl;
	cout<<" "<<"8 "<<"1000.0000000000"<<" "<<"0";
	return 0;
}
