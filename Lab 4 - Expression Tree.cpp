#include <iostream>
#include <stack>

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

void in_post_conv(string expe[],int cnt)
{
	int i,j,o=0;
	string tmp="m";
	string out[50];
	std::stack<string> s;
	s.push("N");

	for(i=0;i<cnt;i++,o++)
	{
		tmp=expe[i];

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

	for(j=0;j<50;j++)
	{
		cout<<out[j]<<" ";
	}
}

int main()
{
	int i,j,cnt=0,k,cnt1=0;
	char c,tmp='n';
	string exp;
	string expe[50];

	cin>>exp;

	cout<<"String : "<<exp<<endl;

	for(i=0;i<50;i++)
	{
		for(j=cnt;j<exp.length();j++)
		{
			if(exp[j]=='+' || exp[j]=='-' || exp[j]=='/' || exp[j]=='*' || exp[j]=='(' || exp[j]==')' || exp[j]=='^')
			{
				if(tmp=='n')
				{
					expe[i]+=exp[j];
					cnt+=1;
					tmp=exp[j];
					break;
				}

				else if(tmp=='+' || tmp=='-' || tmp=='/' || tmp=='*' || tmp=='(' || tmp==')' || tmp=='^')
				{
					expe[i]+=exp[j];
					cnt+=1;
					tmp=exp[j];
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

	for(k=0;k<cnt1;k++)
	{
		cout<<expe[k]<<endl;
	}

cout<<"---------"<<endl;

 in_post_conv(expe,cnt1);

	return 0;
}
