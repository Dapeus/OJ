#include<iostream>

using namespace std;

void insert_sort(int a[], int n)
{

}

int main()
{
    int a[100] = { 0 };
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    insert_sort(a, n);

    system("pause");
    return 0;
}