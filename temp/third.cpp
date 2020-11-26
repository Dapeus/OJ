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
        DataType temp;
        p->next = new LNode;
        p = p->next;
        cin>>temp;
        p->data = temp;
        p->next = NULL;
    }
}

void print(LNode *l)
{
    l = l->next;
    while (l->next)
    {
        cout<<l->data<<" ";
        l = l->next;
    }
    cout<<l->data<<endl;
}


void FrontBackSplit(LNode *l, int len)
{
    //l = l->next;
    len/=2;
    LNode *s1 = l, *s2 = new LNode, *s1h, *s2h;
    s1h = s1;
    s2h = s2;
    for(int i = 0; i < len; i++)
    {
        s1 = s1->next;
        l = l->next;
    }
    s2->next = l->next;
    print(s2h);
    s1->next = NULL;
    print(s1h);
}


int main()
{
    int len;
    while(cin>>len)
    {
        if(len == 0)
        {
            return 0;
        }
        LNode *l;
        creatList(l, len);
        FrontBackSplit(l, len);
    }  
    return 0;
}