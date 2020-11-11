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

void highTree(BiTNode *T, int &max, int n)
{
    if(T == NULL)
    {
        return;
    }
    else
    {
        if(n >= max)
            max = n+1;
        highTree(T->lchild, max, n+1);
        highTree(T->rchild, max, n+1);
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
        int max = 0,n = 0;
        highTree(T, max, n);
        cout<<max<<endl;
    }
    return 0;
}