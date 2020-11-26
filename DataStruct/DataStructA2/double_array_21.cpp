#include<iostream>
#define M 1000
#define N 1000
using namespace std;

int main()
{
    int num[M] = { 0 };
    int m,n;
    while(cin>>m>>n)
    {
        if(m == 0 && n == 0)
        {
            return 0;
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin>>num[i*n+j];
            }
        }
        int jud = 0;
        // for(int i = 0; i < m*n; i++)
        // {
        //     cout<<num[i]<<endl;
        // }

        for(int i = 0; i < m*n; i++)
        {
            for(int j = i + 1; j < m*n; j++)
            {
                //cout<<num[i]<<" "<<num[j]<<endl;
                if(num[i] == num[j])
                {
                    jud = 1;
                    cout<<"YES"<<endl;
                    break;
                }
            }
            if(jud == 1)
            {
                break;
            }
            
        }
        if(jud == 0)
        {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}