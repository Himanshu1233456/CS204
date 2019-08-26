#include <iostream>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

int prior(string p)
{
	if(p == "^")
	{
		return 3;
	}

	else if(p=="/" || p=="*")
	{
		return 2;
	}

	else if(p=="+" || p=="-")
	{
		return 1;
	}

	else
	{
		return -1;
	}
}

void in_post_conv(string expe[],long long int cnt,string out[])
{

	long long int i,j,o=0;
	std::stack<string> s;
	s.push("N");

	for(i=0;i<cnt;i++,o++)
	{
		if(expe[i]!="+" && expe[i]!="-" && expe[i]!="/" && expe[i]!="*" && expe[i]!="^" && expe[i]!="(" && expe[i]!=")")
		{
			out[o]=expe[i];
		}

		else if(expe[i]=="(")
		{
			s.push("(");
			o--;
		}

		else if(expe[i] == ")")
        	{
            		while(s.top() != "N" && s.top() != "(")
            		{
                		string c = s.top();
                		s.pop();
               			out[o] += c;
										o++;
            		}

            		if(s.top()=="(")
            		{
                		string c = s.top();
                		s.pop();
            		}
								o--;
        	}

		else
		{
    	while(s.top() != "N" && prior(expe[i]) <= prior(s.top()))
      {
				if(expe[i]=="^" && s.top()=="^") break;
              string c = s.top();
              s.pop();
      				out[o] += c;
							o++;
      }
      s.push(expe[i]);
			o--;
    }
	}

	while(s.top() != "N")
    {
        string c = s.top();
        s.pop();
        out[o] += c;
				o++;
    }

}

struct tree
{
	string a;
	tree *l, *r;
};

bool op(string c)
{
	if (c == "+" || c == "-" || c == "*" || c == "/" || c == "^")
	{
		return true;
	}

	else
	{
		return false;
	}
}

void trav(tree *i)
{
	if(i)
	{
		trav(i->l);
		trav(i->r);
	}
}

tree* node(string s)
{
	tree *tmp = new tree;
	tmp->l = tmp->r = NULL;
	tmp->a = s;
	return tmp;
}

tree* construct(string post[],long long int cnt)
{
    stack<tree *> tmp;
    tree *t, *t1, *t2;

    for (long long int i=0; i<cnt; i++)
    {
        if (!op(post[i]))
        {
            t = node(post[i]);
            tmp.push(t);
        }

        else
        {
            t = node(post[i]);
            t1 = tmp.top();
            tmp.pop();
            t2 = tmp.top();
            tmp.pop();
            t->r = t1;
            t->l = t2;
            tmp.push(t);
        }
    }

    t = tmp.top();
    tmp.pop();

    return t;
}

long long int convert(string s)
{
    long long int num = 0;

    if(s[0]!='-')
        for (long long int i=0; i<s.length(); i++)
            num = num*10 + (long long int(s[i])-48);

    else
        for (long long int i=1; i<s.length(); i++)
        {
            num = num*10 + (long long int(s[i])-48);
            num = num*-1;
        }

    return num;
}

long long int answ(tree* m)
{
    if (!m)
        return 0;

    else if (!m->l && !m->r)
        return convert(m->a);

    long long int a = answ(m->l);
    long long int b = answ(m->r);

    if (m->a=="+")
        return a+b;

    else if (m->a=="-")
        return a-b;

    else if (m->a=="*")
        return a*b;

		else if (m->a=="^")
		    return pow(a,b);

    return a/b;
}

int main()
{
	long long int i,j,cnt=0,k,cnt1=0,cnt2=0,l,tc;
	char c,tmp='n',chk;
	long long int a=0;
	string exp;
	string expe[50],post[50];
	tree * ext;

cin>>tc;
cin>>l;

for(long long int z=0;z<tc;z++)
{
	for(long long int x=0;x<l;x++)
	{
		cin>>exp;

		for(i=0;i<50;i++)
		{
			for(j=cnt;j<exp.length();j++)
			{
				if(exp[j]=='+' || exp[j]=='-' || exp[j]=='/' || exp[j]=='*' || exp[j]=='(' || exp[j]==')' || exp[j]=='^' || exp[j]=='=')
				{
					if(exp[j]=='-' && tmp=='(')
					{
						while(exp[j]!=')')
						{
							expe[i]+=exp[j];
							tmp=exp[j];
							j++;
							cnt+=1;
						}
						a=1;
						break;
					}

					else if(tmp=='n')
					{
						expe[i]+=exp[j];
						cnt+=1;
						tmp=exp[j];
						break;
					}

					else if(tmp=='+' || tmp=='-' || tmp=='/' || tmp=='*' || tmp=='(' || tmp==')' || tmp=='^' || tmp=='=')
					{
						expe[i]+=exp[j];
						cnt+=1;
						tmp=exp[j];
						break;
					}

					else
					{
						if(a==1)
						{
						expe[i]+=exp[j];
						cnt+=1;
						tmp=exp[j];
						a-=1;
						break;
						}

						else
						{
							i+=1;
							expe[i]+=exp[j];
							cnt+=1;
							tmp=exp[j];
							break;
						}
					}
				}

				else
				{
					expe[i]+=exp[j];
					cnt+=1;
					tmp=exp[j];
				}
			}
		}

		for(k=0;k<50;k++)
		{
			if(!expe[k].empty())
			{
				cnt1+=1;
			}
		}

		for(k=0;k<50;k++)
		{
			if(!expe[k].empty())
			{
				if(expe[k]=="(" || expe[k]==")")
				{
					cnt2+=0;
				}

				else
				{
					cnt2+=1;
				}
			}
		}

		in_post_conv(expe,cnt1,post);
		trav(ext = construct(post,cnt2));
		cout<<answ(ext)<<endl;
		cnt=0;
		cnt1=0;
		cnt2=0;
		exp.clear();
		for(long long int h=0;h<50;h++)
		{
			expe[h].clear();
			post[h].clear();
		}
		free(ext);
	}
}

	return 0;
}
