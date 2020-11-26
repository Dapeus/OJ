//基于深度优先搜索的两顶点路径存在与否的判断

#include<iostream>
#define MaxInt 0xfffffff
#define MVNum 100

using namespace std;

typedef char VerTexType;
typedef int ArcType;

struct AMGraph
{
    ArcType arcs[MVNum][MVNum];
    VerTexType vexs[MVNum];
    int vexnum; //顶点
    int arcnum; //边数
};

int locateIndex(AMGraph G, int v)
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
    //初始化
    G.vexnum = m; G.arcnum = n;
    string temp;
    cin>>temp;
    for(int i = 0; i < G.vexnum; i++)
    {
        G.vexs[i] = temp[i];
    }
    for(int i = 0; i < G.vexnum; i++)
        for(int j = 0; j < G.vexnum; j++)
            G.arcs[i][j] = MaxInt;

    //赋值
    VerTexType v1,v2;
    for(int i = 0; i < G.arcnum; i++)
    {
        cin>>v1>>v2;
        int x = locateIndex(G, v1);
        int y = locateIndex(G, v2);
        G.arcs[x][y] = 1; G.arcs[y][x] = 1;
    }
}

void isRoad_DFS(AMGraph G, int &cnt, int v1, int visited[])
{
    if(cnt == G.vexnum)
    {
        return;
    }
    else
    {
        cnt++;
    }
    visited[v1] = 1;
    int x,y;
    for(int i = 0; i < G.vexnum; i++)
    {
        if(!visited[i] && G.arcs[v1][i] < MaxInt)
        {
            x = i;
            isRoad_DFS(G, cnt, x, visited);
        }
    }
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
        printAMGraph(G);
        VerTexType v1,v2;
        cin>>v1>>v2;
        int x = locateIndex(G, v1);
        int y = locateIndex(G, v2);
        int visited[MVNum] = { 0 };
        int cnt = 0;
        isRoad_DFS(G, cnt, x, visited);
        if(visited[y] == 1)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        
        for(int i = 0; i < G.vexnum; i++)
        {
            cout<<visited[i]<<" ";
        }
        //cout<<endl;
    }
    system("pause");
    return 0;
}