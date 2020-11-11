#include<iostream>
#include<stack>

using namespace std;

int num[7][7] = {	//1：大于； 0：小于； 2：等于 3：不存在；
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

int main()
{
    string s;
    while(cin>>s)
    {
        if(s == "=")
        {
            return 0;
        }
        string output;
        stack<char> op;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '=')
            {
                break;
            }
            if(isdigit(s[i]))
            {
                output.push_back(s[i]);
            }
            else if(op.empty())
            {
                op.push(s[i]);
            }
            else if(getproprity(op.top(), s[i]) == 0)
            {
                op.push(s[i]);
            }
            else if(getproprity(op.top(), s[i]) == 1)
            {
                char t = op.top();
                op.pop();
                output.push_back(t);
                i--;
            }
            else if(getproprity(op.top(), s[i]) == 2)
            {
                op.pop();
            }
        }
        while (!op.empty())
        {
            char t = op.top();
            op.pop();
            output.push_back(t);
        }
        cout<<output<<endl;
    }
    return 0;
}