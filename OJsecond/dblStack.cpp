#include<iostream>

using namespace std;

typedef int SElemType;
typedef struct
{
    int top[2], bot[2]; //栈顶和栈底指针
    SElemType *V;   //栈数组
    int m;  //栈最大可容纳元素个数

}DblStack;

void initDblStack(DblStack &dbls, int m)
{
    dbls.V = new SElemType[m];
    dbls.top[0] = dbls.bot[0] = 0;
    dbls.top[1] = dbls.bot[1] = m-1;
}

void dblsPush(DblStack &dbls, int x, int i)
{
    if(i == 0)
    {
        dbls.V[dbls.top[0]++] = x;
    }
    else
    {
        dbls.V[dbls.top[1]--] = x;
    }
}

int dblsPop(DblStack &dbls, int i)
{
    if(i == 0)
    {
        return dbls.V[--dbls.top[0]];
    }
    else
    {
        return dbls.V[++dbls.top[1]];
    }
}

int isEmpty(DblStack &dbls, int i)
{
    if(i == 0)
    {
        if(dbls.top[0] == dbls.bot[0])
        {
            return 0;   //代表为空
        }
        else
        {
            return 1;   //代表不空
        }
    }
    else
    {
        if(dbls.top[1] == dbls.bot[1])
        {
            return 0;   //代表为空
        }
        else
        {
            return 1;   //代表不空
        }
    }
}

int isFull(DblStack &dbls, int i)
{
    cout<<dbls.top[0]<<" "<<dbls.top[1]<<endl;
    if(dbls.top[0] - 1 == dbls.top[1])
    {
        return 1;   //栈满
    }
    else
    {
        return 0;   //栈不满
    }
}

int main()
{
    DblStack dbls;

    int m;
    int e0,e1,d0,d1;
    int num1[1000] = { 0 };
    int num2[1000] = { 0 };
    while(cin>>m)
    {   
        if(m == 0)
            return 0;
        initDblStack(dbls, m);
        cin>>e0>>e1>>d0>>d1;
        for(int i = 0; i < e0; i++)
        {
            cin>>num1[i];
            dblsPush(dbls, num1[i], 0);
        }

        for(int i = 0; i < e1; i++)
        {
            cin>>num2[i];
            dblsPush(dbls, num2[i], 1);
        }
        

        cout<<isFull(dbls, e0+e1-1)<<endl;
        for(int i = 0; i < d0; i++)
        {
            num1[i] = dblsPop(dbls, 0);
            cout<<num1[i]<<" ";
        }
        cout<<isEmpty(dbls, 0)<<endl;
        

        for(int i = 0; i < d1; i++)
        {
            num2[i] = dblsPop(dbls, 1);
            cout<<num2[i]<<" ";
        }
        cout<<isEmpty(dbls, 1)<<endl;

    }
    system("pause");

    return 0;
}