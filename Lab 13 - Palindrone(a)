#include <bits/stdc++.h>
using namespace std;
#define M 1000000007

int main()
{
    long long n;
    cin>>n;

    string word[n];
    for(int i=0;i<n;i++)
    {
      cin>>word[i];
    }

    sort(word,word+n);

    for(int i=0 ; i<n;i++)
    {
        string temp = word[i];
        reverse(temp.begin(),temp.end());
        if(temp == word[i]) continue;
        if(binary_search(word,word+n,temp))
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}
