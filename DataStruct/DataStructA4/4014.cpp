//基于邻接表的长度为k的简单路径的求解
#include<iostream>

#define MVnum 100
#define MaxInt 0xfffffff

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
    VNode *vertices;
    int vexnum,arcnum;   
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

void creatALGraph(ALGraph &G)
{
    G.vertices = new VNode[MVnum];
    string data;
    cin>>data;
    for (int i = 0; i < G.vexnum; i++)
    {
        G.vertices[i].data = data[i];
        G.vertices[i].firstarc = new ArcNode;
        G.vertices[i].firstarc->adjvex = i+1;
        G.vertices[i].firstarc->nextarc = NULL;
    }
    VexTexType v1,v2;
    for(int i = 0; i < G.arcnum; i++)
    {
        cin>>v1>>v2;
        int x = locateIndex(G, v1);
        int y = locateIndex(G, v2);

        //v后面
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

void getRoad(ALGraph &G, int v, int visited[], int nodenum)
{
    visited[v] = ++nodenum;
    ArcNode *p = G.vertices[v].firstarc;
    while(p->nextarc != NULL)
    {
        int w = p->nextarc->adjvex;
        if(!visited[w-1])
            getRoad(G, w-1, visited, nodenum);
        p = p->nextarc;
    }
}

// void printALGraph(ALGraph &G)
// {
//     for(int i = 0; i < G.vexnum; i++)
//     {
//         while(G.vertices[i].firstarc->nextarc != NULL)
//         {
//             cout<<G.vertices[i].firstarc->adjvex<<" ";
//             G.vertices[i].firstarc = G.vertices[i].firstarc->nextarc;
//         }
//         cout<<G.vertices[i].firstarc->adjvex<<endl;
//     }
// }

int main()
{
    int m,n,len;
    while (cin>>m>>n>>len && (m != 0 && n != 0 && len != 0))
    {
        ALGraph G;
        G.vexnum = m;G.arcnum = n;
        creatALGraph(G);
        //printALGraph(G);
        VexTexType v1,v2;
        cin>>v1>>v2;
        int x = locateIndex(G, v1);
        int y = locateIndex(G, v2);
        int visited[MVnum] = { 0 };
        int nodenum = 0;
        getRoad(G, x, visited, nodenum);
        // for(int i = 0; i < G.vexnum; i++)
        // {
        //     cout<<visited[i]<<" ";
        // }
        if(visited[y]-1 == len)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        
    }
    system("pause");
    return 0;
}