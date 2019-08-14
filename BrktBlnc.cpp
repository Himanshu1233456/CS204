#include <iostream>
#include <stack>

using namespace std;

void Balance(string c)
{
	stack <char> s;
	long long int i,l=c.length();
	long long cnt=0;

	for(i=0;i<l;i++)
	{		

		if(c[i]=='(' || c[i]=='{' || c[i]=='[' || c[i]=='<')
		{
			s.push(c[i]);
			cnt+=1;
		}

		else
		{
			if(c[i]=='|')
			{
				if(s.empty())
				{
					cnt+=1;
					s.push(c[i]);
				}

				else if(s.top()!='|')
				{
					cnt+=1;
					s.push(c[i]);
				}

				else if(s.top()=='|')
				{
					s.pop();
				}

				else
				{
					continue;
				}
			}			
		}


		if(c[i]==')')
		{
			if(s.empty())
			{
				cout<<"NO"<<endl;
				return;
			}
	
			else if(s.top()=='(')
			{
				s.pop();
			}
			
			else
			{
				cout<<"NO"<<endl;
				return;
			}
		}

		if(c[i]=='}')
		{
			if(s.empty())
			{
				cout<<"NO"<<endl;
				return;
			}
	
			else if(s.top()=='{')
			{
				s.pop();
			}
			
			else
			{
				cout<<"NO"<<endl;
				return;
			}
		}

		if(c[i]==']')
		{
			if(s.empty())
			{
				cout<<"NO"<<endl;
				return;
			}
	
			else if(s.top()=='[')
			{
				s.pop();
			}
			
			else
			{
				cout<<"NO"<<endl;
				return;
			}
		}

		if(c[i]=='>')
		{
			if(s.empty())
			{
				cout<<"NO"<<endl;
				return;
			}
	
			else if(s.top()=='<')
			{
				s.pop();
			}
			
			else
			{
				cout<<"NO"<<endl;
				return;
			}
		}
/*
		if(c[i]=='|')
		{
			if(s.top()=='|')
			{
				s.pop();
			}
			
			else
			{
				cout<<"NO"<<endl;
				return;
			}
		} */
	}

	if(cnt==0)
	{
		cout<<"Not a valid input"<<endl;
		return;
	}

	if(!s.empty())
	{
		cout<<"NO"<<endl;
		return;
	}

	else
	{
		cout<<"YES"<<endl;
	}
}

int main()
{
	string c;
	long long int n,i;

	cin>>n;

	for(i=0;i<n;i++)
	{
		cin>>c;
		Balance(c);
	}

	return 0;
}

