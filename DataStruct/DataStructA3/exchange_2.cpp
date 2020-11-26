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

void exchangeTree(BiTNode *T)
{
    if(T == NULL)
    {
        return;
    }
    else
    {
        if(T->lchild != NULL && T->rchild != NULL)
        {
            BiTNode *temp;
            temp = T->lchild;
            T->lchild = T->rchild;
            T->rchild = temp;
        }
        exchangeTree(T->lchild);
        exchangeTree(T->rchild);
    }
    
}

void printTree(BiTNode *T)
{
    if(T == NULL)
    {
        return;
    }
    else
    {
        cout<<T->data;
        printTree(T->lchild);
        printTree(T->rchild);
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
        exchangeTree(T);
        printTree(T);
        cout<<endl;
    }
    return 0;
}