#include<bits/stdc++.h>
using namespace std;
int main()
{
    list<int>l;
    int q,s=0;
    cin>>q;
    while(q--)
    {
        int x,val;
        cin>>x>>val;
        if(x==0)
        {
            l.push_front(val);
            s++;
            cout<<"L -> ";
            for(int i:l)cout<<i<<" ";
            cout<<endl;
            l.reverse();
            cout<<"R -> ";
            for(int i:l)cout<<i<<" ";
            cout<<endl;
            l.reverse();
        }
        else if(x==1)
        {
            l.push_back(val);
            s++;
            cout<<"L -> ";
            for(int i:l)cout<<i<<" ";
            cout<<endl;
            l.reverse();
            cout<<"R -> ";
            for(int i:l)cout<<i<<" ";
            cout<<endl;
            l.reverse();
        }
        else if(x==2)
        {
            if(val<s)
            {
                auto it=l.begin();
                advance(it,val);
                l.erase(it);
                s--;
            }
            cout<<"L -> ";
            for(int i:l)cout<<i<<" ";
            cout<<endl;
            l.reverse();
            cout<<"R -> ";
            for(int i:l)cout<<i<<" ";
            cout<<endl;
            l.reverse();
        }
    }
    
}