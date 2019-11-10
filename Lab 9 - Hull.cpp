#include <bits/stdc++.h>
using namespace std;

struct Point
{
  long long int x;
  long long int y;
};

Point p0;

Point prev(stack <Point> &S)
{
  Point tmp = S.top();
  S.pop();
  Point prv = S.top();
  S.push(tmp);
  return prv;
}

void swap(Point &a, Point &b)
{
  Point tmp = a;
  a = b;
  b = tmp;
}

long long int dist(Point a, Point b)
{
  return (((a.x - b.x)*(a.x - b.x))+((a.y - b.y)*(a.y - b.y)));
}

int rotat(Point a, Point b, Point c)
{
  long long int cross = (((b.y - a.y)*(c.x - b.x))-((b.x - a.x)*(c.y - b.y)));

  if(cross==0)
  {
    return 0;
  }
  return (cross > 0)? 1:2;
}

int compare(const void *a, const void *b)
{
  Point *tmp1 = (Point *)a;
  Point *tmp2 = (Point *)b;

  int o = rotat(p0, *tmp1, *tmp2);

  if(o==0)
  {
    return (dist(p0, *tmp2) >= dist(p0, *tmp1))? -1:1;
  }
  return (o == 2)? -1:1;
}

void Hull(Point space[], long long int k)
{
  long long int xmin = space[0].x, min = 0;

  for(long long int i=1;i<k;i++)
  {
    long long int tmpy = space[i].x;

    if((tmpy < xmin) || (xmin == tmpy && space[i].y < space[min].y))
    {
      xmin = space[i].x, min = i;
    }
  }

  swap(space[0], space[min]);

  p0 = space[0];
  qsort(&space[1], k-1, sizeof(Point), compare);

  long long int m=1;

  for(long long int i=1; i<k; i++)
  {
    while(i < k-1 && rotat(p0, space[i], space[i+1]) == 0)
    {
      i++;
    }
    space[m] = space[i];
    m++;
  }

  if(m < 3) return;

  stack<Point> S;

  S.push(space[0]);
  S.push(space[1]);
  S.push(space[2]);

  for(long long int i=3; i<m; i++)
  {
    while(rotat(prev(S), S.top(), space[i]) != 2)
    {
      S.pop();
    }
    S.push(space[i]);
  }

  cout<<S.size()<<endl;

  while(!S.empty())
  {
    Point p = S.top();
    cout<<"("<<p.x<<","<<p.y<<") ";
    S.pop();
  }
}

int main()
{
  long long int k,i;
  cin>>k;

  Point space[k];

  for(i=0;i<k;i++)
  {
      cin>>space[i].x;
      cin>>space[i].y;
  }

  Hull(space, k);
  return 0;
}
