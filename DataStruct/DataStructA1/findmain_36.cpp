#include<iostream>
#define M 1000

using namespace std;

void findmain(int num[], int len)
{
    int cnt[M] = { 0 };
    int jud = 0;
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < len; j++)
        {
            if(num[i] == num[j])
            {
                cnt[i]++;
            }
        }
        if(cnt[i] > len/2)
        {
            cout<<num[i]<<endl;
            jud = 1;
            break;
        }
    }
    if(jud == 0)
    {
        cout<<-1<<endl;
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
        findmain(num, len);        
    }
    return 0;
}