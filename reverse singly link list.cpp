#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int val;
        Node *next;
    Node(int val)
    {
        this->val=val;
        this->next=NULL;
    }
};
void insert(Node *&head,Node *&tail,int val)
{
    Node *newNode=new Node(val);
    if(head==NULL)
    {
        head=newNode;
        tail=newNode;
        return;
    }
    tail->next=newNode;
    tail=newNode;
}
void print_list(Node *&head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}
void reverse_sigly_linkList(Node *&head,Node *&tail,Node *temp)
{
    if(temp->next==NULL)
    {
        head=temp;
        return;
    }
    reverse_sigly_linkList(head,tail,temp->next);
    temp->next->next=temp;
    temp->next=NULL;
    tail=temp;
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
        insert(head,tail,val);
    }
    reverse_sigly_linkList(head,tail,head);
    print_list(head);
    cout<<endl<<tail->val<<endl<<head->val;
}