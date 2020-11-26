//二叉排序树的限定条件下的数据输出

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

void search(BSTNode *T, int goal, int n[], int &cnt)
{
    if(T == NULL)
    {
        return;
    }
    // if(T->lchild == NULL && T->rchild == NULL)
    // {
    //     return;
    // }
    if(goal == T->data)
    {
        n[cnt] = T->data;
        cnt++;
        search(T->rchild, goal, n, cnt);
    }
    else if(goal > T->data)
    {
        search(T->rchild, goal, n, cnt);
    }
    else
    {
        n[cnt] = T->data;
        cnt++;
        search(T->lchild, goal, n, cnt);
    }
    
}

void sort(int num[], int cnt)
{
    for(int i = 0; i < cnt-1; i++)
    {
        for(int j = 0; j < cnt-1; j++)
        {
            if(num[j] > num[j+1])
            {
                int temp = num[j+1];
                num[j+1] = num[j];
                num[j] = temp;
            }
        }
    }
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
        int cnt = 0;
        cin>>goal;
        int n[M] = { 0 };
        search(T, goal, n, cnt);
        sort(n, cnt);
        for(int i = 0; i < cnt-1; i++)
        {
            cout<<n[i]<<" ";
        }
        cout<<n[cnt-1]<<endl;
    }
    
    system("pause");

    return 0;
}