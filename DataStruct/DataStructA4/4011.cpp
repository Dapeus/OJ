//基于邻接表的深度优先遍历 //递归

#include<iostream>

#define MVNum 100

using namespace std;

typedef char VexTexType;
struct ArcNode
{
    int adjvex;
    ArcNode *nextarc;
};

struct VNode
{
    VexTexType data;
    ArcNode *firstarc;
};

struct ALGraph
{
    VNode* vertices;
    int vexnum, arcnum;
};

int locateIndex(ALGraph &G, VexTexType t)
{
    for(int i = 0; i < G.vexnum; i++)
    {
        if(t == G.vertices[i].data)
        {
            return i;
        }
    }
    return -1;
}

void createALGraph(ALGraph &G)
{
    G.vertices = new VNode[MVNum];
    for(int i = 0; i < G.vexnum; i++)
    {
        G.vertices[i].data = char(i+49);
        G.vertices[i].firstarc = new ArcNode;
        G.vertices[i].firstarc->adjvex = i+1;
        G.vertices[i].firstarc->nextarc = NULL;
    }
    VexTexType m,n;
    for(int i = 0; i < G.arcnum; i++) //后插法创建
    {
        cin>>m>>n;
        int x = locateIndex(G, m);
        int y = locateIndex(G, n);
        //x后面
        ArcNode *temp_x = new ArcNode;
        ArcNode *p_x = G.vertices[x].firstarc;
        while(p_x->nextarc != NULL)
        {
            p_x = p_x->nextarc;
        }
        p_x->nextarc = temp_x;        
        temp_x->adjvex = y+1;
        temp_x->nextarc = NULL;
        //y后面
        ArcNode *temp_y = new ArcNode;
        ArcNode *p_y = G.vertices[y].firstarc;
        while (p_y->nextarc != NULL)
        {
            p_y = p_y->nextarc;
        }
        p_y->nextarc = temp_y;        
        temp_y->adjvex = x+1;
        temp_y->nextarc = NULL;
    }
}

void deleteEdge(ALGraph &G)
{
    VexTexType m,n;
    cin>>m>>n;
    int x = locateIndex(G, m);
    int y = locateIndex(G, n);
    //x后面
    ArcNode *p_x = G.vertices[x].firstarc;
    while(p_x->nextarc != NULL)
    {
        if(p_x->nextarc->adjvex == y+1)
        {
            p_x->nextarc = p_x->nextarc->nextarc;
        }
        p_x = p_x->nextarc;
        if(p_x == NULL)
        {
            break;
        }
    }

    //y后面
    ArcNode *p_y = G.vertices[y].firstarc;
    while (p_y->nextarc != NULL)
    {
        if(p_y->nextarc->adjvex == x+1)
        {
            p_y->nextarc = p_y->nextarc->nextarc;
        }
        p_y = p_y->nextarc;
        if(p_y == NULL)
        {
            break;
        }
    }
    G.arcnum--;
}

void printALGraph(ALGraph &G)
{
    for(int i = 0; i < G.vexnum; i++)
    {
        while(G.vertices[i].firstarc->nextarc != NULL)
        {
            cout<<G.vertices[i].firstarc->adjvex<<" ";
            G.vertices[i].firstarc = G.vertices[i].firstarc->nextarc;
        }
        cout<<G.vertices[i].firstarc->adjvex<<endl;
    }
}

void DFS(ALGraph &G, int v, int &cnt, int visited[])
{
    if(cnt == G.vexnum - 1)
    {
        cout<<v<<endl;
    }
    else
    {
        cout<<v<<" ";
        cnt++;
    }
    visited[v-1] = 1;
    ArcNode *p = G.vertices[v-1].firstarc;
    while(p->nextarc != NULL)
    {
        int w = p->nextarc->adjvex;
        if(!visited[w-1])
            DFS(G, w, cnt, visited);
        p = p->nextarc;
    }
}

int main()
{
    int m,n;
    while(cin>>m>>n && (m != 0 && n != 0))
    {
        ALGraph G;
        G.vexnum = m;
        G.arcnum = n;
        createALGraph(G);
        int visited[MVNum] = { 0 };
        int cnt = 0;
        int start;
        cin>>start;
        DFS(G, start, cnt, visited);
    }
    system("pause");
    return 0;
}