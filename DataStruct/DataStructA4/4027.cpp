//计数排序

#include<iostream>

using namespace std;

void count_Sort(int num[], int n)
{
    int x[1000] = { 0 };
    int cnt[1000] = { 0 };
    for(int i = 0; i < n; i++)
    {
        int j;
        for(j = 0; j < n; j++)
        {
            if(num[j] < num[i] && i != j)
            {
                cnt[i]++;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        x[cnt[i]] = num[i];
    }
    for(int i = 0; i < n-1; i++)
        cout<<x[i]<<" ";
    cout<<x[n-1]<<endl;
}

int main()
{   
    int n;
    while (cin>>n && n != 0)
    {
        int num[1000] = { 0 };
        for (int i = 0; i < n; i++)
            cin>>num[i];
        count_Sort(num, n);
    }   
    system("pause");
    return 0;
}