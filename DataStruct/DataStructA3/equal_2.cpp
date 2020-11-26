#include<iostream>

using namespace std;

typedef char DataType;
struct BiTNode
{
    DataType data;
    BiTNode *lchild;
    BiTNode *rchild;
};

void createTree(BiTNode *&T, string s, int &a)
{
    if(s[a] == '0')
    {
        T = NULL;
        a++;
    }
    else
    {
        T = new BiTNode;
        T->data = s[a++];
        T->lchild = NULL;
        T->rchild = NULL;
        createTree(T->lchild, s, a);
        createTree(T->rchild, s, a);
    }
}

void equalTree(BiTNode *T1, BiTNode *T2, int &jud)
{
    if(T1 == NULL || T2 == NULL)
    {
        return;
    }
    else
    {
        if(T1->data != T2->data)
        {
            jud = 0;
        }
        equalTree(T1->lchild, T2->lchild, jud);
        equalTree(T1->rchild, T2->rchild, jud);
    }
}

int main()
{
    string s1,s2;
    while(cin>>s1 && s1 != "0" && cin>>s2)
    {

        int jud = 1, a = 0;
        BiTNode *T1,*T2;
        createTree(T1, s1, a);
        a = 0;
        createTree(T2, s2, a);
        equalTree(T1, T2, jud);
        if(jud == 1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        
    }
    return 0;
}