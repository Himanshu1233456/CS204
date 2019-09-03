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

void in_post_conv(string expe[],int cnt,string out[])
{

	int i,j,o=0;
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

tree* construct(string post[],int cnt)
{
    stack<tree *> tmp;
    tree *t, *t1, *t2;

    for (int i=0; i<cnt; i++)
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

int convert(string s)
{
    int num = 0;

    if(s[0]!='-')
        for (int i=0; i<s.length(); i++)
            num = num*10 + (int(s[i])-48);

    else
        for (int i=1; i<s.length(); i++)
        {
            num = num*10 + (int(s[i])-48);
            num = num*-1;
        }

    return num;
}

int answ(tree* m)
{
    if (!m)
        return 0;

    else if (!m->l && !m->r)
        return convert(m->a);

    int a = answ(m->l);
    int b = answ(m->r);

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

struct charvalue
{
	int v;
	string c;
};

bool assign(string expe[],int cnt)
{
	for(int i=0;i<cnt;i++)
	{
		if(expe[i]=="=")
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int i,j,cnt=0,k,cnt1=0,cnt2=0,l,tc;
	char c,tmp='n',chk;
	int a=0;
	string exp;
	string expe[10000],post[10000];
	tree * ext;

cin>>tc;
cin>>l;

for(int z=0;z<tc;z++)
{
	for(int x=0;x<l;x++)
	{
		cin>>exp;

		for(i=0;i<10000;i++)
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

		for(k=0;k<10000;k++)
		{
			if(!expe[k].empty())
			{
				cnt1+=1;
			}
		}

		for(k=0;k<10000;k++)
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
		for(int h=0;h<10000;h++)
		{
			expe[h].clear();
			post[h].clear();
		}
		free(ext);
	}
}

if(assign(expe,cnt1))
{
	for(int k=0;k<cnt1;k++)
	{
		if(expe[k]=="=")
		{
			int idx=k;
		}
	}
}

	return 0;
}
