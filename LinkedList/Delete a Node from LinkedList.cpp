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

void deleteNode(int position)
{
    if(position==1)
    {
        struct Node* temp3;
        temp3=head;
        head=head->link;
        free(temp3);
    }
    else
    {
        struct Node* temp1;
        temp1=head;
        for(int i=1;i<=position-2;i++)
        {
            temp1=temp1->link;
        }
        struct Node* temp2;
        temp2=temp1->link;
        temp1->link=temp2->link;
        free(temp2);
    }
}

int main()
{
    head=NULL;
    insert(1);
    insert(2);
    insert(3);
    insert(4);

    print();
    deleteNode(1);
    print();
    deleteNode(3);
    print();

}
