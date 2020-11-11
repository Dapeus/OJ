#include<iostream>

using namespace std;

int main()
{
    string s;
    while (cin>>s)
    {
        int a[36] = { 0 };
        for(int i = 0; i < s.length(); i++)
        {
            if(s == "0")
            {
                return 0;
            }
            if('0' <= s[i] && s[i] <= '9')
            {
                int index = int(s[i] - '0');
                a[index]++;
            }
            else if('A' <= s[i] && s[i] <= 'Z')
            {
                int index = int(s[i] - 'A' + 10);
                a[index]++;
            }
        }
        for(int i = 0; i < 36; i++)
        {
            if(a[i] != 0)
            {
                if(0 <= i && i <= 9)
                {
                    cout<<i<<':'<<a[i]<<endl;
                }
                else
                {
                    cout<<char(i+55)<<':'<<a[i]<<endl;
                }
            }
        }
    }
    
}