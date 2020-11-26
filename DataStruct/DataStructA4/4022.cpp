//基于链表的简单选择排序

#include<iostream>

using namespace std;

typedef int DataType;
struct LNode
{
    DataType data;
    LNode *next;
};

void createLNode(LNode *&l, int n)
{
    l = new LNode;
    LNode *p = l;
    DataType t;
    for(int i = 0; i < n; i++)
    {
        cin>>t;
        p->next = new LNode;
        p = p->next;
        p->data = t;
        p->next = NULL;
    }
}

void sort(LNode *l)
{
    LNode *p = l->next;
    LNode *t = l->next;
    while(p)
    {
        int min = 999;
        t = p;
        while(t)
        {
            if(t->data < min)
            {
                min = t->data;
            }
            t = t->next;
        }
        LNode *pp = l->next;
        while (1)
        {
            if(min == pp->data)
            {
                pp->data = p->data;
                p->data = min;
                break;
            }
            pp = pp->next;
        }
        p = p->next;
    }
}

void printL(LNode *l)
{
    l = l->next;
    while(l->next)
    {
        cout<<l->data<<" ";
        l = l->next;
    }
    cout<<l->data<<endl;
}

int main()
{
    int n;
    while (cin>>n && n != 0)
    {
        LNode *l;
        createLNode(l, n);
        sort(l);
        printL(l);
    }
    system("pause");
    return 0;
}