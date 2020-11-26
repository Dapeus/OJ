#include<iostream>
#define M 10000

using namespace std;

typedef int DataType;
struct Stack
{
    DataType *base;
    DataType *top;
    int stacksize;
};

void initStack(Stack &s)
{
    s.base = new int[M];
    s.top = s.base;
    s.stacksize = M;
}

void pop(Stack &s, int &jud)
{
    if(s.top == s.base)
    {
        cout<<"POP ERROR"<<endl;
        jud = 1;
        return;
    }
    s.top--;
}

void push(Stack &s, int inp)
{
    *s.top++ = inp;
}

DataType getTop(Stack &s)
{
    return *s.top;
}

int main()
{
    int size, inp;
    while(cin>>size)
    {
        if(size == 0)
        {
            return 0;
        }
        Stack s;
        initStack(s);
        for(int i = 0; i < size; i++)
        {
            cin>>inp;
            if(inp != -1)
            {
                push(s, inp);
            }
            else
            {
                int jud = 0;
                pop(s, jud);
                if(jud == 1)
                {
                    for(;i < size - 1; i++)
                    {
                        cin>>inp;
                    }
                    break;
                }
                cout<<getTop(s)<<endl;
            }
        }
        delete(s.base);
    }

    return 0;
}