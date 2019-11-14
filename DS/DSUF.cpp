#include<bits/stdc++.h>
using namespace std;

struct Edge
{
    int src,dest;
};

struct Graph
{
    int V;
    int E;
    struct Edge *edge;
};

struct subset
{
    int root;
    int rank;
};

struct Graph* createGraph(int V,int E)
{
    struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->V=V;
    graph->E=E;
    graph->edge=(struct Edge*)malloc(sizeof(struct Edge));
    return graph;
}

int find(struct subset subsets[],int x)
{
    if(subsets[x].root==x)return x;
    subsets[x].root=find(subsets,subsets[x].root);
    return subsets[x].root;
}

void Union(struct subset subsets[],int x,int y)
{
    int set1=find(subsets,x);
    int set2=find(subsets,y);
    if(subsets[set1].rank>subsets[set2].rank)
    {
        subsets[set2].root=set1;
    }

    else if(subsets[set1].rank<subsets[set2].rank)
    {
        subsets[set1].root=set2;
    }
    else
    {
        subsets[set1].root=set2;
        subsets[set2].rank++;
    }
}

int isCycle(struct Graph* graph)
{
    struct subset subsets[graph->V];
    for(int i=0;i<graph->V;i++)
    {
        subsets[i].root=i;
        subsets[i].rank=0;
    }
    for(int i =0;i<graph->E;i++)
    {
        int x=find(subsets,graph->edge[i].src);
        int y=find(subsets,graph->edge[i].dest);
        if(x==y)return 1;
        Union(subsets,x,y);
    }
    return 0;
}

int main()
{
    int v,e;
    cin>>v>>e;
    struct Graph* graph=createGraph(v,e);
    for(int i=0;i<e;i++)
    {
      int x,y;
      cin>>x>>y;
      graph->edge[i]={x,y};
    }
    if(isCycle(graph))cout<<"YES";
    else cout<<"NO";
}
