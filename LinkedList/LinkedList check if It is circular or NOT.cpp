#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node* link;
};

struct Node* head;

void print()
{
    struct Node* temp;
    temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->link;
    }
    cout<<endl;
}

//Insert a node at the beginning of a linked list
void insert(int val)
{
    struct Node* temp=(struct Node*) malloc(sizeof(struct Node));
    temp->data=val;
    temp->link=NULL;

    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        struct Node* t;
        t=head;
        while(t->link!=NULL)
        {
            t=t->link;
        }
        t->link=temp;
    }

}

bool isCricular()
{
    if(head==NULL)
    {
        return true;
    }

    struct Node* temp5;
    temp5=head->link;
    while(temp5!=NULL && temp5!=head)
    {
        temp5=temp5->link;
    }

    if(temp5==head)return true;
    return false;
}

int main()
{
    head=NULL;
    insert(1);
    insert(2);
    insert(3);
    insert(4);

    print();
    //Make it circular to check!
    //head->link->link->link->link=head;


    bool f=isCricular();
    if(f)cout<<"it is circular LinkedList"<<endl;
    else cout<<"it is not a circular LinkedList"<<endl;

}
