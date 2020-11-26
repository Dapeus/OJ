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

void printTreeD(BiTNode *T)
{
    if(T == NULL)
    {
        return;
    }
    else
    {
        cout<<T->data;
        printTreeD(T->lchild);
        printTreeD(T->rchild);
    }
}

void printTreeL(BiTNode *T)
{
    if(T == NULL)
    {
        return;
    }
    else
    {
        printTreeL(T->lchild);
        cout<<T->data;
        printTreeL(T->rchild);
    }
}

void printTreeR(BiTNode *T)
{
    if(T == NULL)
    {
        return;
    }
    else
    {
        printTreeR(T->lchild);
        printTreeR(T->rchild);
        cout<<T->data;
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
        printTreeD(T);
        cout<<endl;
        printTreeL(T);
        cout<<endl;
        printTreeR(T);
        cout<<endl;
    }
    return 0;
}