#include<bits/stdc++.h>
using namespace std;
int i[100001];
int main()
{
	int x,y;
	 cin>>x;
	for(int u=1;u<=x;u++)
	 {
	 	cin>>y;
	 	i[y]++;
	 }
	for(int u=1;u<=100000;u++)
	 {
	 	if(i[u]!=0) cout<<u<<" ";
	 } 
	 return 0;
}
