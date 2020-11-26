#include<bits/stdc++.h>

using namespace std;

typedef int Datatype;
struct LNode
{
    Datatype data;
    LNode *next;
};

void creatList(LNode *&l)
{
    l = new LNode;
    LNode * p = l;
    int inp;
    while(1)
    {
        cin>>inp;
        if(inp == 0)
        {
            break;
        }
        else
        {
            p->next = new LNode;
            p = p->next;
            p->data = inp;
            p->next = NULL;
        }
    }
}

int getlen(LNode *l)
{
    int cnt = 0;
    while(l)
    {
        l = l->next;
        cnt++;
    }
    return cnt;
}

void print(LNode *l)
{
    while(l)
    {
        cout<<l->data<<endl;
        l = l->next;
    }
}

void odd(LNode *&l, int len) // 原版
{
    LNode *p = l, *p1 = l->next, *h = l->next;
    p = p->next;
    int cnt = 0;
    for(int i = -1; i < len - 1; i++)
    {
        if(p == NULL)
        {
            break;
        }
        if(i % 2 == 1)
        {
            LNode *temp = p1->next; 
            for(int j = 0; j < cnt; j++)
            {
                temp = temp->next;
            }
            cnt++;
            temp->next = p->next;
            p->next = p1->next;
            p1->next = p;
            p1 = p;
            for(int j = 0; j < cnt + 1; j++)
            {
                p = p->next;
            }
        }
        else
        {
            p = p->next;
        }
    }
    while(h)
    {
        if(h->next == NULL)
        {
            cout<<h->data<<endl;
        }
        else
        {
            cout<<h->data<<" ";
        }
        h = h->next;
    }
}

void division(LNode *&l, int len) // 简易版
{
    LNode *h = l, *odd = l->next, *even = l->next->next, *e = l->next->next;
    while(odd->next && even->next)
    {
        odd->next = even->next;
        even->next = odd->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = e;
}

void print_my(LNode *l)
{
    while(l->next)
    {
        cout<<l->data<<" ";
        l = l->next;
    }
    cout<<l->data<<endl;
}

int main()
{
    LNode *l;
    creatList(l);
    int len = getlen(l->next);
    //odd(l, len);
    division(l, len);
    print_my(l->next);
    system("pause");
    return 0;
}