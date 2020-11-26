#include<iostream>
#include<string>

using namespace std;

//string 子串

void test01()
{
    string str = "abcdef";

    string subStr = str.substr(1,3); //第一个参数是位置，第二个参数是截取几个

    cout<<"subStr:"<<subStr<<endl;
}

//实用操作
void test02()
{
    string email = "hello@sina.com";

    //从邮件信息中 获取用户名信息
    int pos = email.find('@'); //pos = 5
    string name = email.substr(0, pos);
    cout<<"name:"<<name<<endl;
}

int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}