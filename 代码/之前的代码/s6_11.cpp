#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[3005],n,i,k,max,temp;
 
    scanf("%d",&n);//666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(k=0;k<n-1;k++)
    {
        max=k;
        for(i=k+1;i<n;i++)
            if(a[i]>a[max])
                max=i;
        if( max!=k ) 
        {
            temp=a[max];
            a[max]=a[k];
            a[k]=temp;
        }
    }
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
