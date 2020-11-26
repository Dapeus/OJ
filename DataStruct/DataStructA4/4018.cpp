//基于非递归的二叉排序树的结点的查找和插入

#include<iostream>
#define M 100

using namespace std;

typedef int DataType;
struct BSTNode
{
    DataType data;
    BSTNode *lchild;
    BSTNode *rchild;
};

void createTree(BSTNode *&T)
{
    T = new BSTNode;
    T->lchild = NULL;
    T->rchild = NULL;
    DataType data;
    cin>>data;
    T->data = data;
}

void createBST(BSTNode *&T, int d)
{
    if(d < T->data)
    {
        if(T->lchild == NULL)
        {
            T->lchild = new BSTNode;
            T->lchild->data = d;
            T->lchild->lchild = NULL;
            T->lchild->rchild = NULL;
        }
        else
        {
            createBST(T->lchild, d);
        }
        
    }
    else
    {
        if(T->rchild == NULL)
        {
            T->rchild = new BSTNode;
            T->rchild->data = d;
            T->rchild->lchild = NULL;
            T->rchild->rchild = NULL;
        }
        else
        {
            createBST(T->rchild, d);
        }
    }
}

int search(BSTNode *T, int goal)
{
    BSTNode *p = T, *pb = T;
    while(p)
    {
        pb = p;
        if(goal < p->data)
        {
            p = p->lchild;
        }
        else if(goal > p->data)
        {
            p = p->rchild;
        }
        else
        {
            return 1;
        }   
    }
    if(goal > pb->data)
    {
        pb->rchild = new BSTNode;
        pb->rchild->data = goal;
        pb->rchild->lchild = NULL;
        pb->rchild->rchild = NULL;
    }
    else
    {
        pb->lchild = new BSTNode;
        pb->lchild->data = goal;
        pb->lchild->lchild = NULL;
        pb->lchild->rchild = NULL;
    }
    return 0;
}

void printTree(BSTNode *T, int num[], int &cnt)
{
    if(T == NULL)
    {
        return;
    }
    printTree(T->lchild, num, cnt);
    num[cnt++] = T->data;
    printTree(T->rchild, num, cnt);
}

int main()
{
    int num;
    while(cin>>num && num != 0)
    {
        BSTNode *T;
        createTree(T);
        int d;
        for(int i = 0; i < num-1; i++)
        {
            cin>>d;
            createBST(T, d);
        }
        int goal;
        cin>>goal;
        int jud = search(T, goal);
        if(jud == 1)
        {
            int cnt = 0;
            int num[M] = { 0 };
            printTree(T, num, cnt);
            for(int i = 0; i < cnt-1; i++)
                cout<<num[i]<<" ";
            cout<<num[cnt-1]<<endl;
            for(int i = 0; i < cnt-1; i++)
            {
                if(goal == num[i])
                    cout<<1<<" ";
                else
                    cout<<0<<" ";
            }
            if(goal == num[cnt-1])
                cout<<1<<endl;
            else
                cout<<0<<endl; 
        }
        else
        {
            int cnt = 0;
            int num[M] = { 0 };
            printTree(T, num, cnt);
            for(int i = 0; i < cnt-1; i++)
                cout<<num[i]<<" ";
            cout<<num[cnt-1]<<endl;
            for(int i = 0; i < cnt-1; i++)
                cout<<0<<" ";   
            cout<<0<<endl; 
        }
    }
    system("pause");
    return 0;
}