#include<bits/stdc++.h>
using namespace std;
char tx[15][6],bd[15][6];
int main()
{
	int n,i=0;
	cin>>n;
	for(int u=1;u<=n;u++)
	  scanf("%c%c%c%c%c %c%c%c%c%c",&tx[u][1],&tx[u][2],&tx[u][3],&tx[u][4],&tx[u][5],&bd[u][1],&bd[u][2],&bd[u][3],&bd[u][4],&bd[u][5]);
	for(int u=1;u<=n;u++)
	  for(int o=1;o<=5;o++)
	   if(tx[u][o]==bd[u][o])
	    i++;
	    int c=5*n-i;
	 cout<<i*2<<" "<<c*2;
}
