#include<bits/stdc++.h>
using namespace std;
string s[505];
int main()
{
	int i;
	cin>>i;
	while(1)
	{ 
	 for(int q=1;q<=i;q++)
	  cin>>s[q];
	 for(int u=1;u<=i;u++)
	  for(int q=1;q<=i-1;q++)
	   if(s[q]+s[q+1]<s[q+1]+s[q])
	    swap(s[q],s[q+1]);
	 for(int q=1;q<=i;q++)
	  cout<<s[q];
	  break;
	} 
	 return 0;
}
