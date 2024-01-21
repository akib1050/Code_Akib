#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node* link;
};


// Node typer structure er dik e point kore thakte parbe
struct Node* head;

void  printLinkedList()
{
    struct Node* temp;
    temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->link;
    }

}


int main()
{
    head = NULL;
     //Node Create er jnno malloc
     //Node typer structure er memory loc return korbe malloc()
     //ejnno type cast krte hbe ja (struct Node*)
     //head jeno ei memory address k point kore thaka tai head=...
    head = (struct Node*)malloc(sizeof(struct Node));

    head->data=2; // node er mddhe data rakhlam

    //again for creating another node

    head->link=(struct Node*)malloc(sizeof(struct Node));

    head->link->data=5; // store 5 at the new mem
    head->link->link=NULL;

    printLinkedList();


}
