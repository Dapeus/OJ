#include<iostream>
#include<string>

using namespace std;

//字符串的查找和替换
//1.查找
void test01()
{
    string str1 = "abcdefgde";
    int pos = str1.find("de");
    if(pos == -1)
    {
        cout<<"no appear"<<endl;
    }
    else
    {
        cout<<"pos:"<<pos<<endl;
    }
    //rfind
    pos = str1.rfind("de");
    cout<<"pos:"<<pos<<endl;
    //rfind and find 的区别 rfind从右往左， find从左往右
}

void test02()
{
    string str1 = "abcdefg";

    str1.replace(1,3,"1111");

    cout<<str1<<endl;
}

int main()
{
    test01();
    test02();
    
    system("pause");
    return 0;
}