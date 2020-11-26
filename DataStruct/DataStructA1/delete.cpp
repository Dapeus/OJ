#include<iostream>

using namespace std;

struct LNode
{
    int data;
    LNode *next;
};

void creatList(LNode*& l, LNode*& h, int len)
{
    l = new LNode;
    h = l;
    int inp;
    for(int i = 0; i < len; i++)
    {
        cin>>inp;
        LNode *t = new LNode;
        l->next = t;
        l = l->next;
        l->data = inp;
        l->next = NULL;
    }
}

void print(LNode *&h)
{
    LNode *p = h->next;
    while (p)
    {
        if(p->next == NULL)
        {
            cout<<p->data<<endl;
        }
        else
        {
            cout<<p->data<<" ";
        }
        p = p->next;
    }
}

void delete_my(LNode *h, int min, int max)
{
    LNode *p = h->next, *t = h;
    while (p)
    {
        if(p->data >= min && p->data <= max)
        {
            t->next = p->next;
            p = t->next;
        }
        else
        {
            p = p->next;
            t = t->next;
        }
    }
}

int main()
{
    LNode *l,*h;
    int len;
    while(cin>>len)
    {
        if(len == 0)
        {
            break;
        }
        
        creatList(l, h, len);
        //print(h);
        int min,max;
        cin>>min>>max;
        delete_my(h, min, max);
        print(h);
    }

    return 0;
}