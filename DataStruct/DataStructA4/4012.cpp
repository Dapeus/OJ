//最长的最短路径的求解

#include<iostream>
#define MaxInt 0xfffffff
#define MVNum 100

using namespace std;

typedef char VerTexType;
typedef int ArcType;

struct AMGraph
{
    ArcType arcs[MVNum][MVNum];
    int vexnum; //顶点
    int arcnum; //边数
};

void createUDN(AMGraph &G, int m, int n)
{
    G.vexnum = m; G.arcnum = n;

    //初始化
    // for(int i = 0; i <= G.vexnum; i++)
    //     G.arcs[i][0] = G.arcs[0][i] = i;
    for(int i = 0; i < G.vexnum; i++)
        for(int j = 0; j < G.vexnum; j++)
            G.arcs[i][j] = MaxInt;

    //赋值
    int v1,v2,w;
    for(int i = 0; i < G.arcnum; i++)
    {
        cin>>v1>>v2>>w;
        G.arcs[v1-1][v2-1] = w; G.arcs[v2-1][v1-1] = w;
    }
}

void longestShortestRoad(AMGraph &G, int v0, int path[], int d[])
{
    int n = G.vexnum;
    int s[MVNum] = { 0 };
    int v;
    for(v = 0; v < n; v++)
    {
        s[v] = 0;
        d[v] = G.arcs[v0][v];
        if(d[v] < MaxInt)
            path[v] = v0;
        else
            path[v] = -1;
    }
    s[v0] = true;
    d[v0] = 0;

    for(int i = 1; i < n; i++)
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
        s[v] = true;

        for(int w = 0; w < n; w++)
        {
            if(!s[w] && (d[v] + G.arcs[v][w] < d[w]))
            {
                d[w] = d[v] + G.arcs[v][w];
                path[w] = v;
            }
        }
    }
    int max = 0;
    int index = 0;
    for(int i = 0; i < G.vexnum; i++)
    {
        if(d[i] > max)
        {
            max = d[i];
            index = i;
        }
    }
    cout<<index+1<<endl<<max<<endl;
}

void printAMGraph(AMGraph G)
{
    for(int i = 0; i < G.vexnum; i++)
    {
        int j = 0;
        for(; j < G.vexnum; j++)
        {
            cout<<G.arcs[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int m,n;
    while (cin>>m>>n && (n != 0 && m != 0))
    {
        AMGraph G;
        createUDN(G, m, n);
        //printAMGraph(G);
        int v;
        cin>>v;
        v--;
        int d[MVNum] = { 0 }, path[MVNum] = { 0 };
        longestShortestRoad(G, v, path, d);
    }
    system("pause");
    return 0;
}