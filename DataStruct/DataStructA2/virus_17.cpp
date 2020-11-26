#include<iostream>

using namespace std;

void change(string &dv)
{
    char temp = dv[0];
    int i;
    for(i = 0; i < dv.length()-1;i++)
    {
        dv[i] = dv[i+1];
    }
    dv[i] = temp;
}

void reverse(string &dv)
{
    for(int i = 0, j = dv.length()-1; i < dv.length()/2; i++)
    {
        char t = dv[i];
        dv[i] = dv[j];
        dv[j] = t;
    }
    char t = dv[dv.length()-1];
    for(int i = 0; i < dv.length()-1; i++)
    {
        dv[i+1] = dv[i];
    }
    dv[0] = t;
}

int exist(string dv, string dp)
{
    int i = 0, j = 0, record = i;
    while(i < dp.length() && j < dv.length())
    {
        if(dp[i] == dv[j])
        {
            if(j == dv.length()-1)
            {
                return 1;
            }
            j++;
            i++;
        }
        else
        {
            j = 0;
            i = ++record;
        }
    }
    return 0;
}

void monitor(string dv, string dp)
{
    int jud = 0;
    for(int i = 0; i < dv.length(); i++)
    {
        change(dv);
        int x = exist(dv, dp);
        if(x == 1)
        {
            jud = 1;
            break;
        }
    }
    reverse(dv);
    //cout<<dv<<endl;
    for(int i = 0; i < dv.length(); i++)
    {
        change(dv);
        int x = exist(dv, dp);
        if(x == 1)
        {
            jud = 1;
            break;
        }
    }
    if(jud == 1)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    
}

int main()
{
    string Dv,Dp;
    while (cin>>Dv>>Dp)
    {
        if(Dv == "0" && Dp == "0")
        {
            return 0;
        }
        monitor(Dv, Dp);
    }
    system("pause");
    return 0;
}