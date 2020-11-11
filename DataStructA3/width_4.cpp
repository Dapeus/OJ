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

void widthTree(BiTNode *T, int a[], int n)
{
    if(T == NULL)
    {
        return;
    }
    else
    {
        a[n]++;
        widthTree(T->lchild, a, n+1);
        widthTree(T->rchild, a, n+1);
    }
}

int maxA(int a[])
{
    int i = 0;
    int max = 0;
    while (a[i] != 0)
    {
        if(a[i] > max)
        {
            max = a[i];
        }
        i++;
    }
    return max;
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
        int a[1000] = { 0 };
        int n = 0;
        widthTree(T, a, n);
        cout<<maxA(a)<<endl;
    }
    return 0;
}