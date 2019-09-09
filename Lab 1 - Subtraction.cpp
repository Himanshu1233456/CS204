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
  int d,max;

  if(l2>l1)
  {
    d=l2-l1;
    max=l2;
    swap(n1,n2);
  }
  else
  {
    max=l1;
    d=l1-l2;
  }

  reverse(n2.begin(),n2.end());
  for(int i=0;i<d;i++)
  {
    n2.push_back('0');
  }
  reverse(n2.begin(),n2.end());

  int diff,carry=0;

  for(int i=max-1;i>=0;i--)
  {
    if(carry==0)
    {
      if((n1[i]-'0')>=(n2[i]-'0'))
      {
        diff=(n1[i]-'0')-(n2[i]-'0');
        out.push_back(diff+'0');
      }
      else if((n1[i]-'0')<(n2[i]-'0'))
      {
        diff=(n1[i]-'0'+'K'-'A')-(n2[i]-'0');
        out.push_back(diff+'0');
        carry+=1;
      }
    }
    else if(carry>0)
    {
      if((n1[i]-'0'+'A'-'B')>=(n2[i]-'0'))
      {
        diff=((n1[i]-'0'+'A'-'B')-(n2[i]-'0'));
        out.push_back(diff+'0');
        carry-=1;
      }
      else if((n1[i]-'0'+'A'-'B')<(n2[i]-'0'))
      {
        diff=((n1[i]-'0'+'K'-'A'+'A'-'B')-(n2[i]-'0'));
        out.push_back(diff+'0');
        carry+=0;
      }
    }
  }

  reverse(out.begin(),out.end());

  cout<<n1<<"\n";
  cout<<n2<<"\n";
  cout<<out<<"\n";

  return 0;
}
