#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    list<int>l={1,2,3,4,5};
    //int arr[]={10,20,30,40};
    vector<int>arr={10,20,30,40};
    list<int>l2(arr.begin(),arr.end());
    //for(auto it=l.begin();it!=l.end();it++)cout<<*it<<endl;
    l2.clear();
    //if(l2.empty())cout<<"empty"<<endl;
    for(int val:l2)cout<<val<<endl;
    if()
}