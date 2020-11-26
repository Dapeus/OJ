#include<iostream>

#define N 10000

using namespace std;

typedef char DataType;
typedef struct Stack
{
    DataType* base;
    DataType* top;
    int stacksize;
};

void initStack(Stack &s)
{
    s.base = new DataType[N];
    if(!s.base)
        return;
    s.top = s.base;
    s.stacksize = N;
}

void push(Stack &s, DataType a)
{
    if(s.top - s.base == s.stacksize)
    {
        return;
    }
    *s.top++ = a;
}

char pop(Stack &s)
{
    --s.top;
    return *s.top;
}

int main()
{
    
    string a;
    while(cin>>a)
    {
        int judge = 0;
        string jud;
        Stack s,s1;
        initStack(s);
        initStack(s1);
        if(a == "0")
            return 0;
        int len = a.length();

        for(int i = 0; i < len; i++)
        {
            push(s, a[i]);
        }
        for(int i = 0; i < len; i++)
        {
            jud[i] = pop(s);
            //cout<<jud[i]<<endl;
        }
        for(int i = 0; i < len; i++)
        {
            if(jud[i] != a[i])
            {
                cout<<"NO"<<endl;
                judge = 1;
                break;
            }
        }
        if(judge == 1)
        {}
        else
        {
            cout<<"YES"<<endl;
        }


    }

    return 0;
}