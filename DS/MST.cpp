#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

int P[MAX],R[MAX];
int node, e, cost;

struct edge
{
  int u,v;
  int c;
};

edge Edge[MAX*MAX];
edge path[MAX];

int com(const void* xy, const void* xz)
{
  edge* x = (edge*)xy;
  edge* y = (edge*)xz;
  return (x->c - y->c);
}

void In()
{
  int i;
  for(i=1;i<=node;i++)
  {
    P[i]=i;
    R[i]=1;
  }
}

int find(int n)
{
  if(P[n]!=n)
  P[n]=find(P[n]);
  return P[n];
}

void link(int x, int y)
{
  if(R[x]>R[y])
  {
    P[y]=x;
  }
  else
  {
    P[x]=y;
    if(R[x]==R[y])
    R[y]++;
  }
}

void krus()
{
  int x,y,t=0;
  cost=0;
  for(int i=0;i<e;i++)
  {
    x=find(Edge[i].u);
    y=find(Edge[i].v);
    if(x!=y)
    {
      path[t++]=Edge[i];
      link(x,y);
      cost+=Edge[i].c;
      if(t==node-1) break;
    }
  }
}

void cal()
{
  qsort(Edge,e,sizeof(edge),com);
  krus();
  cout<<"Cost: "<<cost<<endl;
  for(int i=0;i<node-1;i++)
  {
    cout<<path[i].u<<" "<<path[i].v<<endl;
  }
}

int main()
{
  int i;
  while(cin>>node>>e)
  {
    In();
    for(i=0;i<e;i++)
    cin>>Edge[i].u>>Edge[i].v>>Edge[i].c;
    cal();
  }
  return 0;
}
