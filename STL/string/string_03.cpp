#include<iostream>
#include<string>

using namespace std;

//string字符串拼接

void test01()
{
    //1
    string str1 = "i ";
    str1 += "love play games";
    cout<<str1<<endl;
    //2
    str1 += ';';
    cout<<str1<<endl;
    //3
    string str2 = " ,like lol";
    str1 += str2;
    cout<<str1<<endl;
    //4 
    string str3 = "i";
    str3.append(" love ");
    cout<<str3<<endl;
    //5 把前n个拼接到str3里
    str3.append("game abcde", 4);
    cout<<str3<<endl;
    //6
    str3.append(str2);
    cout<<str3<<endl;
    //7
    str3.append(str2, 0, 4);
    cout<<str3<<endl;
}

int main()
{
    test01();

    system("pause");

    return 0;
}