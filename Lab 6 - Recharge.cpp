#include <bits/stdc++.h>

using namespace std;

struct compare {
    bool operator()(const pair<int, int>& value,
                                const int& key)
    {
        return (value.first < key);
    }
    bool operator()(const int& key,
                    const pair<int, int>& value)
    {
        return (key < value.first);
    }
};

void insert(vector <pair<long long int, long long int>> &vect, long long int id, long long int val)
{
  if(vect.empty()==true)
  {
    pair<long long int, long long int> tmp;

    tmp.first=id;
    tmp.second=val;

    vect.push_back(tmp);
    return;
  }

  else
  {
    sort(vect.begin(), vect.end(), [](auto &left, auto &right)
    {
      return left.second < right.second;
    });
    if(binary_search(vect.begin(),vect.end(),id, compare()))
    {
      vect[lower_bound(vect.begin(),vect.end(),id,compare()) - vect.begin()].second+=val;
      return;
    }
  }

  pair<long long int, long long int> tmp;
  tmp.first=id;
  tmp.second=val;

  vect.push_back(tmp);
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

  for(long long int i=0; i<q; i++)
  {
    cin>>f;

    if(f==1)
    {
      cin>>id;
      cin>>val;
      insert(list,id,val);
    }

    else if(f==2)
    {
      sort(list.begin(), list.end(), [](auto &left, auto &right)
      {
        return left.second < right.second;
      });
      cout<<list[list.size()-1].first<<"<--------"<<endl;
    }
  }

  return 0;
}
