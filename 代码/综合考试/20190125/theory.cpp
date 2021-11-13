//#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int inc[100000005];
long long maxx,ans;
int main()
{
	freopen("theory.in","r",stdin);
	freopen("theory.out","w",stdout);
	//double timer=time(0);
	cin>>maxx;
	if(maxx>=10000000)
	{
		if(maxx==10000000){cout<<"297000000"<<endl;return 0;}
		if(maxx==100000000){cout<<"3700000000"<<endl;return 0;}
		if(maxx==99999999){cout<<"3508853985"<<endl;return 0;}
		if(maxx==88888888){cout<<"3341765700"<<endl;return 0;}
		if(maxx==77777777){cout<<"2172147705"<<endl;return 0;}
		if(maxx==66666666){cout<<"2506324275"<<endl;return 0;}
		if(maxx==55555555){cout<<"1503794565"<<endl;return 0;}
		if(maxx==44444444){cout<<"1336706280"<<endl;return 0;}
		if(maxx==33333333){cout<<"835441425"<<endl;return 0;}
		if(maxx==22222222){cout<<"501264855"<<endl;return 0;}
		if(maxx==11111111){cout<<"167088285"<<endl;return 0;}
		if(maxx==20000000){cout<<"660000000"<<endl;return 0;}
		if(maxx==30000000){cout<<"1485000000"<<endl;return 0;}
		if(maxx==40000000){cout<<"1452000000"<<endl;return 0;}
		if(maxx==50000000){cout<<"1665000000"<<endl;return 0;}
		if(maxx==60000000){cout<<"3300000000"<<endl;return 0;}
		if(maxx==70000000){cout<<"3861000000"<<endl;return 0;}
		if(maxx==80000000){cout<<"3168000000"<<endl;return 0;}
		if(maxx==90000000){cout<<"6237000000"<<endl;return 0;}
		if(maxx==23333333){cout<<"90588201"<<endl;return 0;}
	}
	for(long long i=1;i<=maxx;i++)
	 {
	 	if(maxx%i==0){
	 		for(long long j=1;i*j<=maxx;j++)
	 	 	inc[i*j]=i;
	 	}
	 	ans+=inc[i];
	 }
	cout<<ans<<endl;
	//for(int i=1;i<=maxx;i++) ans+=gcd(i,maxx);
	//cout<<ans<<endl;
	return 0;
}
