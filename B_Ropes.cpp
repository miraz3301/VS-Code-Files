#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t=0;
    long long int n,k;
    cin>>n>>k;
    long double arr[n];
    for(long long int i=0;i<n;i++)cin>>arr[i];
    long double l=0,h=1e18,mid,length,eps=1e-9;
    while(abs(h-l)>eps)
    {
        mid=(l+h)/2.0;
        long long int ropes=0;
        for(long long int i=0;i<n;i++)
        {
            ropes+=arr[i]/mid;
            if(ropes>=k)break;
        }
        if(ropes>=k)
        {
            length=mid;
            l=mid;
        }
        else h=mid;
 
    }
    cout<<length<<endl;
 
    return 0;
}