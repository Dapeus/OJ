#include<iostream>
#define M 10000

using namespace std;

typedef char DataType;
struct Stack
{
    DataType *base;
    DataType *top;
    int stacksize;
};

void initStack(Stack &s)
{
    s.base = new DataType[M];
    s.top = s.base;
    s.stacksize = M;
}

void pop(Stack &s, int &jud)
{
    if(s.top == s.base)
    {
        cout<<"FALSE"<<endl;
        jud = 1;
        return;
    }
    s.top--;
}

void push(Stack &s, char inp)
{
    *s.top++ = inp;
}

DataType getTop(Stack &s)
{
    return *s.top;
}

int main()
{
    string inp;
    while(cin>>inp)
    {
        int jud = 0, cnt = 0;
        int size = inp.length();
        if(inp == "0")
        {
            return 0;
        }
        Stack s;
        initStack(s);
        for(int i = 0; i < size; i++)
        {
            if(inp[i] == 'I')
            {
                push(s, inp[i]);
                cnt++;
            }
            else
            {
                jud = 0;
                pop(s, jud);
                cnt--;
                if(jud == 1)
                {
                    cnt = 0;
                    break;
                }
                //cout<<getTop(s)<<endl;
            }
        }
        if(jud == 0 && cnt == 0)
        {
            cout<<"TRUE"<<endl;
        }
        else if(cnt != 0)
        {
            cout<<"FALSE"<<endl;
        }
        delete(s.base);
    }

    return 0;
}