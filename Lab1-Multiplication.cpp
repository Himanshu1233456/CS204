#include <bits/stdc++.h>
using namespace std;

void Add(string a, string b,int cnt)
{
  int l1=a.length();
  int l2=b.length();
  int d;

  cout<<l1;


  if(l1>l2)
  {
    d=l1-l2;
    reverse(b.begin(),b.end());
    for(int i=0;i<d;i++)
    {
      b.push_back('0');
    }
    reverse(b.begin(),b.end());
  }
  else
  {
    d=l2-l1;
    reverse(a.begin(),a.end());
    for(int i=0;i<d;i++)
    {
      a.push_back('0');
    }
    reverse(a.begin(),a.end());
  }

  int sum,carry=0;

  for(int i=l1-1;i>=0;i--)
  {
    sum = (((a[i]-'0')+(b[i]-'0'))+carry);
    b.push_back(sum%10+'0');
    carry=sum/10;
  }
}

int main()
{
  string n1,n2;
  string out1;
  string out2;

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

  int Mult,Carry=0,cnt=-1;

  for(int i=max-1;i>=0;i--)
  {
    for(int j=max-1;j>=0;j--)
    {
      if(j!=0)
      {
        Mult=((n2[i]-'0')*(n1[j]-'0')+Carry);
        out1.push_back(Mult%10+'0');
        Carry=Mult/10;
      }
      else if(j==0)
      {
        Mult=((n2[i]-'0')*(n1[j]-'0')+Carry);
        out1.push_back(Mult%10+'0');
        Carry=Mult/10;
        out1.push_back(Carry+'0');
        Carry=0;
      }
    }
    cnt+=1;
    Add(out1,out2,cnt);
    out1.clear();
  }

  reverse(out2.begin(),out2.end());

  cout<<out2<<"\n";

  return 0;
}
