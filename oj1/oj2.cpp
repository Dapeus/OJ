#include<iostream>
#define M 1000
using namespace std;

typedef int DataTpye;
struct Stack
{
    DataTpye *base;
    DataTpye *min;
    int top;
};

void initStack(Stack &s)
{
    s.base = new int[M];
    s.min = new int[M];
    s.top = -1;
}

void push(Stack &s, DataTpye x)
{
    if(s.top == -1)
    {
        s.min[++s.top] = x;
    }
    else 
    {
        if(x < s.min[s.top-1])
        {
            s.min[++s.top] = x;
        }
    }
    s.base[s.top] = x;
}

int pop(Stack &s, int &cnt)
{
    if(s.top == 0)
    {
        return 0;
    }
    s.top--;
    cnt--;
    return s.base[s.top];
}

int top(Stack &s)
{
    if(s.top == 0)
    {
        return 0;
    }
    return s.base[s.top];
}

int getMin(Stack s, int cnt)
{
    // int find = s.base[0];
    // for(int i = 1; i < cnt; i++)
    // {
    //     if(s.base[i] < find)
    //     {
    //         find = s.base[i];
    //     }
    // }
    // return find;
    return s.min[s.top];
}

int main()
{
    Stack s;
    initStack(s); 
    string in;
    int cnt = 0;
    
    while (cin>>in)
    {
        if(in == "000")
        {
            break;
        }
        char chan[5] = { 0 };
        for(int i = 0; i < in.length(); i++)
        {
            chan[i] = in[i];
        }
        double x = atof(chan);
        //cout<<"x"<<x<<endl;
        push(s,x);
        cnt++;
    }
    cout<<getMin(s, cnt)<<endl;
    pop(s, cnt);pop(s, cnt);
    cout<<top(s)<<endl;
    cout<<getMin(s, cnt)<<endl;

    system("pause");
    return 0;
}