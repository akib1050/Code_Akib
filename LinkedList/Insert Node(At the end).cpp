#include <bits/stdc++.h>

using namespace std;

struct  Node
{
    int data;
    struct Node* link;

};

struct Node* Head;

void print()
{
    struct Node* temp;
    temp=Head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->link;
    }
}


void insert(int val)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=val;
    temp->link=NULL;
    if(Head==NULL)
    {
        Head=temp;
    }
    else
    {
        struct Node* t;
        t=Head;
        while(t->link!=NULL)
        {
            t=t->link;
        }
        t->link=temp;

    }
}

int main()
{
    Head=NULL;
    insert(1);
    insert(2);
    insert(3);

    print();

}
