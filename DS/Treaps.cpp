#include<bits/stdc++.h>
using namespace std;

struct tnode
{
    int pr;
    int key;
    tnode *left,*right;
};

tnode* rightrotate(tnode* x)
{
    tnode* y=x->left;
    tnode* temp =y->right;
    y->right=x;
    x->left=temp;
    return y;

}
tnode* leftrotate(tnode* x)
{
    tnode* y=x->right;
    tnode* temp =y->left;
    y->left=x;
    x->right=temp;
    return y;
}

tnode* newNode(int key)
{
    tnode* temp =new tnode;
    temp->key=key;
    temp->pr=rand()%100;
    temp->left=temp->right=NULL;
    return temp;
}

tnode* Search(tnode* root ,int key)
{
    if(root==NULL||root->key==key)
    {
        return root;
    }
    else if(root->key<key)
    {
        Search(root->right,key);
    }
    else if(root->key>key)
    {
        Search(root->left,key);
    }
}

tnode* Insert(tnode* root,int key)
{
    if(root==NULL)
    {
        tnode* temp=newNode(key);
        return temp;
    }
    else if(root->key<key)
    {
        root->right=Insert(root->right,key);
        if(root->right->pr>root->pr)
        {
           root=leftrotate(root);
        }
    }
     else if(root->key>=key)
    {
        root->left=Insert(root->left,key);
        if(root->left->pr > root->pr)
        {
            root=rightrotate(root);
        }
    }
    return root;
}

tnode* Delete(tnode* root,int key)
{
    if(root==NULL)
    {
        return root;
    }
    else if(root->key<key)
    {
        root->right=Delete(root->right,key);

    }
    else if(root->key>key)
    {
        root->left=Delete(root->left,key);
    }
    else if(root->left==NULL)
    {
        tnode* temp=root->right;
        delete(root);
        root=temp;
    }
    else if(root->right==NULL)
    {
        tnode* temp=root->left;
        delete(root);
        root=temp;
    }
    else if(root->right->pr > root->left->pr)
    {
        root=leftrotate(root);
        root->left=Delete(root->left,key);
    }
     else if(root->right->pr < root->left->pr)
    {
        root=rightrotate(root);
        root->left=Delete(root->left,key);
    }
    return root;
}

void inorder(tnode* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<"Key/Priority: ("<<root->key<<","<<root->pr<<")";
        if(root->left)
        {
            cout<< " --> Left child: "<<root->left->key;
        }
        if(root->right)
        {
            cout<< " --> Right child: "<<root->right->key;
        }
        cout<<endl<<endl;
        inorder(root->right);
    }
}

int main()
{
    srand(time(NULL));
    struct tnode *root = NULL;
    root = Insert(root, 1);
    root = Insert(root, 2);
    root = Insert(root, 5);
    root = Insert(root, 6);
    root = Insert(root, 3);
    root = Insert(root, 10);
    root = Insert(root, 13);

    inorder(root);

    root = Delete(root, 10);
    cout<<endl<<"10 Removed"<<endl;

    inorder(root);

    /*

    tnode *temp = Search(root, 6);
    (temp == NULL)? cout <<endl<< "6 Not Found ":  cout << endl<<"6 found"; */

    return 0;
}
