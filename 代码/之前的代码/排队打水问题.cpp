#include<bits/stdc++.h>
using namespace std;
long long T[1002],s[1002];
int m,n;//m���ˣ�n��ˮ��ͷ 
long long total;
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	 	cin>>T[i];
	sort(T+1,T+m+1);
	for(int i=1;i<=m;i++)
	 s[i]=T[i];//��ÿ���˵ĵȴ�ʱ���ȼ��ϱ��� 
	for(int i=1;i<=n;i++)
	 total+=T[i];
	for(int i=n+1;i<=m;i++)
	 {
	 	s[i]+=s[i-n];
	 	total+=s[i];
	 }
	cout<<total<<endl;
}
