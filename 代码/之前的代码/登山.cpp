#include<bits/stdc++.h>
using namespace std;
int n,in[1005][4],maxx;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	 cin>>in[i][1];
	for(int i=1;i<=n;i++)
	 {
	 	for(int j=i-1;j>=1;j--)
	 	if(in[i][1]>in[j][1]&&in[i][2]<=in[j][2])
	 	in[i][2]=in[j][2];
	 	in[i][2]++;
	 }//�����������������е����� 
	 //�������������һ��������ɽʱ���ǿ������棬��Ҫ���Ǹ���������½������� 
	 //����ת������max����ǰ������������� 
	for(int i=n;i>=1;i--)
	{
		for(int j=i+1;j<=n;j++)
		if(in[i][1]>in[j][1]&&in[i][3]<=in[j][3])
		 in[i][3]=in[j][3];//���½������� 
		in[i][3]++;
	}
	for(int i=1;i<=n;i++)
	 if(in[i][2]+in[i][3]>maxx) maxx=in[i][2]+in[i][3];
	cout<<maxx-1;//��Ϊ��ǰ���㱻�������飬����˵��Ҫ-1
	return 0; 
}
/*
8
186 186 150 200 160 130 197 220
*/
