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
void insert_at_head(Node *&head,Node *&tail,int val)
{
    Node *new_node=new Node(val);
    if (head==NULL)
    {
        head=new_node;
        tail=new_node;
        return;
    }
    head->prev=new_node;
    new_node->next=head;
    head=new_node;
}
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
void insert_at_any_position(Node *&head,Node *&tail,int index,int val)
{
    Node *temp=head;
    for (int i=1;i<index;i++)temp=temp->next;
    Node *new_node=new Node(val);
    new_node->prev = temp;
    new_node->next = temp->next;
    temp->next->prev = new_node;
    temp->next = new_node;
}
void print_forward(Node *&head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
void print_backward(Node *&head,Node *&tail)
{
    Node *temp=tail;
    while(temp!=NULL)
    {
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
}
int main()
{
    int q,l=0;
    cin>>q;
    Node *head = NULL;
    Node *tail = NULL;
    while(q--)
    {
        int x,val;
        cin>>x>>val;
        if(x==0)
        {
            insert_at_head(head,tail,val);
            l++;
            cout<<"L -> ";
            print_forward(head);
            cout<<"R -> ";
            print_backward(head,tail);
        }
        else if(x==l)
        {
            insert_at_tail(head,tail,val);
            l++;
            cout<<"L -> ";
            print_forward(head);
            cout<<"R -> ";
            print_backward(head,tail);
        }
        else if(x<l)
        {
            insert_at_any_position(head,tail,x,val);
            l++;
            cout<<"L -> ";
            print_forward(head);
            cout<<"R -> ";
            print_backward(head,tail);
        }
        else if(x>l)cout<<"Invalid\n";
    }
}