#include<iostream>
#include<iomanip>

using namespace std;

typedef char DataType;
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
        p->next = new LNode;
        p = p->next;
        p->next = NULL;
    }
}

void reverse(LNode *l, string s, int &i)
{
    if(l->next == NULL)
    {
        l->data = s[i++];
        return;
    }
    else
    {
        reverse(l->next, s, i);
        l->data = s[i++];
    }
}

void print(LNode *l)
{
    while (l)
    {
        if(l->next == NULL)
        {
            cout<<l->data<<endl;
        }
        else
        {
            cout<<l->data;
        }
        l = l->next;
    }
}

int main()
{   
    string len;
    while (cin>>len)
    {
        if(len == "0")
        {
            return 0;
        }
        LNode *l;
        creatList(l, len.length());
        int i = 0;
        reverse(l->next, len, i);
        print(l->next);
    }
    
    return 0;
}