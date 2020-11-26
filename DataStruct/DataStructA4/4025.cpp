//数组的正负排序

#include<iostream>

using namespace std;

void sort(int a[], int n)
{
    for(int i = 0, j = n; i < j; i++, j--)
    {
        if(a[i] > 0)
        {
            if(a[j] < 0)
            {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
            else
            {
                i--;
            }
        }      
    }
}

int main()
{
    int n;
    while(cin>>n && n != 0)
    {
        int a[100] = { 0 };
        for(int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        sort(a, n);
        for (int i = 0; i < n -1; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<a[n-1]<<endl;
    }
    system("pause");
    return 0;
}