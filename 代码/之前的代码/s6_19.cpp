#include<bits/stdc++.h>
using namespace std;
struct student
{
	string name;
	int order,number;
};
student stu[105],x;
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>stu[i].name;
		stu[i].order=i;//order是输入顺序，name是学号 
	}
	for(int i=1;i<=n-1;i++)
	 for(int j=1;j<=n-1;j++)
	  if(stu[j].name>stu[j+1].name)
	   swap(stu[j],stu[j+1]);
	for(int i=1;i<=n;i++)
	 stu[i].number=i;
	for(int i=1;i<=n-1;i++)
	 for(int j=1;j<=n-1;j++)
	  if(stu[j].order>stu[j+1].order)
	   swap(stu[j],stu[j+1]);
	for(int i=1;i<=n;i++)
	cout<<stu[i].number<<"\n";
	return 0;
}
