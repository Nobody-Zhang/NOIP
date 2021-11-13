#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("test.in","w",stdout);
	srand(time(0));
	int a=rand()%100000+1;
	int b=rand()%100000+1;
	cout<<a<<" "<<b<<endl;
	for(int i=1;i<=a;i++)
	cout<<i<<" ";
	cout<<endl;
	for(int i=1;i<=b;i++)
	{
		if(rand()%2==0){
			cout<<"M"<<" "<<rand()%a+1<<" "<<rand()<<endl;
		}
		else{
			cout<<"Q "<<rand()%a+1<<" "<<endl;
		}
	}
	return 0;
}
