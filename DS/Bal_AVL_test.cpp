#include<bits/stdc++.h>
using namespace std;

class BST
{
    struct node
    {
        int val;
        node* left;
        node* right;
        int height;
    };

    node* root;

    void makeEmpty(node* t)
    {
        if(t == NULL)
            return;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }

    node* insert(int x, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->val = x;
            t->height = 0;
            t->left = t->right = NULL;
        }
        else if(x < t->val)
        {
            t->left = insert(x, t->left);
            if(height(t->left) - height(t->right) == 2)
            {
                if(x < t->left->val)
                    t = SR(t);
                else
                    t = DR(t);
            }
        }
        else if(x > t->val)
        {
            t->right = insert(x, t->right);
            if(height(t->right) - height(t->left) == 2)
            {
                if(x > t->right->val)
                    t = SL(t);
                else
                    t = DL(t);
            }
        }

        t->height = max(height(t->left), height(t->right))+1;
        return t;
    }

    node* SR(node* &t)
    {
        node* u = t->left;
        t->left = u->right;
        u->right = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(u->left), t->height)+1;
        return u;
    }

    node* SL(node* &t)
    {
        node* u = t->right;
        t->right = u->left;
        u->left = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(t->right), t->height)+1 ;
        return u;
    }

    node* DL(node* &t)
    {
        t->right = SR(t->right);
        return SL(t);
    }

    node* DR(node* &t)
    {
        t->left = SL(t->left);
        return SR(t);
    }

    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node* findMax(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    node* remove(int x, node* t)
    {
        node* temp;
        if(t == NULL)
            return NULL;

        else if(x < t->val)
            t->left = remove(x, t->left);
        else if(x > t->val)
            t->right = remove(x, t->right);

        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->val = temp->val;
            t->right = remove(t->val, t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }
        if(t == NULL)
            return t;

        t->height = max(height(t->left), height(t->right))+1;
        if(height(t->left) - height(t->right) == 2)
        {
            if(height(t->left->left) - height(t->left->right) == 1)
                return SL(t);
            else
                return DL(t);
        }
        else if(height(t->right) - height(t->left) == 2)
        {
            if(height(t->right->right) - height(t->right->left) == 1)
                return SR(t);
            else
                return DR(t);
        }
        return t;
    }

    int height(node* t)
    {
        return (t == NULL ? -1 : t->height);
    }

    int getBalance(node* t)
    {
        if(t == NULL)
            return 0;
        else
            return height(t->left) - height(t->right);
    }

    void inorder(node* t)
    {
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->val << " ";
        inorder(t->right);
    }

public:
    BST()
    {
        root = NULL;
    }

    void insert(int x)
    {
        root = insert(x, root);
    }

    void remove(int x)
    {
        root = remove(x, root);
    }

    void show()
    {
        inorder(root);
        cout << endl;
    }
};

int main()
{
    BST t;
    t.insert(1);
    t.insert(2);
    t.insert(3);
    t.insert(4);
    t.insert(5);
    t.remove(3);
    t.show();


}
