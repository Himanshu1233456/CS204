#include <iostream>
using namespace std;

struct node
{
	int x;
	int y;
	struct node* ptr;
};

struct node* Head=NULL;

struct node* AddFirst(int x,int y)
{
	struct node* tmp;
	tmp=(struct node*)malloc(sizeof(node));

	if(Head==NULL)
	{
		tmp->x=x;
		tmp->y=y;
		tmp->ptr=NULL;
		Head=tmp;
	}

	else
	{
		tmp->x=x;
		tmp->y=y;
		tmp->ptr=Head;
		Head=tmp;
	}

	return Head;
}

struct node* DelFirst()
{
	struct node* tmp;

	if(Head==NULL)
	{
		cout<<"Linked List Empty!"<<endl;
	}

	else
	{
		tmp=Head;
		Head=Head->ptr;
		free(tmp);
	}
	return Head;
}

struct node* Del(int x,int y)
{
	struct node* tmp;
	struct node* tmp2;
	struct node* tmp1=NULL;
	tmp=Head;
	tmp2=Head;

	while(tmp!=NULL)
	{
		if(tmp->x==x && tmp->y==y)
		{
			if(tmp==Head)
			{
				Head=Head->ptr;
				free(tmp);
				return Head;
			}
		}
	tmp=tmp->ptr;
	}

	while(tmp2->ptr!=NULL)
	{
		if(tmp2->ptr->x==x && tmp2->ptr->y==y)
		{
			tmp1=tmp2->ptr;
			tmp2->ptr=tmp2->ptr->ptr;
			free(tmp1);
			return Head;
		}
	tmp2=tmp2->ptr;
	}
	cout<<"No Node Found!"<<endl;
	return Head;
}

void Search(double d)
{
	struct node* tmp;
	tmp=Head;

	int c1=d*d;
	int cnt=0;

	while(tmp!=NULL)
	{
		if((((tmp->x)*(tmp->x))+((tmp->y)*(tmp->y)))<=c1)
		{
			cout<<"("<<tmp->x<<","<<tmp->y<<")";
			cnt+=1;
		}
	tmp=tmp->ptr;
	}
	cout<<endl;

	if(cnt==0)
	{
		cout<<"No Node Found!"<<endl;
	}
}

void Search(int x,int y)
{
	int cnt=0;
	struct node* tmp;
	tmp=Head;

	while(tmp!=NULL)
	{
		if(tmp->x==x && tmp->y==y)
		{
			cnt+=1;
		}
	tmp=tmp->ptr;
	}

	if(cnt>0)
	{
		cout<<"True"<<endl;
	}

	else
	{
		cout<<"False"<<endl;
	}
}

void Length()
{
	struct node* tmp;
	tmp=Head;

	int cnt=0;

	while(tmp!=NULL)
	{
		cnt+=1;
		tmp=tmp->ptr;
	}

	cout<<cnt;
}

int main()
{
	struct node* Main;
	struct node* tmp;
	int s,x,y;
	long long int n;
	double d;

	cout<<"Enter the number Of TestCases : ";
	cin>>n;

	for(long long int i=0;i<n;i++)
	{
		cin>>s;
		if(s==1)
		{
			cin>>x>>y;
			Main=AddFirst(x,y);
		}

		if(s==2)
		{
			Main=DelFirst();
		}

		if(s==3)
		{
			cin>>x>>y;
			Main=Del(x,y);
		}

		if(s==4)
		{
			cin>>d;
			Search(d);
		}

		if(s==5)
		{
			cin>>x>>y;
			Search(x,y);
		}

		if(s==6)
		{
			Length();
		}

// To preview Linked List Live

/*		tmp=Main;
		cout<<"                   Linked List : ";
		while(tmp!=NULL)
		{
			cout<<"("<<tmp->x<<","<<tmp->y<<")";
			tmp=tmp->ptr;
		}
		cout<<endl; */
	}
	return 0;
}
