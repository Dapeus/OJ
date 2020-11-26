//基于链地址法的散列表的插入

#include<iostream>

using namespace std;

typedef int DataType;
struct HashNode
{
    DataType data;
    HashNode *next;
};

struct Hash
{
    HashNode **nodes;
};

void createHash(Hash &H, int n)
{
    for(int i = 0 ; i < 13; i++)
    {
        H.nodes[i] = new HashNode;
        H.nodes[i]->next = NULL;
    }
    for(int i = 0; i < n; i++)
    {
        int t;
        cin>>t;
        int key = t % 13;
        HashNode *p = H.nodes[key];
        while (p->next)
        {
            p = p->next;
        }
        HashNode *temp = new HashNode;
        p->next = temp;
        temp->data = t;
        temp->next = NULL;
    }

}

void insert(Hash &H)
{
    int t;
    cin>>t;
    int key = t % 13;
    HashNode *p = H.nodes[key];
    while (p->next)
    {
        p = p->next;
    }
    HashNode *temp = new HashNode;
    p->next = temp;
    temp->data = t;
    temp->next = NULL;
}

void printHash(Hash H)
{
    for(int i = 0 ; i < 13; i++)
    {
        cout<<i;
        HashNode *p = H.nodes[i]->next;
        while (p)
        {
            cout<<" "<<p->data;
            p = p->next;
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    while(cin>>n && n != 0)
    {
        Hash H;
        H.nodes = new HashNode*[12];
        createHash(H, n);
        insert(H);
        printHash(H);
    }
    system("pause");
    return 0;
}