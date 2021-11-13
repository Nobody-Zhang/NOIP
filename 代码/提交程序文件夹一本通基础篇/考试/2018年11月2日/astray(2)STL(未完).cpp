#pragma optimize(2)
#include<bits/stdc++.h>
#define ll(x1,y1,x2,y2) sqrt(pow((x1-x2),2)+pow((y1-y2),2))
using namespace std;
vector<pair<int,int> > a,b;
int gcd(int a, int b)
{
    int t;
    if (a < b)
    {
        t = a;
        a = b;
        b = t;
    }
    while (b != 0)
    {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}
int main()
{
	int m;
	pair<int,int> p;
	cin>>p.first>>p.second>>m;
	a.push_back(p);
	vector<pair<int,int> >::iterator ita=a.begin();
	for(int i=1;i<=m;i++)
	{
		int k;
		char y;
		cin>>k>>y;
		if(y=='X')
		{
			
			while(1)
			{
				if(k>(*ita).first)
				p.first=(*ita).first+1;
				else
				p.first=(*ita).first-1;
				p.second=(*ita).second;
				a.push_back(p);
				ita++;
				if(p.first==k)
				 break;
				ita++;
			}
		}
		if(y=='Y')
		{
			while(1)
			{
				p.first=(*ita).first;
				if(k>(*ita).second)
				p.second=(*ita).second+1;
				else
				p.second=(*ita).second-1;
				a.push_back(p);
				if(p.second==k)
				break;
				ita++;
			}
		}
	}
	int n;
	cin>>p.first>>p.second>>n;
	b.push_back(p);
	vector<pair<int,int> >::iterator itb=b.begin();
	for(int i=1;i<=m;i++)
	{
		int k;
		char y;
		cin>>k>>y;
		if(y=='X')
		{
			while(1)
			{
				if(k>(*itb).first)
				p.first=(*itb).first+1;
				else
				p.first=(*itb).first-1;
				p.second=(*itb).second;
				b.push_back(p);
				if(p.first==k)
				 break;
				itb++;
			}
		}
		if(y=='Y')
		{
			while(1)
			{
				p.first=(*itb).first;
				if(k>(*itb).second)
				p.second=(*itb).second+1;
				else
				p.second=(*itb).second-1;
				b.push_back(p);
				itb++;
				if(p.second==k)
				 break;
				itb++;
			}
		}
	}
	int cs=gcd(a.size(),b.size());
	double minn=20000.00;
	itb=b.begin();
	ita=a.begin();
	for(int i=1;i<=cs+2;i++)
	 {
	 	ita++;
	 	itb++;
	 	if(ita==a.end()) ita=a.begin();
	 	if(itb==b.end()) itb=b.begin();
	 	minn=min(minn,ll((*ita).first,(*ita).second,(*itb).first,(*itb).second));
	 }
	 printf("%.2lf",minn);
	 return 0;
}
