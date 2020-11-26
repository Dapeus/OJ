#include<iostream>
#include<iomanip>

using namespace std;

typedef struct LNode
{
    float data;
    LNode* next;
};
float sum = 0;
LNode* creatLNode(LNode *&l, int m)
{
    l = new LNode;
    int inp;
    LNode *p = l;
    l->next = new LNode;
    l->data = -1;
    for(int i = 0; i < m; i++)
    {
        cin>>inp;
        l->next = new LNode;
        l = l->next;
        l->data = inp;
        l->next = NULL;
    }
    return p;
}

float aver(LNode *& l)
{


    if(l->next == NULL)
    {
        return l->data;
    }
    else
    {
        float temp = aver(l->next) + l->data;
        //cout<<"temp:"<<temp<<endl;;
        return temp;
    }
}



int main()
{
    float m;
    LNode *l,*h;
    while(cin>>m)
    {
        if(m == 0)
            return 0;
        sum = 0;
        l = creatLNode(l, m);
        h = l;
        // while (l)
        // {
        //     cout<<l->data<<" ";
        //     l = l->next;
        // }
        //cout<<setiosflags(ios::fixed)<<setprecision(2);
        cout<<setiosflags(ios::fixed)<<setprecision(2)<<aver(l->next)/m<<endl;
    }

    return 0;
}