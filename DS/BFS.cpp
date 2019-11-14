#include<bits/stdc++.h>
#define MAX 1000

using namespace std;

int cost[MAX][MAX],i,j,k,n,qu[MAX],front,rare,v,visit[MAX],visited[MAX];

main()
{
int m;
cin >> n;
cin >> m;
for(k=1;k<=m;k++)
{
cin >>i>>j;
cost[i][j]=1;
}
cout <<"Initial Vertex: "<<endl;
cin >>v;
cout <<"Visitied vertices\n";
cout <<v<<" ";
visited[v]=1;
k=1;
while(k<n)
{
for(j=1;j<=n;j++)
if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
{
visit[j]=1;
qu[rare++]=j;
}
v=qu[front++];
cout<<v << " ";
k++;
visit[v]=0;
visited[v]=1;
}
}
