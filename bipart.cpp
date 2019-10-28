#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long int n, m, a, b;
  cin>>n;
  cin>>m;

  vector <long long int> cv[n+1];
  long long int chk[n+1]={0};

  for(long long int i=0;i<m;i++)
  {
    cin>>a>>b;
    cv[b].push_back(a);
    cv[a].push_back(b);
  }

  queue<long long int> q;
  long long int pr=1;
  chk[1]=1;
  q.push(1);

  while(!q.empty())
  {
    long long int k=q.front();
    q.pop();
    if(chk[k]==1)
    {
      pr=2;
    }
    else
    {
      pr=1;
    }
    for(long long int j=0;j<cv[k].size();j++)
    {
      if(chk[cv[k][j]]==0)
      {
        q.push(cv[k][j]);
      }
      if(chk[cv[k][j]]==0 || chk[cv[k][j]]==pr)
      {
        chk[cv[k][j]]=pr;
      }
      else
      {
        cout<<"NOT A BIPARTITE!"<<endl;
        return 0;
      }
    }
  }
  cout<<"BIPARTITE!"<<endl;
  return 0;
}
