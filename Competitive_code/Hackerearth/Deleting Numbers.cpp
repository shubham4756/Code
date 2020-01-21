#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,i;
    cin>>n>>k;
    long long int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    int s=(n-k+1)/2;
    int e=s+k-1;
    int max=a[s-1];
    for(i=s-1;i<=e;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    cout<<max;
    return 0;
}
