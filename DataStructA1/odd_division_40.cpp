#include<iostream>

using namespace std;

struct LNode
{
    int data;
    LNode *next;
};

LNode* createList(LNode *&l, int len)
{
    l = new LNode;
    LNode *h = l;
    int inp;
    for (int i = 0; i < len; i++)
    {
        cin>>inp;
        l->next = new LNode;
        l = l->next;
        l->data = inp;
        l->next = NULL;
    }
    //l->next = h->next;
    return h;
}

int isOdd(int x)
{
    if(x % 2 == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

void odd_division(LNode *&l, int len)
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
        if(isOdd(i))
        {
            LNode *temp = p1->next;
            // p1->next->next = p->next;
            
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
        l = createList(l, len);
        odd_division(l, len);
    }
    return 0;
}