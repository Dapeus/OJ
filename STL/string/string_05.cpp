#include<iostream>
#include<string>

using namespace std;

//字符串的比较

void test01()
{
    string str1 = "aello";
    string str2 = "hello";

    if(str1.compare(str2) == 0)
    {
        cout<<"equal"<<endl;
    }
    else if(str1.compare(str2) == 1)
    {
        cout<<"str1>str2"<<endl;
    }
    else
    {
        cout<<"str1<str2"<<endl;
    }
    
    
}

int main()
{
    test01();
    
    system("pause");
    return 0;
}