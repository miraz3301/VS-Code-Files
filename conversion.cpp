#include<bits/stdc++.h>
using namespace std;
int main()
{
    int given,base,dec=0,i,temp,temp1,k=0;
    cout<<"Number :";
    cin>>given;
    cout<<"Base :";
    cin>>base;
    temp=given;
    while(temp)
    {
        temp/=10;
        k++;
    }
    temp1=given;
    for(i=0;i<k;i++)
    {
        int las=temp1%10;
        dec+=las*pow(base,i);
        temp1/=10;
    }
    cout<<dec;
}

