//六度空间理论

//基于邻接矩阵的新顶点的增加

#include<iostream>
#include<iomanip>
#include<queue>
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

// int locateIndex(AMGraph &G, VerTexType v)
// {
//     for(int i = 0; i < G.vexnum; i++)
//     {
//         if(v == G.arcs[i])
//         {
//             return i;
//         }
//     }
//     return -1;
// }

void createUDN(AMGraph &G, int n, int m)
{
    G.vexnum = n; G.arcnum = m;

    //初始化

    for(int i = 0; i < G.vexnum; i++)
        for(int j = 0; j < G.vexnum; j++)
            G.arcs[i][j] = MaxInt;

    //赋值
    int v1,v2;
    for(int i = 0; i < G.arcnum; i++)
    {
        cin>>v1>>v2;
        G.arcs[v1-1][v2-1] = 1; G.arcs[v2-1][v1-1] = 1;
    } 
}

int getFirst(AMGraph &G, int u)
{
    for(int i = 0; i < G.vexnum; i++)
    {
        if(G.arcs[u][i] == 1)
        {
            return i;
        }
    }
    return -1;
}

int getNeighbor(AMGraph &G, int u, int w)
{
    for(int i = w+1; i < G.vexnum; i++)
    {
        if(G.arcs[u][i] == 1)
        {
            return i;
        }
    }
    return -1;
}

int cnt(AMGraph G, int u, int visited[])
{
    int c = 0;
    for(int i = 0; i < G.vexnum; i++)
    {
        if(G.arcs[u][i] == 1 && !visited[i])
        {
            c++;
        }
    }
    return c;
}

void sixDegree_BFS(AMGraph &G, int v)
{
    int visit_num = 1;
    int start = v;
    int visited[MVNum] = { 0 };
    visited[v] = 1;
    int level = 0;
    int last = v;
    int tail = 0;
    queue<int> q;
    q.push(v);
    while(!q.empty())
    {
        v = q.front();
        q.pop();
        for(int w = getFirst(G, v); w >= 0; w = getNeighbor(G, v, w))
        {
            if(!visited[w])
            {
                visited[w] = 1;
                visit_num++;
                q.push(w);
                tail = w;
            }
        }
        if(v == last)
        {
            level++;
            last = tail;
        }
        if(level == 6)
        {
            break;
        }
    }
    double num = 100*double(visit_num)/double(G.vexnum);
    cout<<start+1<<": "<<fixed<<setprecision(2)<<num<<"%"<<endl;
}

int main()
{
    int n,m;
    while (cin>>n>>m && (n != 0 && m != 0))
    {
        AMGraph G;
        createUDN(G, n, m);
        for(int i = 0; i < G.vexnum; i++)
            sixDegree_BFS(G, i);
    }
    system("pause");
    return 0;
}