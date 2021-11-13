#include<cstdio>
#include<iostream>
using namespace std;

int main() {
	freopen("comb.in","r",stdin);
	freopen("comb.out","w",stdout);
	long long n, p, ans1, ans2;
	cin >> n >> p;
	ans1 = n + 1;
	ans2 = 1;
	while( n ) { 
		ans2 *= n % p + 1;
		n /= p;
	}
	cout << ans1 - ans2-1 << endl;
	return 0;
}

