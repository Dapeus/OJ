#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//vector容器存放自定义数据类型
class Person
{
public:
    Person(string name, int age): m_name(name), m_age(age)
    {}
    ~Person();

    string m_name;
    int m_age;
};

Person::~Person()
{

}

void myprint(Person p)
{
    cout<<p.m_name<<" "<<p.m_age<<endl;
}

void test01()
{
    vector<Person> v;
    Person p1("aa",10);
    Person p2("bb",20);
    Person p3("cc",30);
    Person p4("dd",40);
    Person p5("ee",50);

    //向容器中存放数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    for_each(v.begin(), v.end(), myprint);

    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout<<"last_name:"<<it->m_name<<" age:"<<it->m_age<<endl;
    }
}

void myprint_sec(Person *p)
{
    cout<<p->m_name<<" "<<p->m_age<<endl;
}
//存放自定义数据类型的指针
void test02()
{
    vector<Person*> v;
    Person p1("aa",10);
    Person p2("bb",20);
    Person p3("cc",30);
    Person p4("dd",40);
    Person p5("ee",50);

    //向容器中存放数据
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    for_each(v.begin(), v.end(), myprint_sec);

    for(vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout<<"last_name:"<<(*it)->m_name<<" age:"<<(*it)->m_age<<endl;
    }
}

int main()
{
    test02();
    
    system("pause");

    return 0;
}