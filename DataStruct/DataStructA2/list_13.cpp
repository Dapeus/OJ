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
    for(int i = 0; i < len; i++)
    {
        DataType t;
        p->next = new LNode;
        p = p->next;
        cin>>t;
        p->data = t;
        p->next = NULL;
    }
}

int getLen(LNode *l)
{
    if(l->next == NULL)
    {
        return 0;
    }
    else
    {
        return getLen(l->next) + 1;
    }
}

int main()
{   
    int len;
    while (cin>>len)
    {
        if(len == 0)
        {
            return 0;
        }
        LNode *l;
        creatList(l, len);
        cout<<getLen(l)<<endl;
    }
    
    return 0;
}