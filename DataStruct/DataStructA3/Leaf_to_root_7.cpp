#include<iostream>
#include<bits/stdc++.h>

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

void countTree(BiTNode *T, string path)
{
    if(T == NULL)
    {
        return;
    }
    else
    {
        if(T->lchild == NULL && T->rchild == NULL)
        {
            path.push_back(T->data);
            reverse(path.begin(),path.end());
            cout<<path<<endl;
        }
        else
        {
            path.push_back(T->data);
            countTree(T->lchild, path);
            countTree(T->rchild, path);
        }      
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
        string path = "";
        countTree(T, path);

    }
    return 0;
}