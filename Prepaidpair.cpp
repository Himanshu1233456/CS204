#include <bits/stdc++.h>
using namespace std;

void insert(vector <pair<long long int, long long int>> list, long long int id, long long int val)
{
  if(list.empty()==true)
  {
    int i=0;
    pair<long long int, long long int> tmp;

    tmp.first=id;
    tmp.second=val;

    list.push_back(tmp);

    for(int j=0;j<list.size();j++)
    {
      cout<<"(";
      cout<<list[j].first<<","<<list[j].second;
      cout<<")";
      cout<<endl;
    }
    return;
  }

  else
  {
    int f,l,m;
    f=0;
    l=list.size()-1;

    while(f<=l)
    {
        m=(f+l)/2;
        if(id==list[m].first)
            list[m].second=list[m].second+val;
        else
            if(list[m].first>list[m].first)
                f=m+1;
            else
                l=m-1;
    }
  }

  pair<long long int, long long int> tmp;

  tmp.first=id;
  tmp.second=val;

  list.push_back(tmp);

  for(int j=0;j<list.size();j++)
  {
    cout<<"(";
    cout<<list[j].first<<","<<list[j].second;
    cout<<")";
    cout<<endl;
  }
  return;
}

bool sortsec(const pair<long long int, long long int> &a, const pair<long long int, long long int> &b)
{
    return (a.second < b.second);
}

int main()
{
  long long int k=0,n,cnt,id,val,q;
  int f;
  vector <pair<long long int, long long int>> list;

  cin>>n;
  cin>>q;

  for(int i=0; i<q; i++)
  {

    cin>>f;

    if(f==1)
    {
      cin>>id;
      cin>>val;
      insert(list,id,val);
    }

    if(f==2)
    {
      sort(list.begin(), list.end(), sortsec);
      cout<<list[0].second<<endl;
    }
  }

  return 0;
}
