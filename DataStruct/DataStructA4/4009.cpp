//基于邻接表的边的删除

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
    for(int i = 0; i < G.arcnum; i++) //前插法
    {
        cin>>m>>n;
        int x = locateIndex(G, m);
        int y = locateIndex(G, n);
        //x后面
        G.vertices[x].firstarc->adjvex = x+1;
        ArcNode *temp_x = new ArcNode;
        temp_x->nextarc = G.vertices[x].firstarc->nextarc;
        G.vertices[x].firstarc->nextarc = temp_x;        
        temp_x->adjvex = y+1;

        //y后面
        G.vertices[y].firstarc->adjvex = y+1;
        ArcNode *temp_y = new ArcNode;
        temp_y->nextarc = G.vertices[y].firstarc->nextarc;
        G.vertices[y].firstarc->nextarc = temp_y;        
        temp_y->adjvex = x+1;
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

int main()
{
    int m,n;
    while(cin>>m>>n && (m != 0 && n != 0))
    {
        ALGraph G;
        G.vexnum = m;
        G.arcnum = n;
        createALGraph(G);
        deleteEdge(G);
        printALGraph(G);
    }
    system("pause");
    return 0;
}