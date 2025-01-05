#include<bits/stdc++.h>
using namespace std;
int main()
{
    list<string>l;
    string s;
    while(1)
    {
        cin>>s;
        if(s=="end")break;
        l.push_back(s);
    }
    int t;
    cin>>t;
    auto it=l.begin();
    while(t--)
    {
        string test;
        cin>>test;
        if(test=="visit")
        {
            string s1;
            cin>>s1;
            auto newit=find(l.begin(),l.end(),s1);
            if(newit!=l.end())
            {
                cout<<s1<<endl;
                it=newit;
            }
            else cout<<"Not Available\n";
        }
        else if(test=="prev")
        {
            if (it!=l.begin()) 
            {
                it--;
                cout<< *it <<endl;
            } 
            else cout<<"Not Available\n";
        }
        else if(test=="next")
        {
            auto nextit=next(it);
            if (nextit!=l.end()) 
            {
                it=nextit;
                cout<< *nextit <<endl;
            } 
            else cout<<"Not Available\n";
        }
    }
    
}