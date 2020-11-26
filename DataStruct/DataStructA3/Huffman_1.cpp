#include<iostream>
#include<bits/stdc++.h>
#define M 10000
using namespace std;

struct HTNode
{
    int weight;
    int parent,lchild,rchild;
};

void select(HTNode *HT, int n, int &s1, int &s2)
{
    int min1 = 1000000, min2 = 1000000;
    for(int i = 1; i <= n; i++)
    {
        if(HT[i].weight < min1 && HT[i].parent == 0)
        {
            min1 = HT[i].weight;
            s1 = i;
        }
    }
    int temp = HT[s1].weight;
    HT[s1].weight = 1000000;
    for(int i = 1; i <= n; i++)
    {
        if(HT[i].weight < min2 && HT[i].parent == 0)
        {
            min2 = HT[i].weight;
            s2 = i;
        }
    }
    HT[s1].weight = temp;
}

void createHuffmanTree(HTNode *&HT, int n, int a[])
{
    if(n < 1)
    {
        return;
    }
    int m = 2 * n - 1;
    HT = new HTNode[m+1];
    for(int i = 1; i <= m; i++)
    {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }
    for(int i = 1, j = 0; i <= n; j++)
    {
        if(a[j] != 0)
        {
            HT[i].weight = a[j];
            i++;
        }
    }

    for(int i = n+1; i <= m ; i++)
    {
        int s1,s2;
        select(HT, i-1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;

        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }

}

int statistics(string s, int *a)
{
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        a[s[i] - 'a']++;
    }
    int jud = 0;
    for (int i = 0; i < 26; i++)
    {
        if(a[i] != 0)
        {
            if(jud == 0)
            {
                cnt++;
                cout<<char('a'+ i)<<':'<<a[i];
                jud = 1;
            }
            else
            {
                cnt++;
                cout<<' '<<char('a'+ i)<<':'<<a[i];
            }    
        }
    }
    cout<<endl;
    return cnt;
}

void printTree(HTNode *HT, int n)
{
    for(int i = 1; i <= 2*n-1; i++)
    {
        cout<<i<<' '<<HT[i].weight<<' '<<HT[i].parent<<' '<<HT[i].lchild<<' '<<HT[i].rchild<<endl;
    }
}

void creatHuffmanCode(HTNode *HT, string *HTcode, int n, int a[])
{
    int i, start, c, f;
    
    for(i = 1; i <= n; i++)
    {
        start = n - 1;
        c = i;
        f = HT[i].parent;
        string cd = "";
        while (f != 0)
        {
            --start;
            if(HT[f].lchild == c)
            {
                cd.push_back('0');
            }
            else
            {
                cd.push_back('1');
            }
            c = f;
            f = HT[f].parent;
        }
        reverse(cd.begin(),cd.end());
        HTcode[i] = cd;
    }
    i = 1;
    int jud = 0;
    for(int j = 0; j < 26; j++)
    {
        if(a[j] != 0)
        {
            if(jud == 0)
            {
                cout<<char('a'+j)<<':'<<HTcode[i];
                i++;
                jud = 1;
            }
            else
            {
                cout<<' '<<char('a'+j)<<':'<<HTcode[i];
                i++;
            }
        }
    }
    string *temp = new string[26];
    i = 1;
    for(int j = 0; j < 26; j++)
    {
        if(a[j] != 0)
        {
            temp[j] = HTcode[i];
            i++;
        }
    }
    for(int j = 0; j < 26; j++)
    {
        HTcode[j] = temp[j];
    }
    cout<<endl;
}

void printCode(string *HTcode, int n, string s)
{
    for(int i = 0; i <= s.length(); i++)
    {
        cout<<HTcode[int(s[i]-'a')]; //wrong
    }
    cout<<endl;
    cout<<s<<endl;
}

int main()
{
    string s;
    while (cin>>s && s != "0")
    {
        HTNode *HT;
        
        int a[26] = { 0 };
        int cnt = statistics(s, a);
        string *HTcode = new string[26];
        createHuffmanTree(HT, cnt, a);
        printTree(HT, cnt);
        creatHuffmanCode(HT, HTcode, cnt, a);
        printCode(HTcode, cnt, s);
    }
    
    return 0;
}