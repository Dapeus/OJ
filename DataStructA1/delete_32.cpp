#include<iostream>
#include<math.h>

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

void delete_my(LNode *h)
{
    LNode *p = h->next, *t = h, *p1 = h->next;
    while (p)
    {
        p1 = h->next;
        t = h;
        while(p1)
        {
            if(abs(p->data) == abs(p1->data) && p1 != p)
            {
                t->next = p1->next;
                p1 = t->next;
            }
            else
            {
                p1 = p1->next;
                t = t->next;
            }
        }
        p = p->next;
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

        delete_my(h);
        print(h);
    }

    return 0;
}