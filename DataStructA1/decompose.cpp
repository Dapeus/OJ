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

void decompose(LNode *&h, int len)
{   
    LNode *p = h->next, *p1 = h;
    int cnt = 0;
    for(int j = 0; j < len; j++)
    {
        p = h->next;
        p1 = h;
        for(int i = 0; i < len; i++, p = p->next, p1 = p1->next)
        {
            if(p->data < 0 && cnt > 0 && p1->data > 0)
            {
                int temp = p->data;
                p->data = p1->data;
                p1->data = temp;
            }
            cnt++;
        }
    }
    p = h->next;
    for(int i = 0; i < len; i++)
    {
        if(p->data < 0)
        {
            if(p->next->data > 0)
            {
                cout<<p->data<<endl;
                break;
            }
            else
            {
                cout<<p->data<<" ";            
            }
        }
        p = p->next;
    }
    p = p->next;
    while(p)
    {
        if(p->data > 0)
        {
            if(p->next == NULL)
            {
                cout<<p->data<<endl;
            }
            else
            {
                cout<<p->data<<" ";            
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
        decompose(h, len);
        //print(h);
    }

    return 0;
}