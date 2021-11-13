#include<bits/stdc++.h>
using namespace std;
double dis(double x1,double y1,double x2,double y2)
{
	double ans=0;
	ans=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	return ans;
}
int main()
{
	double x1,x2,x3,y1,y2,y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	double ans=dis(x1,y1,x2,y2)+dis(x1,y1,x3,y3)+dis(x3,y3,x2,y2);
	printf("%.2lf",ans);
	return 0;
}