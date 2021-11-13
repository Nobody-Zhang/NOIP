#include<bits/stdc++.h>
const int maxT = 4000105;
int n,m,t,ti,ans=1e9,l=1,r,cnt[maxT],sum[maxT],q[maxT],f[maxT];
inline double getSlope(int u, int v) 
{ 
	return (double) (f[v] + sum[v] - f[u] - sum[u]) / (cnt[u] == cnt[v] ? 1e-9 : cnt[v] - cnt[u]);
}

int main() {
	freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) 
	{
        scanf("%d", &ti); t = std::max(t, ti);
        cnt[ti]++; sum[ti] += ti;
    }
    for (int i = 1; i < t + m; i++) 
	{ cnt[i] += cnt[i - 1];
	 sum[i] += sum[i - 1]; 
	 } 
    for (int i = 0; i < t + m; i++) 
	{
        if (i - m >= 0) 
		{
            while (l < r && getSlope(q[r - 1], q[r]) >= getSlope(q[r], i - m)) 
			{
			 r--;
			  }
            q[++r]=i-m; 
        }
        while(l<r&&getSlope(q[l],q[l+1])<= i)
		 { 
		 l++;
		 } 
        f[i]=cnt[i]*i-sum[i]; 
        if(l<=r) 
		{ 
		f[i] = std::min(f[i], f[q[l]] + (cnt[i] - cnt[q[l]]) * i - (sum[i] - sum[q[l]]));
		} 
    }
    for (int i = t; i < t + m; i++) 
	{ 
	ans = std::min(ans, f[i]); 
	}
    printf("%d\n", ans);
    return 0;
}
