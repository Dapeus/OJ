#include<iostream>

using namespace std;

typedef int DataType;
struct LNode
{
    DataType data;
    LNode *next;
};

void creatList(LNode *&l, int len)
{
    l = new LNode;
    LNode *p = l;
    DataType inp;
    for(int i = 0; i < len; i++)
    {
        cin>>inp;
        p->next = new LNode;
        p = p->next;
        p->data = inp;
        p->next = NULL;
    }
}

int getMax(LNode *l)
{
    if(l->next == NULL)
    {
        return l->data;
    }
    else
    {
        int t = getMax(l->next);
        if(l->data >= t)
        {
            return l->data;
        }
        else
        {
            return t;
        }
    }
}

int main()
{
    int len;
    LNode *l,*h;
    while(cin>>len)
    {
        if(len == 0)
        {
            return 0;
        }
        creatList(l, len);
        cout<<getMax(l->next)<<endl;
    }
    return 0;
}