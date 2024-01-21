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
}

//Insert a node at the beginning of a linked list
void insert(int val)
{
    struct Node* temp= (struct Node*) malloc(sizeof(struct Node));
    temp->data=val;
    temp->link=head;// head j dik point kore ase temp o sedik point kore thakbe
    head=temp;// head ekhn temp ke point korbe
}

int main()
{
    head=NULL;
    insert(1);
    insert(2);
    insert(3);
    insert(4);

    print();

}
