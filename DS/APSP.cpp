#include <bits/stdc++.h>
#define max 1000
#define inf 999
using namespace std;

int p[max][max];

void allpairshort(int a[max][max], int n)
{
    int k, i, j;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (a[i][k] + a[k][j] < a[i][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                    p[i][j] = k;
                }
            }
        }
    }
}

void shortest(int i, int j)
{
    int k = p[i][j];
    if (k > 0)
    {
        shortest(i, k);
        cout<<"  "<<k<<"  ";
        shortest(k, j);
    }
}

void findpath(int a[max][max], int i, int j, int n)
{
    if (a[i][j] < inf)
    {
        cout<<"  "<<i<<"  ";
        shortest(i, j);
        cout<<"  "<<j<<" ";
    }
}

int main()
{
    int i, j;
    int a[][max] = {{0, 5, inf, 7, 13},
                   {inf, 0 , 2, inf, inf},
                   {inf, inf , 0, 3, 10},
                   {inf, inf , 8, 0, 1},
                   {inf, inf , inf, inf, 0},
                  };

    allpairshort(a, 5);
    for(int i=0;i<5;i++)
    {
      for(int j=0;j<5;j++)
      {
        cout<<a[i][j]<<" ";
      }
      cout<<endl;
    }
    return 0;
}
