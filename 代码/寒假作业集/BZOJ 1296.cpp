#include<bits/stdc++.h>
using namespace std;
int n,m,t;//n�У�ÿ��m�������t�� 
long long in[51][51],f[51][51][2505],dp[51][51],sum[51][2501];
//f[i][j][k];��i��ľ��ǰj�����ӷ�ˢk�ε����ֵ 
int main()
{
//	freopen("test.in","r",stdin);
    //redi(n,m,t);
    char c;
    cin>>n>>m>>t; 
    for(int i=1;i<=n;i++){
        //for(int j=1;j<=m;j++){
        string s;
        cin>>s;
        //cout<<s<<endl; 
        for(int j=1;j<=m;j++)	
            in[i][j]=s[j-1]-'0';
            //c=getchar();
             //if(c=='1') in[i][j]=1;
        //}
         
         //in[i][j]=(c=='1');
         //scanf("%d",&in[i][j]);
         //redi(in[i][j]);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            sum[i][j]=sum[i][j-1]+in[i][j];
    for(int i=1;i<=n;i++)//��������һ�� 
        for(int j=1;j<=m;j++)//����ǰ���� 
            for(int k=1;k<=m;k++)//����ڼ��� 
                for(int l=0;l<j;l++)//�м䴦�� 
                {
                    int tmp=sum[i][j]-sum[i][l];
                    int mid=max(f[i][j][k],f[i][l][k-1]+max(tmp,j-tmp-l));
                    f[i][j][k]=mid;
                }
//	for(int i=1;i<=n;i++)
//	 {for(int j=1;j<=m;j++)
//	 {
//	  for(int k=1;k<=m;k++)
//	   cout<<i<<" "<<j<<" "<<k<<"      "<<f[i][j][k]<<"/";
//	 	cout<<endl;
//	 }
//	 	cout<<endl;
//	 }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=t;j++)
            for(int k=0;k<=j;k++)
                dp[i][j]=max(dp[i][j],dp[i-1][j-k]+f[i][m][k]);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=t;j++)
//			cout<<dp[i][j]<<"	";
//		cout<<endl;
//	} 
    long long ans=0;
    for(int i=1;i<=t;i++)
        ans=max(ans,dp[n][i]);
    //ans=dp[n][t];
    cout<<ans<<endl;
    return 0;
 } 
