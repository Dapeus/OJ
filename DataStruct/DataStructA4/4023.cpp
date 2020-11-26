//基于双向链表的双向冒泡排序法

#include<iostream>

using namespace std;

typedef int DataType;
struct LNode
{
    DataType data;
    LNode *next;
    LNode *prior;
};

void createLNode(LNode *&l, int n)
{
    l = new LNode;
    LNode *p = l;
    LNode *d = l;
    DataType t;
    for(int i = 0; i < n; i++)
    {
        cin>>t;
        p->next = new LNode;
        p = p->next;
        p->prior = d;
        d = d->next;
        p->data = t;
        p->next = NULL;
    }
    l->prior = p;
    p->next = l;
}

void sort_double_buble(LNode *l, int n)
{
    LNode *h = l->next;
    LNode *t = l->prior;
    for(int i = 0; i < n; i++)
    {
        h = l->next;
        t = l->prior;
        if(i % 2 == 1)
        {
            while (h->next != l)
            {
                if(h->data > h->next->data)
                {
                    int temp = h->data;
                    h->data = h->next->data;
                    h->next->data = temp;
                }
                h = h->next;
            }
        }
        else
        {
            while (t->prior != l)
            {
                if(t->data < t->prior->data)
                {
                    int temp = t->data;
                    t->data = t->prior->data;
                    t->prior->data = temp;
                }
                t = t->prior;
            }
        }
        
    }
}

void printList(LNode *l)
{
    LNode *p = l->next;
    while (p->next != l)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<p->data<<endl;
    
}

int main()
{
    int n;
    while (cin>>n && n != 0)
    {
        LNode *l;
        createLNode(l, n);
        sort_double_buble(l, n);
        printList(l);
    }
    system("pause");
    return 0;
}