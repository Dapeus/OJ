#include<iostream>
#include<iomanip>

using namespace std;

typedef double DataType;
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
        DataType t;
        p->next = new LNode;
        p = p->next;
        cin>>t;
        p->data = t;
        p->next = NULL;
    }
}

double getAver(LNode *l, int len)
{
    if(l->next == NULL)
    {
        return l->data;
    }
    else
    {
        return (l->data + (getAver(l->next, len-1)*(len-1)))/len;
    }
}

int main()
{   
    int len;
    while (cin>>len)
    {
        if(len == 0)
        {
            return 0;
        }
        LNode *l;
        creatList(l, len);
        cout<<fixed<<setprecision(2)<<getAver(l->next, len)<<endl;
    }
    
    return 0;
}