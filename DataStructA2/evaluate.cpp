#include<iostream>
#include<stack>
#include<iomanip>

using namespace std;

int num[7][7] = {	//1：大于； 0：等于； 2：小于 3：不存在；
	{1,1,0,0,0,1,1},
	{1,1,0,0,0,1,1},
	{1,1,1,1,0,1,1},
	{1,1,1,1,0,1,1},
	{0,0,0,0,0,2,3},
	{1,1,1,1,3,1,1},
	{0,0,0,0,0,3,2}
};

int getproprity(char ctop, char ch)
{
	int jud1,jud2;
	if(ctop == '+')
	{
		jud1 = 0;
	}
	else if(ctop == '-')
	{
		jud1 = 1;
	}
	else if(ctop == '*')
	{
		jud1 = 2;
	}
	else if(ctop == '/')
	{
		jud1 = 3;
	}
	else if(ctop == '(')
	{
		jud1 = 4;
	}
	else if(ctop == ')')
	{
		jud1 = 5;
	}
	else if(ctop == '=')
	{
		jud1 = 6;
	}
	else
	{
		return -1;
	}

	if(ch == '+')
	{
		jud2 = 0;
	}
	else if(ch == '-')
	{
		jud2 = 1;
	}
	else if(ch == '*')
	{
		jud2 = 2;
	}
	else if(ch == '/')
	{
		jud2 = 3;
	}
	else if(ch == '(')
	{
		jud2 = 4;
	}
	else if(ch == ')')
	{
		jud2 = 5;
	}
	else if(ch == '=')
	{
		jud2 = 6;
	}
	else
	{
		return -1;
	}
	
	return num[jud1][jud2];
}

int isOperator(char ch)
{
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/' )
		return 1;
	else
		return 0;
}

double caculate(double a, double b, char ctop)
{
	double ret = 0;
	if(ctop == '+')
	{
		ret = a + b;
	}
	else if(ctop == '-')
	{
		ret = a - b;
	}
	else if (ctop == '*')
	{
		ret = a * b;
	}
	else if (ctop == '/')
	{
		ret = a / b;
	}
	return ret;
}

int main()
{
	double result, a, b, num;
    stack<char> tr;
	stack<double> nd;
    char ctop;
	string ch;
	while(cin>>ch)
	{
		if(ch=="=")
		{
			return 0;
		}
		for(int i = 0; i < ch.length() && ch[i] != '=';)
		{
			if(isdigit(ch[i]))
			{
				num = 0;
				num = atof(&ch[i]);
				//cout<<num<<endl;
				nd.push(num);
				while(isdigit(ch[i]))
				{
					i++;
				}
				if(ch[i] == '.')
				{
					i++;
					while(isdigit(ch[i]))
					{
						i++;
					}
				}
				//cout<<ch[i]<<endl;
			}
			else if(ch[i] == '(')
			{
				tr.push(ch[i]);
				i++;
			}
			else
			{
				if(tr.empty())
				{
					tr.push(ch[i]);
					i++;
				}
				else
				{
					while(!tr.empty())
					{
						ctop = tr.top();
						//cout<<ctop<<" "<<ch[i]<<" "<<getproprity(ctop, ch[i])<<endl;
						if(getproprity(ctop, ch[i]) == 1)
						{

							result = 0;
							b = nd.top(); nd.pop();	//第二个数字
							a = nd.top(); nd.pop();	//第一个数字

							result = caculate(a,b,ctop);
							nd.push(result);
							tr.pop();
							//tr.push(ch[i]);
							//i++;
							
						}
						else if(getproprity(ctop, ch[i]) == -1)
						{
							break;
						}
						else if(getproprity(ctop, ch[i]) == 2)
						{
							i++;
							tr.pop();
							// tr.push(ch[i]);
							// i++;
						}
						else
						{
							tr.push(ch[i]);
							i++;
							break;
						}
					}
					
				}

			}
		}
		while(!tr.empty())
		{
			ctop = tr.top();
			result = 0;
			a = nd.top();nd.pop();
			b = nd.top();nd.pop();

			result = caculate(a, b, ctop);
			tr.pop();
			nd.push(result);
		}
		cout<<fixed<<setprecision(2)<<nd.top()<<endl;
	}
	//system("pause");
    return 0;
}