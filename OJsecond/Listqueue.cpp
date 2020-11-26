#include<iostream>

using namespace std;

typedef int DataType;
typedef struct LNode
{
    DataType data;
    LNode* next;
};

LNode* creatList(LNode *&l, int m)
{
    l = new LNode;
    l->data = -1;
    LNode *h = l;
    //int inp;

    for(int i = 0; i < m; i++)
    {
        //cin>>inp;
        l->next = new LNode;
        l= l->next;
        //l->data = inp;
        l->next = NULL;
    }
    l->next = h->next;
    return l,h;
}

void inList(LNode *&l, int m)
{
    LNode *p = l;
    int inp;
    p = p->next;
    for(int i = 0; i < m; i++)
    {   
        cin>>inp;
        p->data = inp;
        p = p->next;
    }
}

void popList(LNode *&l, int n, LNode *&h, int m)
{
    LNode *p = l;
    //p = p->next;
    //cout<<endl;
    if(m == 0)
        return;
    for(int i = 0; i < n; i++)
    {
        cout<<p->next->data<<" ";
        //free(p->next);
        if(p->next == p->next->next)
        {
            //cout<<p->next->data<<" "<<"cao";
            p->next = NULL;
            return;
        }
        p->next = p->next->next;
    }
    //cout<<endl;
    h->next = l->next;
}

int isEmpty(LNode *&l,LNode *h)
{
    if(l->next == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    LNode *l,*h;
    int m,n;
    while(cin>>m>>n)
    {
        if(m == 0 && n == 0)
            return 0;
        l,h = creatList(l, m);
        
        inList(l, m);
        popList(l, n, h, m);
        cout<<isEmpty(l,h)<<endl;       
    }

    return 0;
}