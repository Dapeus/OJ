//砾石的交换排序

#include<iostream>

using namespace std;

void sort_stone(char stone[], int n)
{
    int h = 0,t = n-1;
    for (int i = 0; i <= t; i++)
    {
        if(stone[i] == 'R')
        {
            stone[i] = stone[h];
            stone[h++] = 'R';
        }
        else if(stone[i] == 'W')
        {
            
        }
        else
        {
            stone[i] = stone[t];
            stone[t--] = 'B';
            i--;
        }
    }
}

int main()
{
    int n;
    while (cin>>n && n != 0)
    {
        char stone[1000] = { 0 };
        for(int i = 0; i < n; i++)
            cin>>stone[i];
        sort_stone(stone, n);
        for(int i = 0; i < n-1; i++)
        {
            cout<<stone[i]<<" ";
        }
        cout<<stone[n-1]<<endl;
    }
    
    system("pause");
    return 0;
}