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
    q.rear = 0;
    q.front = 0;
    q.tag = 0;
}

void enQueue(Queue &q, DataType inp, int len)
{
    q.base[(q.rear++)%len] = inp;
    if(q.rear == q.front)
    {
        q.tag = 1;
    }
}

void enQueueH(Queue &q, DataType inp, int len)
{
    q.base[(q.rear++)%len] = inp;
    if(q.rear == q.front)
    {
        q.tag = 1;
    }
}

void enQueueR(Queue &q, DataType inp, int len)
{
    q.base[(len + q.front--)%len] = inp;
}

void delQueue(Queue &q, int len)
{
    q.front++;
    if(q.front == q.rear)
    {
        q.tag = 1;
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
        while(q.tag != 1)
        {
            
            delQueue(q, len);
            if(q.tag == 1)
            {
                cout<<q.base[q.front-1]<<endl;
                break;
            }
            else
            {
                cout<<q.base[q.front-1]<<" ";
            }
            
        }
    }
    return 0;
}