#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int val;
        Node *next;
        Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *new_node=new Node(val);
    if(head==NULL)
    {
        head=new_node;
        tail=new_node;
        return;
    }
    new_node->prev=tail;
    tail->next=new_node;
    tail=new_node;
}
int main()
{
    Node *head=NULL;
    Node *tail=NULL;
    
    int val;
    while(1)
    {
        cin>>val;
        if(val==-1)break;
        insert_at_tail(head,tail,val);
    }
    for(Node *i=head,*j=tail;i!=j && i->prev!=j;i=i->next,j=j->prev)
    {
        if(i->val!=j->val)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}