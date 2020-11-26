#include<iostream>

using namespace std;

struct LNode
{
    int data;
    LNode *next;
};

LNode* creatList(LNode *l, int len)
{
    l = new LNode;
    LNode *p = l;
    int inp;
    for(int i = 0; i < len; i++)
    {
        cin>>inp;
        l->next = new LNode;
        l = l->next;
        l->data = inp;
        l->next = NULL;
    }
    return p;
}

void input(LNode *h, int len)
{
    LNode *p = h->next;
    int t;
    for(int i = 0; i < len; i++)
    {
        cin>>t;
        p->data = t;
        p = p->next;
    }
}

void print(LNode *l, int len)
{
    LNode *p = l->next;
    // for(int i = 0; i < len; i++)
    // {
    //     cout<<p->data<<" ";
    //     p = p->next;
    // }
    while(p)
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

void intersection(LNode *h1, LNode *h2, int len1, int len2)
{
    LNode *p1 = h1->next,*p2 = h2->next;
    LNode *p11 = h1;

    for(int i = 0; i < len1; i++, p1 = p1->next)
    {
        int jud = 0;
        p2 = h2->next;
        for(int j = 0; p1 != NULL && p2 != NULL; j++,p2 = p2->next)
        {
            if(p1->data == p2->data)
            {   
                jud = 1;
                break;
            }
        }
        if(jud == 0)
        {
            p11->next = p1->next;
        }
        else
        {
            p11 = p11->next;
        }
    }
}

void differentSet(LNode *h1, LNode *h2, int len1, int len2)
{
    LNode *p1 = h1->next,*p2 = h2->next;
    LNode *p11 = h1;
    int cnt = 0;
    for(int i = 0; i < len1; i++, p1 = p1->next)
    {
        int jud = 0;
        p2 = h2->next;
        for(int j = 0; p1 != NULL && p2 != NULL; j++,p2 = p2->next)
        {
            if(p1->data == p2->data)
            {   
                jud = 1;
                cnt++;
                break;
            }
        }
        if(jud == 1)
        {
            p11->next = p1->next;
        }
        else
        {
            p11 = p11->next;
        }
    }
    print(h1, len1);
    cout<<len1-cnt<<endl;
}

int main()
{
    LNode *l1,*l2,*h1,*h2;
    int len1,len2;
    while (cin>>len1>>len2)
    {
        if(len1 == 0 && len2 == 0)
        {
            break;
        }
        l1 = creatList(l1, len1);
        l2 = creatList(l2, len2);
        h1 = l1; h2 = l2;
        //print(h1, len1);
        

        differentSet(h1, h2, len1, len2);
        
    }
    return 0;
}