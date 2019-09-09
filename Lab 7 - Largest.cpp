#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long int tc,l,i,j,k;
  vector <string> in;
  string a;

  cin>>tc;

  for(i=0;i<tc;i++)
  {
    cin>>l;

    for(j=0;j<l;j++)
    {
      cin>>a;
      in.push_back(a);
    }

    sort(in.begin(), in.end(), [](string &a, string &b)
      {
        string tmp1 = a+b;
        string tmp2 = b+a;
        return tmp1>tmp2;
      });

    for(k=0;k<in.size();k++)
    {
      cout<<in[k];
    }

    cout<<endl;
    in.clear();
  }

  return 0;
}
