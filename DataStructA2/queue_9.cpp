#include<iostream>
#define M 1000

using namespace std;

typedef int DataType;
struct Queue
{
    DataType *base;
    int front;
    int rear;
    int tag;
};

void initQueue(Queue &q)
{
    q.base = new DataType[M];
    q.front = q.rear = 0;
    q.tag = 0;
}

void enQueue(Queue &q, DataType inp, int len)
{
    if((q.rear+1)%len == q.front)
    {
        q.base[(q.rear++)%len] = inp;
        q.tag = 1;  //队满
        return;
    }
    else
    {
        q.base[(q.rear++)%len] = inp;

    }
}

void delQueue(Queue &q, int len)
{
    if(q.front == q.rear)
    {
        q.tag = 0;
        return;
    }
    else
    {
        q.front++;

    }    
}

int main()
{
    int len;
    while(cin>>len)
    {
        Queue q;
        initQueue(q);
        if(len == 0)
        {
            return 0;
        }
        for(int i = 0; i < len; i++)
        {
            DataType inp;
            cin>>inp;
            enQueue(q, inp, len);
        }
        for(int i = len; i > 0; i--)
        {
            
            delQueue(q, len);
            
            if(i == 1)
            {
                cout<<q.base[q.front-1]<<endl;
            }
            else
            {
                cout<<q.base[q.front-1]<<" ";
            }
        }
    }
    return 0;
}