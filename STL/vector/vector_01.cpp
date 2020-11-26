#include<iostream>
#include<vector>
#include<algorithm> //标准算法头文件

using namespace std;

void myPrint(int val)
{
    cout<<val<<endl;
}

void test01()
{
    vector<int> v; //创建了一个vector容器
    
    //向容器中插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    //通过迭代器来访问容器中的数据
    vector<int>::iterator itBegin = v.begin(); //v.begin()起始迭代器 指向容器中第一个元素
    vector<int>::iterator itEnd = v.end(); //v.end()结束迭代器 指向容器最后一个元素的下一个位置

    //第一种遍历方式
    while (itBegin != itEnd)
    {
        cout<<*itBegin<<endl;
        itBegin++;
    }
    //第二种遍历方式
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout<<*it<<endl;
    }

    //第三种遍历方式 利用stl中提供的遍历算法
    for_each(v.begin(), v.end(), myPrint);
}

int main()
{
    test01();
    system("pause");

    return 0;
}