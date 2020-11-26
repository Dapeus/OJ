#include<iostream>
#include<string>

using namespace std;

//string 字符存取

void test01()
{
    string str = "hello";

    cout<<"str:"<<str<<endl;
    //通过[]访问
    for(int i = 0; i < str.length(); i++)
    {
        cout<<str[i];
    }
    cout<<endl;
    //通过at访问
    for(int i = 0; i < str.length(); i++)
    {
        cout<<str.at(i);
    }
    cout<<endl;

    //修改单个字符
    str[0] = 'x';
    cout<<str<<endl;

    str.at(1) = 'x';
    cout<<str<<endl;
}

int main()
{
    test01();
    
    system("pause");
    return 0;
}