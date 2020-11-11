#include<iostream>

using namespace std;

typedef char DataType;
struct BiTNode
{
    DataType data;
    BiTNode *lchild;
    BiTNode *rchild;
};

void createTree(BiTNode *&T)
{
    DataType ch;
    cin>>ch;
    if(ch == '0')
    {
        T = NULL;
    }
    else
    {
        T = new BiTNode;
        T->data = ch;
        T->lchild = NULL;
        T->rchild = NULL;
        createTree(T->lchild);
        createTree(T->rchild);
    }
}

void countTree(BiTNode *T, int &n0, int &n1, int &n2)
{
    if(T == NULL)
    {
        return;
    }
    else
    {
        if(T->lchild == NULL && T->rchild == NULL)
            n0++;
        else if(T->lchild == NULL || T->rchild == NULL)
            n1++;
        else
            n2++;
        countTree(T->lchild, n0, n1, n2);
        countTree(T->rchild, n0, n1, n2);
    }
}

int main()
{
    while(1)
    {
        BiTNode *T;
        createTree(T);
        if(T == NULL)
        {
            return 0;
        }
        int n0 = 0, n1 = 0, n2 = 0;
        countTree(T, n0, n1, n2);
        cout<<n0<<' '<<n1<<' '<<n2<<endl;
    }
    return 0;
}