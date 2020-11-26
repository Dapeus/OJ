//基于递归的折半查找
#include<iostream>
#define M 1000

using namespace std;

void search(int num[], int max, int mid, int min, int goal, int &jud)
{
    if(min > max)
    {
        return;
    }
    if(goal == num[mid])
    {
        jud = 1;
    }
    else if(goal < num[mid])
    {
        max =  mid-1;
        mid = (max+min)/2;
        search(num, max, mid, min, goal, jud);
    }
    else
    {
        min = mid+1;
        mid = (max+min)/2;
        search(num, max, mid, min, goal, jud);
    }
}

int main()
{
    int n;
    while(cin>>n && n != 0)
    {
        int num[M] = { 0 };
        int goal, i;
        for(i = 0; i < n; i++)
        {
            cin>>num[i];
        }
        cin>>goal;
        int max = i;
        int min = 0;
        int mid = (max + min) / 2;
        int jud = 0;
        search(num, max, mid, min, goal, jud);
        if(jud == 1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    system("pause");

    return 0;
}