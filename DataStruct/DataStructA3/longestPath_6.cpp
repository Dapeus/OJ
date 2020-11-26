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

void longestTree(BiTNode *T, string path, string &record, int n, int &max)
{
    if(T == NULL)
    {
        return;
    }
    else
    {
        path.push_back(T->data);
        if(n >= max)
        {
            max = n+1;
            record = path;
        }
        longestTree(T->lchild, path, record, n+1, max);
        longestTree(T->rchild, path, record, n+1, max);
        
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
        string record = "";
        int n = 0, max = 0;
        longestTree(T, path, record, n, max);
        cout<<max<<endl;
        cout<<record<<endl;

    }
    return 0;
}