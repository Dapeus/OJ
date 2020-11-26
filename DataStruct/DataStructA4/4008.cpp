//基于邻接矩阵的新边的增加

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
    for(int i = 0; i <= G.vexnum; i++)
        G.arcs[i][0] = G.arcs[0][i] = i;
    for(int i = 1; i <= G.vexnum; i++)
        for(int j = 1; j <= G.vexnum; j++)
            G.arcs[i][j] = 0;

    //赋值
    int v1,v2;
    for(int i = 0; i < G.arcnum; i++)
    {
        cin>>v1>>v2;
        G.arcs[v1][v2] = 1; G.arcs[v2][v1] = 1;
    } 
}

void addEdge(AMGraph &G)
{
    int v1,v2;
    cin>>v1>>v2;
    G.arcs[v1][v2] = 1; G.arcs[v2][v1] = 1;
    for(int i = 0; i <= G.vexnum; i++)
    {
        int j;
        for(j = 0; j < G.vexnum; j++)
        {
            cout<<G.arcs[i][j]<<" ";
        }
        cout<<G.arcs[i][j]<<endl;
    }
}

int main()
{
    int m,n;
    while (cin>>m>>n && (n != 0 && m != 0))
    {
        AMGraph G;
        createUDN(G, m, n);
        addEdge(G);
    }
    system("pause");
    return 0;
}