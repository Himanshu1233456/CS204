#include <bits/stdc++.h>
using namespace std;

int main()
{
  string n1,n2;
  string out;

  cin>>n1;
  cin>>n2;

  int l1=n1.length();
  int l2=n2.length();
  int d;

  if(l1>l2)
  {
    d=l1-l2;
    reverse(n2.begin(),n2.end());
    for(int i=0;i<d;i++)
    {
      n2.push_back('0');
    }
    reverse(n2.begin(),n2.end());
  }
  else
  {
    d=l2-l1;
    reverse(n1.begin(),n1.end());
    for(int i=0;i<d;i++)
    {
      n1.push_back('0');
    }
    reverse(n1.begin(),n1.end());
  }

  int sum,carry=0;

  for(int i=l1-1;i>=0;i--)
  {
    sum = (((n1[i]-'0')+(n2[i]-'0'))+carry);
    out.push_back(sum%10+'0');
    carry=sum/10;
  }

  reverse(out.begin(),out.end());

  cout<<out<<"\n";

  return 0;
}
