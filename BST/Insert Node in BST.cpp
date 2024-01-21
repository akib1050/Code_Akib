#include<bits/stdc++.h>

using namespace std;

//implementing BST

struct bst
{
    struct bst* left;
    struct bst* right;
    int data;

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
        struct bst* temp;
        while(1)
        {
            if(newNode->data<=temp->data)
            {
                //For filling up the left side
                if(temp->left==NULL)
                {
                    temp->left=temp;
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
                    temp->right=temp;
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




int main()
{
    root = NULL;
    insert(1);
    insert(2);



}
