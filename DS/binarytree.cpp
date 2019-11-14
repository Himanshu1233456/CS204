#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int val;
	struct Node* left, *right;
	Node(int val)
	{
		this->val = val;
		left = right = NULL;
	}
};

void In(struct Node* node)
{
	if (node == NULL)
		return;

	In(node->left);
	cout << node->val << " ";
	In(node->right);
}

void Pre(struct Node* node)
{
	if (node == NULL)
		return;

	cout << node->val << " ";
	Pre(node->left);
	Pre(node->right);
}

void Post(struct Node* node)
{
	if (node == NULL)
		return;

	Post(node->left);
	Post(node->right);
	cout << node->val << " ";
}

struct Node* find(struct Node* node, int val)
{
		struct Node* tmp = node;
    if (tmp == NULL || tmp->val == val)
       return tmp;

    if (tmp->val < val)
       return find(tmp->right, val);

    return find(tmp->left, val);
}

int main()
{
  int n,c;
  cin>>c;
	struct Node *t = new Node(1);
	t->left = new Node(2);
	t->right	= new Node(3);
	t->left->left = new Node(4);
	t->left->right = new Node(5);
  t->right->left = new Node(6);
  t->right->right = new Node(7);

  switch(c)
    {
      case 1: In(t);
        break;
      case 2: Pre(t);
        break;
      case 3: Post(t);
        break;
    }

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
