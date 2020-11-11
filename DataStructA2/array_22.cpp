#include<iostream>
#define M 1000

using namespace std;

void splitSort(int num[], int len)
{
    int t1[M],t2[M];
    int c1 = 0, c2 = 0;
    for(int i = 0; i < len; i++)
    {
        if(num[i] < 0)
        {
            t2[c2++] = num[i];
        }
        else
        {
            t1[c1++] = num[i];
        }
    }
    for(int i = 0, j = 0; i < len; i++)
    {
        if(i < c1)
        {
            num[i] = t1[i];
        }
        else
        {
            num[i] = t2[j++];
        }
    }
}

void print(int num[], int len)
{
    int i;
    for(i = 0; i < len-1; i++)
    {
        cout<<num[i]<<" ";
    }
    cout<<num[i]<<endl;
}

int main()
{
    int len;
    while(cin>>len)
    {
        if(len == 0)
        {
            return 0;
        }
        int num[M] = { 0 };
        for(int i = 0; i < len; i++)
        {
            cin>>num[i];
        }
        splitSort(num, len);
        print(num, len);
    }
    return 0;
}