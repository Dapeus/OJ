#include<iostream>
#define M 1000

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

void GetNext(string t, int next[])
{
	int k = -1, j = 0;
    next[0] = -1;
    while (j < t.length())
    {
        if(k == -1 || t[j] == t[k])
        {
            j++;k++;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
}

int KMP(string dv, string dp, int next[])
{
    int i = 0, j = 0, record = i;
    while(j < int(dv.length()) && i < dp.length())
    {
        if(j == -1 || dp[i] == dv[j])
        {
            j++;
            i++;
        }
        else
        {
            j = next[j];
        }
        //cout<<"j:"<<j<<"dv.length:"<<dv.length()<<endl;
        //cout<<"i:"<<i<<"dp.length:"<<dp.length()<<endl;
    }
    if(j >= dv.length())
    {
        return 1;
    }   
    else
    {
        return 0;
    }
}

void monitor(string dv, string dp)
{
    int jud = 0;
    int next[M] = { -1 };
    GetNext(dv, next);
    for(int i = 0; i < dv.length(); i++)
    {
        change(dv);
        int x = KMP(dv, dp, next);
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
        int x = KMP(dv, dp, next);
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