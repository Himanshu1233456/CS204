#include<bits/stdc++.h>
using namespace std;

long long int partition(long long int Dist[], long long int l, long long int r, long long int k);

long long int SubMedian(long long int Dist[], long long int n)
{
	sort(Dist, Dist+n);
	return Dist[n/2];
}

long long int Median(long long int Dist[], long long int l, long long int r, long long int k)
{
	if (k > 0 && k <= r - l + 1)
	{
		long long int n = r-l+1;
		long long int i, median[(n+4)/5];
		for (i=0; i<n/5; i++)
			median[i] = SubMedian(Dist+l+i*5, 5);
		if (i*5 < n)
		{
			median[i] = SubMedian(Dist+l+i*5, n%5);
			i++;
		}

		long long int medOfMed = (i == 1)? median[i-1]:
								Median(median, 0, i-1, i/2);

		long long int pos = partition(Dist, l, r, medOfMed);

		if (pos-l == k-1)
			return Dist[pos];
		if (pos-l > k-1)
			return Median(Dist, l, pos-1, k);

		return Median(Dist, pos+1, r, k-pos+l-1);
	}
	return INT_MAX;
}

void swap(long long int *a, long long int *b)
{
	long long int temp = *a;
	*a = *b;
	*b = temp;
}

long long int partition(long long int Dist[], long long int l, long long int r, long long int x)
{
	long long int i;
	for (i=l; i<r; i++)
		if (Dist[i] == x)
		break;
	swap(&Dist[i], &Dist[r]);

	i = l;
	for (long long int j = l; j <= r - 1; j++)
	{
		if (Dist[j] <= x)
		{
			swap(&Dist[i], &Dist[j]);
			i++;
		}
	}
	swap(&Dist[i], &Dist[r]);
	return i;
}

int main()
{
  long long int tc,k,i,j,x,y,p=0;
  cin>>tc;

  for(i=0;i<tc;i++)
  {
    cin>>k;
    long long int Dist[k];

    for(j=0;j<k;j++)
    {
      cin>>x;
      cin>>y;
      long long int d=((x*x)+(y*y));
      Dist[p]=d;
      p++;
    }
    cout<<sqrt(Median(Dist,0,k-1,((k+1)/2)))<<endl;
  }

  return 0;
}
