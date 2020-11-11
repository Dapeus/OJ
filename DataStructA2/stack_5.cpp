#include<iostream>
#include<iomanip>
#include<stack>

#define M 1000

using namespace std;

double caculate(double a, double b, char ctop)
{
	double ret = 0;
	if(ctop == '+')
	{
		ret = a + b;
	}
	else if(ctop == '-')
	{
		ret = b - a;
	}
	else if (ctop == '*')
	{
		ret = a * b;
	}
	else if (ctop == '/')
	{
		ret = b / a;
	}
	return ret;
}

int main()
{
    stack<double> nd;
    string s;
    int cnt = 0;
    while(1)
    {
        cin>>s;
        if(s == "=")
        {
            return 0;
        }
        int jud = 0;
        int len = s.length();
        for(int i = 0; i < len;)
        {
            if(s[i] == '=')
            {
                jud = 1;
                break;
            }
            if(isdigit(s[i]))
            {
                double num = atof(&s[i]);
                nd.push(num);
                while(isdigit(s[i]))
                {
                    i++;
                }
                if(s[i] == '.')
                {
                    i++;
                    while(isdigit(s[i]))
                    {
                        i++;
                    }
                }
            }
            else
            {
                double num1 = nd.top();nd.pop();
                double num2 = nd.top();nd.pop();
                nd.push(caculate(num1, num2, s[i]));
                i++;
            }
        }
        if(jud == 1)
        {
            cout<<fixed<<setprecision(2)<<nd.top()<<endl;
        }
    }
    return 0;
}