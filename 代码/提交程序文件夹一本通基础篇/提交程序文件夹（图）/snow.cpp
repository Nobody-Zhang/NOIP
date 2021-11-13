#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long tmp,x,y,x1,x2,y1,y2;
	long double s=0;
	freopen("snow.in","r",stdin);
	freopen("snow.out","w",stdout);
	cin>>x>>y;
	while(cin>>x1>>y1>>x2>>y2)
	 s+=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	s=s*2/1000/20;
	int h=floor(s);
	s=(s-h)*60;
	int m=s;
	if(s-m>=0.5) m++;
	 cout<<h<<":";
	if(m<10) cout<<"0";
	 cout<<m<<endl;
	return 0;
}
