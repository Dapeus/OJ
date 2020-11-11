#include<iostream>
#include<iomanip>
#define M 1000

using namespace std;

typedef struct Book
{
    string num; //存储书籍编号
    string name; //存储书籍名字
    float price; //存储书籍价格
};

void print(Book book[],int i)
{
    for(int j = 0; j < i; j++)
    {
        cout<<book[j].num<<" "<<book[j].name<<" "<<setiosflags(ios::fixed)<<setprecision(2)<<book[j].price<<endl;
    }
}

void exchange(Book &b1, Book &b2)
{
    Book temp;
    temp.num = b1.num;
    temp.name = b1.name;
    temp.price = b1.price;

    b1.num = b2.num;
    b1.name = b2.name;
    b1.price = b2.price;

    b2.num = temp.num;
    b2.name = temp.name;
    b2.price = temp.price;
}

void sort(Book book[], int len)
{
    for(int i = 0; i < len; i++)
    {
        int jud = 0,rec = 0;
        for(int j = 0; j < len - 1; j++)
        {
            if(book[j].price < book[j+1].price)
            {
                exchange(book[j],book[j+1]);                
            }
        }
    }
}

void increasePrice(Book book[], int len)
{
    float aver = 0;
    for(int i = 0; i < len; i++)
    {
        aver += book[i].price;
    }
    aver /= len;
    for(int i = 0; i < len; i++)
    {
        if(book[i].price >= aver)
        {
            book[i].price *= 1.1;
        }
        else
        {
            book[i].price *= 1.2;
        }
    }
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<aver<<endl;
}

void reverse(Book book[], int len)
{
    int i = 0;
    int j = len - 1;
    for(; i < len/2; i++,j--)
    {
        exchange(book[i],book[j]);
    }
}

void searchPrice(Book book[], int len)
{
    int price = 0;
    int cnt = 0;
    Book temp[M];
    int rec = 0;
    for(int i = 0; i < len; i++)
    {
        if(book[i].price > price)
        {
            rec = i;
            price =  book[i].price;
        }
    }

    for(int i = 0; i < len; i++)
    {
        if(book[i].price == price)
        {
            temp[cnt].num = book[i].num;
            temp[cnt].name = book[i].name;
            temp[cnt].price = book[i].price;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    print(temp, cnt);
}

void searchFavourite(Book book[], int len, string content)
{
    int jud = 0;
    Book temp[M];
    for(int i = 0; i < len; i++)
    {
        if(book[i].name == content)
        {
            temp[jud] = book[i];
            jud++;
        }
    }
    if(jud == 0)
    {
        cout<<"Sorry，there is no your favourite!"<<endl;
    }
    else
    {
        cout<<jud<<endl;
        print(temp, jud);
    }

    
}  

void searchBest(Book book[], int len, int num)
{
    num--;
    if(num < 0)
    {
        cout<<"Sorry，the book on the best position doesn't exist!"<<endl;
    }
    for(int i = 0; i < len; i++)
    {
        if(num == i)
        {
            cout<<book[i].num<<" "<<book[i].name<<" "<<setiosflags(ios::fixed)<<setprecision(2)<<book[i].price<<endl;
        }
    }
}

void insert(Book book[], int len, int num, Book temp)
{
    if(num >= len)
    {
        cout<<"Sorry，the position to be inserted is invalid!"<<endl;
    }
    else
    {
        num -= 2;
        int j;
        for(j = len - 1; j > num; j--)
        {
            exchange(book[j],book[j+1]);
        }
        book[j+1] = temp;
        print(book, len+1);
    }
}

void pop(Book book[], int len, int num)
{

    if(num > len || num < 0)
    {
        cout<<"Sorry，the position to be deleted is invalid!"<<endl;
    }
    else
    {
        for(int i = --num; i < len; i++)
        {
            exchange(book[i], book[i+1]);
        }
        //print(book, len - 1);
    }
}

void deduplication(Book book[], int len, int &cnt)
{
    for(int i = 0; i < len-cnt; i++)
    {
        for(int j = 0; j < len-cnt; j++)
        {
            if(book[i].num == book[j].num && book[i].name == book[j].name && book[i].price == book[j].price && i != j)
            {
                for(int x = j; x < len; x++)
                {
                    book[x] = book[x+1];
                }
                cnt++;
            }
        }
    }
    cout<<len-cnt<<endl;
}

int main()
{
    Book book[M];
    int len;
    cin>>len;
    for(int i = 0; i < len; i++)
    {
        cin>>book[i].num>>book[i].name>>book[i].price;
    }
    int cnt = 0;
    deduplication(book, len, cnt);
    print(book, len-cnt);
    system("pause");

    return 0;
}