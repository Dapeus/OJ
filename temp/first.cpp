#include<iostream>
#define M 1000

using namespace std;

void split(int a[])
{
    for(int i = 0, j = 9; i < 5 && j > 4; i++,j--)
    {
        if(a[i] % 2 == 0)
        {
            i--;
            if(a[j] % 2 == 1)
            {
                i++;
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

void print(int a[])
{
    int i;
    for(i = 0; i < 9; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<a[i]<<endl;
}

int main()
{
    int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
    split(a);
    print(a);
    system("pause");
    return 0;
}