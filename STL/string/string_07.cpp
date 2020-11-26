#include<iostream>
#include<string>

using namespace std;

//string 插入和删除

void test01()
{
    //插入
    string str = "hello";
    str.insert(1,"111");
    cout<<"str:"<<str<<endl;

    //删除
    str.erase(1,3); //第一个是位置，第二个是个数
    cout<<"str:"<<str<<endl;
}

int main()
{
    test01();
    
    system("pause");
    return 0;
}