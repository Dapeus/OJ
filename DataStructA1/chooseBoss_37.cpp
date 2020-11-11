#include<iostream>

using namespace std;

struct LNode
{
    int data;
    LNode *next;
};

void createList(LNode *&l, int m)
{
    l = new LNode;
    LNode *h = l;
    for (int i = 0; i < m; i++)
    {
        l->next = new LNode;
        l = l->next;
        l->data = i+1;
        l->next = NULL;
    }
    l->next = h->next;
}

void choose(LNode *l, int m, int n)
{
    LNode *h = l, *p = l;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            l = l->next;
            if(j == 0)
            {}
            else
            {
                p = p->next;
            }
        }
        if(i+1 == m)
        {
            cout<<l->data<<endl;
        }
        else
        {
            cout<<l->data<<" ";
        }
        p->next = l->next;

    }
}

int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        if(m == 0 && n == 0)
        {
            return 0;
        }
        LNode *l;
        createList(l, m);
        choose(l, m ,n);
    }
    return 0;
}