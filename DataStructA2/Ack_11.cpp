#include <iostream>
using namespace std;
 
int Ack(int m,int n)
{   
    int akm[m+1][100];
    for(int i = 0; i < 100; i++)
    {
        akm[0][i] = i + 1;
    }
        
    for(int i = 1; i <= m; i++)
    {
        akm[i][0]=akm[i-1][1];
        for(int j = 1; j < 100; j++)
        {
            akm[i][j]=akm[i-1][akm[i][j-1]];
        }
            
    }
    return (akm[m][n]);
}
 
int main()
{
    int m,n;
    while (cin>>m>>n)
    {
        if(m == 0 && n == 0)
        {
            return 0;
        }
        cout<<Ack(m,n)<<endl;
    }
    return 0;
}