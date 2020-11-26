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

void shortestPathMax(AMGraph &G, int v0, int d[], int path[])
{
    int n = G.vexnum;
    int s[MVNum] = { 0 };
    int v;
    for(v = 0; v < n; v++) //初始化
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
}

void road(AMGraph &G, int d[], int path[], int v_goal, int v0)
{
    cout<<d[v_goal]<<endl;
    char p[MVNum] = { 0 };
    int i = 0;
    while(path[v_goal] != -1)
    {
        p[i] = G.vexs[v_goal];
        v_goal = path[v_goal];
        i++;
    }
    p[i] = G.vexs[v0];
    while (i > 0)
    {
        cout<<p[i]<<" ";
        i--;
    }
    cout<<p[i]<<endl;
    
}

int main()
{
    int n,m;
    while (cin>>m>>n && (n != 0 && m != 0))
    {
        AMGraph G;
        createUDN(G, m, n);
        int d[MVNum] = { 0 }, path[MVNum] = { 0 };
        VerTexType x,y;
        cin>>x>>y;
        int v0 = locateIndex(G, x);
        int v_goal = locateIndex(G, y);
        shortestPathMax(G, v0, d, path);
        road(G, d, path, v_goal, v0);
    }
    system("pause");
    return 0;
}