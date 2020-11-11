#include<iostream>
#include<iomanip>

using namespace std;

struct Data
{
    string num;
    string name;
    float price;
};

struct LNode
{
    Data data;
    LNode* next;
};

LNode* creatList(LNode* l)
{
    l = new LNode;
    l->next = new LNode;

    return l;
}

void input(LNode* l, LNode* h, int num)
{
    Data inp;
    
    for(int i = 0; i < num; i++)
    {
        cin >> inp.num >> inp.name >> inp.price;
        l->data.num = inp.num; l->data.name = inp.name; l->data.price = inp.price;
        l->next = new LNode;
        l = l->next;
        l->next = NULL; 
    }
}

void input_reverse(LNode *l, LNode *h, int num)
{
    Data inp;
    h->next = NULL;
    for(int i = 0; i < num; i++)
    {
        cin>>inp.num>>inp.name>>inp.price;
        LNode *temp = new LNode;
        temp->data.num = inp.num; temp->data.name = inp.name; temp->data.price = inp.price;
        temp->next = h->next;
        h->next = temp;
    }
    //cout<<"c";
}

void print(LNode* l)
{
    while (l->next != NULL)
    {
        cout << l->data.num << " " << l->data.name << " " << setiosflags(ios::fixed) << setprecision(2) << l->data.price << endl;
        l = l->next;
    }
}

int count(LNode* l)
{
    int cnt = 0;
    while (l->next != NULL)
    {
        cnt++;
        l = l->next;
    }
    return cnt;
}

void exchange(LNode* l, LNode* p)
{
    //cout<<"???????"<<endl;
    //cout<<p->next->data.price<<" "<<l->data.price<<endl;
    p->next = l->next;
    l->next = p->next->next;
    p->next->next = l;
}



void increasePrice(LNode *l, LNode *h)
{
    float aver = 0;
    LNode *p = l;
    int len = count(p);
    while(l->next != NULL)
    {
        //cout<<l->data.price<<"xxx"<<endl;
        aver += l->data.price;
        l = l->next;
        
    }
    aver /= len;
    l = h->next;
    for(int i = 0; i < len + 1; i++)
    {
        if(l->data.price >= aver)
        {
            l->data.price *= 1.1;
        }
        else
        {
            l->data.price *= 1.2;
        }
        l = l->next;
    }
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<aver<<endl;
}

void searchPrice(LNode *h, int len)
{
    int price = 0;
    int cnt = 0;
    Data temp[1000];
    int rec = 0;
    LNode *p = h->next;
    for(int i = 0; i < len; i++)
    {
        if(p->data.price > price)
        {
            rec = i;
            price =  p->data.price;
        }
        p = p->next;
    }
    p = h->next;
    for(int i = 0; i < len; i++)
    {
        if(p->data.price == price)
        {
            temp[cnt].num = p->data.num;
            temp[cnt].name = p->data.name;
            temp[cnt].price = p->data.price;
            cnt++;
        }
        p = p->next;
    }
    cout<<cnt<<endl;
    for(int i = 0; i < cnt; i++)
    {
        cout<<temp[i].num<<" "<<temp[i].name<<" "<<setiosflags(ios::fixed)<<setprecision(2)<<temp[i].price<<endl;
    }
}

void searchFavourite(LNode *h, int len, string content)
{
    int jud = 0;
    LNode *p = h->next;
    Data temp[1000];
    for(int i = 0; i < len; i++)
    {
        if(p->data.name == content)
        {
            temp[jud].num = p->data.num; temp[jud].name = p->data.name; temp[jud].price = p->data.price;
            jud++;
        }
        p = p->next;
    }
    if(jud == 0)
    {
        cout<<"Sorry，there is no your favourite!"<<endl;
    }
    else
    {
        cout<<jud<<endl;
        for(int i = 0; i < jud; i++)
        {
            cout<<temp[i].num<<" "<<temp[i].name<<" "<<setiosflags(ios::fixed)<<setprecision(2)<<temp[i].price<<endl;
        }
    }

    
}  

void searchBest(LNode *h, int len, int num)
{
    num--;
    LNode *p = h->next;
    if(num < 0)
    {
        cout<<"Sorry，the book on the best position doesn't exist!"<<endl;
    }
    for(int i = 0; i < len; i++)
    {
        if(num == i)
        {
            cout<<p->data.num<<" "<<p->data.name<<" "<<setiosflags(ios::fixed)<<setprecision(2)<<p->data.price<<endl;
        }
        p = p->next;
    }
}

void insert(LNode *h, int lens, int num, Data temp)
{
    LNode *p = h->next;
    if(num >= lens)
    {
        cout<<"Sorry，the position to be inserted is invalid!"<<endl;
    }
    else
    {
        LNode *t = new LNode;
        t->data.num = temp.num; t->data.name = temp.name; t->data.price = temp.price;
        num-= 2;
        for(int i = 0; i < num; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
        print(h->next);
    }
}

void pop(LNode *h, int lens, int poi)
{
    if(poi > lens || poi < 1)
    {
        cout<<"Sorry，the position to be deleted is invalid!"<<endl;
    }
    else
    {
        poi--;
        LNode *p = h;
        for(int i = 0; i < poi; i++)
        {
            p = p->next;
        }
        p->next = p->next->next;
        print(h->next);
    }
    
}

void deduplication(LNode *h, int len, int &cnt)
{
    LNode *pi = h->next,*pj = h->next,*pjj;

    for(int i = 0; i < len-cnt; i++,pi = pi->next)
    {
        if(pi == NULL)
        {
            break;
        }
        pj = h->next;
        pjj = h;
        for(int j = 0; j < len-cnt; j++, pj = pj->next, pjj = pjj->next)
        {
            if(pi == NULL || pj == NULL)
            {
                break;
            }
            if(pi->data.num == pj->data.num && pi->data.name == pj->data.name && pi->data.price == pj->data.price && i != j)
            {
                pjj->next = pj->next;
                cnt++;
            }
        }
    }
    cout<<len-cnt<<endl;
    print(h->next);
}

int main()
{
    LNode* l, * h;
    l = new LNode;
    l->next = new LNode;
    h = l;

    l = l->next;
    int lens;
    cin>>lens;
    input(l, h, lens);
    
    int cnt = 0;
    deduplication(h, lens, cnt);
    
    system("pause");

    return 0;
}