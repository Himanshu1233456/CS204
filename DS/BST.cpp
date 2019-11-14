#include<iostream>
using namespace std;

struct Node
{
int val;
struct Node *left, *right;
};

struct Node *newNode(int val)
{
struct Node *temp =  new struct Node();
temp->val = val;
temp->left = temp->right = NULL;
return temp;
}

void in(struct Node *root)
{
if (root != NULL)
    {
in(root->left);
cout<<root->val<<" ";
in(root->right);
    }
}

struct Node* insert(struct Node* node, int val)
{
if (node == NULL) return newNode(val);
if (val < node->val)
node->left  = insert(node->left, val);
else
node->right = insert(node->right, val);
return node;
}

struct Node * min(struct Node* node)
{
struct Node* current = node;
while (current && current->left != NULL)
current = current->left;
return current;
}

struct Node * max(struct Node* node)
{
struct Node* current = node;
while (current && current->right != NULL)
current = current->right;
return current;
}

struct Node* find(struct Node* node, int x)
{
  struct Node* current = node;
  if(current == NULL)
    return NULL;
  else if(x < current->val)
    return find(current->left, x);
  else if(x > current->val)
    return find(current->right, x);
  else
    return current;
}

struct Node* Remove(struct Node* root, int val)
{
if (root == NULL) return root;
if (val < root->val)
root->left = Remove(root->left, val);
else if (val > root->val)
root->right = Remove(root->right, val);
else
    {
if (root->left == NULL)
        {
struct Node *temp = root->right;
free(root);
return temp;
        }
else if (root->right == NULL)
        {
struct Node *temp = root->left;
free(root);
return temp;
        }
struct Node* temp = min(root->right);
root->val = temp->val;
root->right = Remove(root->right, temp->val);
    }
    return root;
}

int main()
{
struct Node *t = NULL;
t = insert(t, 2);
t = insert(t, 3);
t = insert(t, 5);
t = insert(t, 6);
t = insert(t, 4);
t = insert(t, 7);
t = insert(t, 1);

cout<<endl;
in(t);

cout<<endl;
t = Remove(t, 4);
in(t);

cout<<endl;
cout<<min(t)->val;

cout<<endl;
cout<<max(t)->val;

cout<<endl;
if(find(t,9)==NULL)
{
  cout<<"No Node Found!";
}
else
{
  cout<<find(t,9)->val;
}

return 0;
}
