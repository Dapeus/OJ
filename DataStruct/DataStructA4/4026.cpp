//基于快排思想的查找

#include<iostream>
#define M 1000
using namespace std;

int quickSort(int r[], int low, int high, int goal)
{
    while(low < high)
    {
        if(r[low] > goal && r[high] < goal)
        {
            high--;
            low++;
        }
        while(low <= high &&r[high] > goal)
        {
            high--;
        }
        if(r[high] == goal)
            return high;
        while(low <= high && r[low] < goal)
        {
            low++;
        }
        if(r[low] == goal)
            return low;
    }
    cout<<"not find"<<endl;
    return 0;
}

int main()
{
    int n;
    while(cin>>n && n != 0)
    {
        int a[M] = { 0 };
        for(int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        int goal;
        cin>>goal;
        int x = quickSort(a, 0, n, goal);
        if(x)
        {
            cout<<x+1<<" "<<goal<<endl;
        }
    }
    system("pause");
    return 0;
}