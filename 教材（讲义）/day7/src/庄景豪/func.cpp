#include<bits/stdc++.h>
#define LL long long
using namespace std;
int L,R,D,f[100010],ans1;
int pr[100]={2,3,5,7,11,13,17,19,23,29,31,37,
41,43,47,53,59,61,67,71,73,79,83,89,
97,101,103,107,109,113,127,131,137,139,149,151,
157,163,167,173,179,181,191,193,197,199,211,223,
227,229,233,239,241,251,257,263,269,271,277,281,
283,293,307,311,313,317,331,337,347,349,353,359,
367,373,379,383,389,397,401,409,419,421,431,433,
439,443,449,457,461,463,467,479,487,491,499,503};
inline LL qm(LL d,LL c,int fl)
{
	LL ans=1;
	if(fl==1){
		LL ans=1;
		while(c){
			if(c&1)ans=ans*d;
			d=d*d;
			c/=2;
		}
		return ans;
	}
	while(c){
		if(c&1)ans=ans*d%D;
		d=d*d%D;
		c/=2;
	}
	return ans%D;
}
void prime(int x,int k)
{
	int sum=0;
	for(int i=1;pr[i]*pr[i]<=x&&i<=95;i++){
		if(x%pr[i]==0){
			sum+=pr[i];
			while(x%pr[i]==0){
				x/=pr[i];
			}
		}
	}
	if(x!=1)sum+=x;
	if(k==1)sum=1;
	f[k]=qm(2048,qm(3,sum,1),0);
}
int main()
{
	freopen("func.in","r",stdin);
	freopen("func.out","w",stdout);
	cin>>L>>R>>D;
	for(int i=L;i<=R;i++){
		prime(i,i);
	}
	ans1=f[L];
	for(int i=L+1;i<=R;i++){
		ans1^=f[i];
	}
	printf("%d",ans1);
}
