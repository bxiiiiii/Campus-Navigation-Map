#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
//#include "list.h"

#define MAX_V 20
#define MAX_G 10

typedef struct 
{
    char password[20];
    int vexnum;
    int arcnum;
}Info;
 
typedef struct
{
    char vex[30];
    char adjvex[30];
    int weight[4];  
    char info[100];     
}EdgeInfo;
 
typedef struct ArcNode
{
    //int adjvex;
    struct ArcNode *nextarc;
    EdgeInfo info;
}ArcNode;
 
typedef struct
{
    char name[30];
    char info[100];
    int x, y;
}VertexData;
  
typedef struct
{
    VertexData data;
    ArcNode *firstarc;
}VertexNode;
 
typedef struct
{
    VertexNode vertex[MAX_V];
    Info info;
//  GraphKind kind;
}AdjList;

typedef struct
{
    int fa;
    int id;
    int w;
}Dnode;

typedef struct node
{
    Dnode data;
    struct node* next;
}queue_node;

typedef struct 
{
    queue_node *front;
    queue_node *rear;
}Queue;

typedef struct
{
    int path[MAX_V];
    int index;
}Path;

void list_add(VertexNode *vnode, ArcNode *node);
void list_del(VertexNode *vnode, char *name);

Queue *InitQueue();
void Push(Queue *list, Dnode node);
Dnode Pop(Queue *list);
int Isempty(Queue *list);
 
int CreatGraph(AdjList *list);
int InitGraph(AdjList *list);
int Login(AdjList *list);
int ChangePass(AdjList *list);
int SaveGraph(AdjList *list);
int SearchVertex(AdjList *list, char *name);
int InsertVertex(AdjList *list);
int ModifyVertex(AdjList *list);
int DeleteVertex(AdjList *list);
int InsertEdge(AdjList *list);
int ModifyEdge(AdjList *list);
int DeleteEdge(AdjList *list);
int Dijkstra(AdjList *list, int flag);
void PrintNode(AdjList *list);
void PrintPath(AdjList *list);