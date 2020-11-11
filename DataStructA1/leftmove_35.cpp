#include<iostream>
#define M 1000

using namespace std;

void move(int num[], int len, int left)
{
    while(left--)
    {
        int temp = num[0];
        for(int i = 0; i < len - 1; i++)
        {
            num[i] = num[i+1];
        }
        num[len-1] = temp;
    }
}

int main()
{
    int len;
    while (cin>>len)
    {

        if(len == 0)
        {
            return 0;
        }
        int num[M];
        for(int i = 0; i < len; i++)
        {
            cin>>num[i];
        }
        int left;
        cin>>left;

        move(num, len, left);
        for (int i = 0; i < len; i++)
        {
            if(i == len-1)
            {
                cout<<num[i]<<endl;
            }
            else
            {
                cout<<num[i]<<" ";
            }
        }
    }
    return 0;
}