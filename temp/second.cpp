#include<iostream>

using namespace std;

typedef int DataType;
struct LNode
{
    DataType data;
    LNode *next;
};

void creatList(LNode *&l, int len)
{
    l = new LNode;
    LNode *p = l;
    for(int i = 0; i < len; i++)
    {
        DataType temp;
        p->next = new LNode;
        p = p->next;
        cin>>temp;
        p->data = temp;
        p->next = NULL;
    }
}

void SortInsert(LNode *l, LNode *newNode)
{
    LNode *p = l;
    l = l->next;
    while (l)
    {
        if(l->data >= newNode->data)
        {
            newNode->next = l;
            p->next = newNode;
            break;
        }
        l = l->next;
        p = p->next;
    }
}

void print(LNode *l)
{
    l = l->next;
    while (l->next)
    {
        cout<<l->data<<" ";
        l = l->next;
    }
    cout<<l->data<<endl;
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
        creatList(l, len);
        LNode *newNode = new LNode;
        cout<<"please input:";
        cin>>newNode->data;
        SortInsert(l, newNode);
        print(l);
    }  
    return 0;
}