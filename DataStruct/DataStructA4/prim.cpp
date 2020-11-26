//基于Dijsktra算法的最短路径求解

#include<iostream>
#define MaxInt 0xfffffff
#define MVNum 100

using namespace std;

typedef char VerTexType;
typedef int ArcType;

struct AMGraph
{
    VerTexType vexs[MVNum];
    ArcType arcs[MVNum][MVNum];
    int vexnum; //顶点
    int arcnum; //边数
};

int locateIndex(AMGraph &G, VerTexType v)
{
    for(int i = 0; i < G.vexnum; i++)
    {
        if(v == G.vexs[i])
        {
            return i;
        }
    }
    return -1;
}

void createUDN(AMGraph &G, int m, int n)
{
    G.vexnum = m; G.arcnum = n;

    //初始化
    for(int i = 0; i < m; i++)
        cin>>G.vexs[i];
    for(int i = 0; i < G.vexnum; i++)
        for(int j = 0; j < G.vexnum; j++)
            G.arcs[i][j] = MaxInt;
    //赋值
    VerTexType v1,v2;
    int w;
    for(int i = 0; i < G.arcnum; i++)
    {
        cin>>v1>>v2>>w;
        int x = locateIndex(G, v1);
        int y = locateIndex(G, v2);
        G.arcs[x][y] = w;
        G.arcs[y][x] = w;
    }
}

int getV(AMGraph G, VerTexType mst[])
{
    int j = 0;
    int u = -2;
    while(u != -1)
    {
        u = locateIndex(G, mst[j]);
        j++;
    }
    for(int i = 0; i < G.vexnum; i++)
    {

    }
}

void prim(AMGraph &G)
{
    VerTexType mst[MVNum] = { 0 };
    int n = G.vexnum;
    int d[MVNum] = { 0 };
    int s[MVNum] = { 0 };
    //初始化
    for(int i = 0; i < G.vexnum; i++)
    {
        
    }
    while (1)
    {
        int min = MaxInt;
        for(int w = 0; w < n; w++)
        {
            if(!s[w] && d[w] < min)
            {
                v = w;
                min = d[w];
            }
        }  
    }
     
}

int main()
{
    int n,m;
    while (cin>>m>>n && (n != 0 && m != 0))
    {
        AMGraph G;
        createUDN(G, m, n);
        int d[MVNum] = { 0 }, path[MVNum] = { 0 };
    }
    system("pause");
    return 0;
}