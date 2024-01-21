#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

//implementing BST

struct bst
{
     int data;
    struct bst* left;
    struct bst* right;


};

struct bst* root;

void insert(int val)
{
    struct bst* newNode=(struct bst*)malloc(sizeof(struct bst));
    newNode->data=val;
    newNode->left=NULL;
    newNode->right=NULL;

    if(newNode==NULL)
    {
        root=newNode;
    }
    else
    {
        struct bst* temp=root;
        while(1)
        {
            if(newNode->data<=temp->data)
            {
                //For filling up the left side
                if(temp->left==NULL)
                {
                    temp->left=newNode;
                    break;
                }
                else
                {
                    temp=temp->left;
                }

            }
            else
            {
                //for filling up the right side
                if(temp->right==NULL)
                {
                    temp->right=newNode;
                    break;
                }
                else
                {
                    temp=temp->right;
                }
            }
        }

    }
}

void preOrder(struct bst* r)
{
    if(r==NULL)return;

    cout<<r->data<<" ";

    preOrder(r->left);
    preOrder(r->right);

}

void InOrder(struct bst* r)
{
    if(r==NULL)return;

    preOrder(r->left);

    cout<<r->data<<" ";

    preOrder(r->right);

}

void PostOrder(struct bst* r)
{
    if(r==NULL)return;

    preOrder(r->left);
    preOrder(r->right);
    cout<<r->data<<" ";


}




int main()
{
    root = NULL;
    insert(5);
    insert(6);


    preOrder(root);


}
