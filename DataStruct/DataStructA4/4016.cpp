//二叉排序树的判定

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
    DataType t;
    cin>>t;
    if(t == '#')
    {
        T = NULL;
    }
    else
    {
        T = new BiTNode;
        T->data = t;
        T->lchild = NULL;
        T->rchild = NULL;
        createTree(T->lchild);
        createTree(T->rchild);
    }
}

void judge(BiTNode *T, int &jud)
{
    if(T->lchild != NULL)
    {
        if(T->lchild->data >= T->data)
        {
            jud = 1;
        }
        else
        {
            judge(T->lchild, jud);
        }
        
    }
    if(T->rchild != NULL)
    {
        if(T->rchild->data <= T->data)
        {
            jud = 1;
        }
        else
        {
            judge(T->rchild, jud);
        }
    }
}

int main()
{
    while (1)
    {
        BiTNode *T;
        createTree(T);
        if(T == NULL)
        {
            break;
        }
        int jud = 0;
        judge(T, jud);
        if(jud == 1)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
        
    }
    
    system("pause");
    return 0;
}