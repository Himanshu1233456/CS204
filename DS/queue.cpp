#include <bits/stdc++.h>
using namespace std;

struct node
{
   int val;
   struct node *next;
};

struct node* front = NULL;
struct node* rear = NULL;
struct node* tmp;

void Insert()
{
   int val;
   cin>>val;
   if (rear == NULL)
   {
      rear = (struct node *)malloc(sizeof(struct node));
      rear->next = NULL;
      rear->val = val;
      front = rear;
   }

   else
   {
    tmp=(struct node *)malloc(sizeof(struct node));
    rear->next = tmp;
    tmp->val = val;
    tmp->next = NULL;
    rear = tmp;
   }
}

void Delete()
{
   tmp = front;
   if (front == NULL)
   {
      cout<<"Underflow"<<endl;
      return;
   }
   else
   if (tmp->next != NULL)
   {
     tmp = tmp->next;
     free(front);
     front = tmp;
   }
   else
   {
     free(front);
     front = NULL;
     rear = NULL;
   }
}

void Display()
{
   tmp = front;
   if ((front == NULL) && (rear == NULL))
   {
      cout<<"Empty"<<endl;
      return;
   }
   cout<<"Queue: ";
   while (tmp != NULL) {
      cout<<tmp->val<<" ";
      tmp = tmp->next;
   }
   cout<<endl;
}

int main()
{
   int ch;
do {
   cin>>ch;
   switch (ch) {
      case 1: Insert();
         break;
      case 2: Delete();
         break;
      case 3: Display();
         break;
      case 4: cout<<"Exit"<<endl;
         break;
      default: cout<<"Invalid"<<endl;
   }
} while(ch!=4);
   return 0;
}
