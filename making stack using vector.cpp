#include<bits/stdc++.h>
using namespace std;
class MyStack
{
    public:
        vector<int>v;

        void push(int val){v.push_back(val);}
        void pop(){v.pop_back();}
        int top(){return v.back();}
        int size(){return v.size();}
        bool empty(){return v.empty();}
};
int main()
{
    MyStack tas;
    // tas.push(10);
    // tas.push(20);
    // tas.push(30);
    // if(!tas.empty())cout<<tas.top()<<endl;
    // if(!tas.empty())tas.pop();
    // if(!tas.empty())cout<<tas.top()<<endl;
    // if(!tas.empty())tas.pop();
    // if(!tas.empty())cout<<tas.top()<<endl;
    // if(!tas.empty())tas.pop();
    // if(!tas.empty())cout<<tas.top()<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        tas.push(x);
    }
    while(!tas.empty())
    {
        cout<<tas.top()<<" ";
        tas.pop();
    }
}
