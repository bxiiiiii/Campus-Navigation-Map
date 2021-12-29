#include "Operations.h"
 
void PrintNode(AdjList *list)
{
    // printf("         name ")
    for(int i = 0; i < MAX_V; i++){
        if(!strcmp(list->vertex[i].data.name, "0"))
            continue;
        printf("name : %s\n", list->vertex[i].data.name);
        printf("info : %s\n", list->vertex[i].data.info);
        printf("coordinate : x-%d y-%d\n", list->vertex[i].data.x, list->vertex[i].data.y);
    }
}

void PrintPath(AdjList *list)
{
    for(int i = 0; i < MAX_V; i++){
        if(!strcmp(list->vertex[i].data.name, "0"))
            continue;
        for(ArcNode *p = list->vertex[i].firstarc; p; p = p->nextarc){
            printf("sta : %s\n", p->info.vex);
            printf("des : %s\n", p->info.adjvex);
            printf("info : %s\n", p->info.info);
        }
    }
}
 
int CreatGraph(AdjList *list)
{
    int data;
    int index = 0;
    char password[20];
    EdgeInfo edgeinfo;
    VertexData vertexdata;
    FILE *fp_node, *fp_edge, *fp_info;
    for(int i = 0; i < MAX_V; i++)
        strcpy(list->vertex[i].data.name, "0");
     
    fp_info = fopen("../file/info.txt", "r");
    if(fp_info == NULL) {
        printf("open info.txt failed\n");
        return -1;
    }
    if(!fread(&list->info, sizeof(Info), 1, fp_info)) 
        return 1;

    printf("%d %d %s\n", list->info.vexnum, list->info.arcnum, list->info.password);
    fp_node = fopen("../file/node.txt", "r");
    if(fp_node == NULL) {
        printf("open node.txt failed\n");
        return -1;
    }
    while(!feof(fp_node)) {
        if(fread(&vertexdata, sizeof(VertexData), 1, fp_node)){
            list->vertex[index].firstarc = NULL;
            list->vertex[index++].data = vertexdata;
        }
    }
    printf("%d\n", index);

    fp_edge = fopen("../file/edge.txt", "r");
    if(fp_edge == NULL) {
        printf("open edge.txt failed\n");
        return -1;
    }
    while(!feof(fp_edge)) {
        if(fread(&edgeinfo, sizeof(EdgeInfo), 1, fp_edge)){
            ArcNode *newNode = (ArcNode *) malloc (sizeof(ArcNode));
	        newNode->info = edgeinfo;
            for(int i = 0; i < MAX_V; i++){
                if(!strcmp(edgeinfo.vex, list->vertex[i].data.name)){
                    list_add(&list->vertex[i], newNode);
                    break;
                }
            }
        }
    }

    return 0;
}

int InitGraph(AdjList *list)
{
    char password[30] = "123456";
    list->info.arcnum = 0;
    list->info.vexnum = 0;
    strcpy(list->info.password, password);
}
 
int SaveGraph(AdjList *list)
{
    FILE *fp_node, *fp_edge, *fp_info;

    fp_info = fopen("../file/info.txt", "w");
    if(fp_info == NULL) {
        printf("open info.txt failed\n");
        return -1;
    }
    fwrite(&list->info, sizeof(Info), 1, fp_info);
    fclose(fp_info);

    fp_node = fopen("../file/node.txt", "w");
    if(fp_node == NULL) {
        printf("open node.txt failed\n");
        return -1;
    }
    for(int i = 0; i < MAX_V; i++){
        if(!strcmp(list->vertex[i].data.name, "0"))
            continue;
        fwrite(&list->vertex[i].data, sizeof(VertexData), 1, fp_node);
    }
    fclose(fp_node);

    fp_edge = fopen("../file/edge.txt", "w");
    if(fp_edge == NULL) {
        printf("open edge.txt failed\n");
        return -1;
    }
    for(int i = 0; i < MAX_V; i++){
        if(!strcmp(list->vertex[i].data.name, "0"))
            continue;
        for(ArcNode *p = list->vertex[i].firstarc; p; p = p->nextarc)
            fwrite(&p->info, sizeof(EdgeInfo), 1, fp_edge);
    }
    fclose(fp_edge);
    
    return 0;
}
 
int SearchVertex(AdjList *list, char *name)
{
    for(int i = 0; i < MAX_V; i++) {
        if(!strcmp(name, list->vertex[i].data.name)) {
            printf("name:%s\n", name);
            printf("info:%s\n", list->vertex[i].data.info);
            printf("coordinate:x-%d y-%d\n", list->vertex[i].data.x, list->vertex[i].data.y);
            return 0;
        }
    }

    return 1;
}
 
int InsertVertex(AdjList *list)
{
    if(list->info.vexnum >= MAX_V)
        return 1;

    VertexNode *node = (VertexNode *) malloc (sizeof(VertexNode));
    node->firstarc = NULL;
    printf("please enter name of the new node:");
    scanf("%s", node->data.name);
    printf("please enter info of the new node:");
    scanf("%s", node->data.info);
    printf("please enter coordinate of the new node:");
    scanf("%d %d", &node->data.x, &node->data.y);
    for(int i = 0; i < MAX_V; i++){
        if(!strcmp(list->vertex[i].data.name, "0")){
            list->vertex[i] = *node;
            break;
        }   
    } 
    list->info.vexnum++;

    printf("insert successful.\n");
    return 0;
}
 
int ModifyVertex(AdjList *list)
{
    int choice;
    char info[100];
    char name[30], newname[30];
    VertexNode *node = NULL;

    printf("please enter the name:");
    scanf("%s", name);
    if(SearchVertex(list, name)) {
        printf("not found\n");
        return 1;
    }

    for(int i = 0; i < MAX_V; i++)
        if(!strcmp(name, list->vertex[i].data.name)){
            node = &list->vertex[i];
            break;
        }
            

    while(1) {
        printf("[1]name\n");
        printf("[2]info\n");
        printf("[3]x of coordinate\n");
        printf("[4]y of coordinate\n");
        printf("[5]return\n");
        printf("enter your choice plz:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter name plz:");
            scanf("%s", newname);
            strcpy(node->data.name, newname);
            for(ArcNode *p = node->firstarc; p; p = p->nextarc){
                strcpy(p->info.vex, newname);
                for(int j = 0; j < MAX_V; j++){
                    if(!strcmp(p->info.adjvex, list->vertex[j].data.name)){
                        for(ArcNode *q = list->vertex[j].firstarc; q; q = q->nextarc){
                            if(!strcmp(q->info.adjvex, name)){
                                strcpy(q->info.adjvex, newname);
                            }
                        }
                    }
                }
            }      
            break;
        case 2:
            printf("enter info plz:");
            scanf("%s", info);
            strcpy(node->data.info, info);
            break;
        case 3:
            printf("enter x of coordinate plz:");
            scanf("%d", &node->data.x);
            break;
        case 4:
            printf("enter y of coordinate plz:");
            scanf("%d", &node->data.y);
            break;
        case 5:
            return 0;
        default:
            printf("enter correct choice plz.\n");
        }
    }

    printf("modify successful.\n");
    return 0;
}
 
int DeleteVertex(AdjList *list)
{
    int confirm;
    int edge_num = 0;
    char name[30];
    printf("enter name plz");
    scanf("%s", name);
    if(SearchVertex(list, name)){
        printf("not found.\n");
        return 1;
    }

    while(1) {
        printf("confirm delete(0-no, 1-yes):");
        scanf("%d", &confirm);
        if(confirm == 1){
            for(int i = 0; i < MAX_V; i++){
                if(!strcmp(name, list->vertex[i].data.name)){
                    for(ArcNode *p = list->vertex[i].firstarc; p; p = p->nextarc){
                        edge_num++;
                        for(int j = 0; j < MAX_V; j++){
                            if(!strcmp(p->info.adjvex, list->vertex[j].data.name)){
                                list_del(&list->vertex[j], name);
                                break;
                            }
                        }
                        list_del(&list->vertex[i], p->info.adjvex);
                    }
                    strcpy(list->vertex[i].data.name, "0");
                    break;
                }
            }
            list->info.vexnum--;
            list->info.arcnum -= edge_num;
            printf("delete successful.\n");
            return 0;
        }else if(confirm == 0){
            return 0;
        } else 
            printf("enter correct choice plz.\n");
    }
}
 
int InsertEdge(AdjList *list)
{
    char sta[30], des[30], info[100];
    printf("enter sta name plz:");
    scanf("%s", sta);
    if(SearchVertex(list, sta)){
        printf("sta not found.\n");
        return 1;
    }

    printf("enter des name plz:");
    scanf("%s", des);
    if(SearchVertex(list, des)){
        printf("des not found.\n");
        return 1;
    }

    ArcNode *node = (ArcNode *) malloc (sizeof(ArcNode));
    strcpy(node->info.vex, sta);
    strcpy(node->info.adjvex, des);
    printf("enter info plz:");
    scanf("%s", info);
    strcpy(node->info.info, info);
//   weight initialization
    printf("enter weight0 plz.:");
    scanf("%d", &node->info.weight[0]);
    for(int i = 0; i < MAX_V; i++)
        if(!strcmp(sta, list->vertex[i].data.name)){
            list_add(&list->vertex[i], node);
            break;
        }

    ArcNode *node2 = (ArcNode *) malloc (sizeof(ArcNode));
    strcpy(node2->info.vex, des);
    strcpy(node2->info.adjvex, sta);
    strcpy(node2->info.info, info);
//   weight initialization
    node2->info.weight[0] = node->info.weight[0];
    for(int i = 0; i < MAX_V; i++)
        if(!strcmp(des, list->vertex[i].data.name)){
            list_add(&list->vertex[i], node2);
            break;
        }

    list->info.arcnum++;
    printf("insert successful.\n");
    return 0;
}
 
int ModifyEdge(AdjList *list)
{
    int choice;
    int weight;
    ArcNode *p = NULL, *q = NULL;
    char sta[30], des[30], info[100];

    printf("enter sta name plz:");
    scanf("%s", sta);
    if(SearchVertex(list, sta)){
        printf("sta not found.\n");
        return 1;
    }

    printf("enter des name plz:");
    scanf("%s", des);
    if(SearchVertex(list, des)){
        printf("des not found.\n");
        return 1;
    }

    for(int i = 0; i < MAX_V; i++){
        if(!strcmp(sta, list->vertex[i].data.name)){
            for(p = list->vertex[i].firstarc; p; p = p->nextarc){
                if(!strcmp(des, p->info.adjvex)){
                    break;
                }
            }
        }
        if(!strcmp(des, list->vertex[i].data.name)){
            for(q = list->vertex[i].firstarc; q; q = q->nextarc){
                if(!strcmp(sta, q->info.adjvex)){
                    break;
                }
            }
        }
    }
    
    if(p == NULL && q == NULL){
        printf("edge not found.\n");
        return -1;
    }

    while(1) {
        printf("[1]info\n");
        printf("[2]weight1\n");
        printf("[3]weight2\n");
        printf("[4]weight3\n");
        printf("[5]weight4\n");
        printf("[6]return\n");
        printf("enter your choice plz:");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                //memset(p->info.info, 0, sizeof(p->info.info));
                //memset(q->info.info, 0, sizeof(q->info.info));
                printf("enter info plz.:\n");
                printf("**\n");
                scanf("%s", info);
                printf("%s %s\n",p->info.info, q->info.info);
                strcpy(p->info.info, info);
                strcpy(q->info.info, info);
                break;
            case 2:
                printf("enter weight1 plz.\n");
                scanf("%d", &weight);
                p->info.weight[0] = weight;
                break;
            case 3:
                printf("enter weight2 plz.\n");
                scanf("%d", &weight);
                p->info.weight[1] = weight;
                break;
            case 4:
                printf("enter weight3 plz.\n");
                scanf("%d", &weight);
                p->info.weight[2] = weight;
                break;
            case 5:
                printf("enter weight4 plz.\n");
                scanf("%d", &weight);
                p->info.weight[3] = weight;
                break;
            case 6:
                return 0;
            default:
                printf("enter correct choice plz.\n");
        }
    }

    printf("modify successful.\n");
    return 0;
}
 
int DeleteEdge(AdjList *list)
{
    char sta[30], des[30];
    printf("enter sta name plz:");
    scanf("%s", sta);
    if(SearchVertex(list, sta)){
        printf("sta not found.\n");
        return 1;
    }

    printf("enter des name plz:");
    scanf("%s", des);
    if(SearchVertex(list, des)){
        printf("des not found.\n");
        return 1;
    }

    for(int i = 0; i < MAX_V; i++){
        if(!strcmp(sta, list->vertex[i].data.name)){
            list_del(&list->vertex[i], des);
        }
        if(!strcmp(des, list->vertex[i].data.name)){
            list_del(&list->vertex[i], sta);
        }
    }

    list->info.arcnum--;
    printf("delete successful.\n");
    return 0;
}
 
int Dijkstra(AdjList *list, int flag)
{
    char sta[30], des[30];
    int start, end;
    int path[MAX_V];
    int visited[MAX_V] = {0};
    Dnode dist[MAX_V];
    Queue *queue = InitQueue();

    printf("enter sta name plz:");
    scanf("%s", sta);
    if(SearchVertex(list, sta)){
        printf("sta not found.\n");
        return 1;
    }
    printf("enter des name plz:");
    scanf("%s", des);
    if(SearchVertex(list, des)){
        printf("des not found.\n");
        return 1;
    }

    for(int i = 0; i <list->info.vexnum; i++){
        if(!strcmp(sta, list->vertex[i].data.name)){
            start = i;
        }
        if(!strcmp(des, list->vertex[i].data.name)){
            end = i;
        }
    }
    printf("%d %d\n", start, end);
    for(int i = 0; i < list->info.vexnum; i++){
        dist[i].id = i;
        dist[i].w = 30000;
        path[i] = -1;
        visited[i] = 0;
    }
    dist[start].w = 0;
    Push(queue, dist[start]);
    while (!Isempty(queue))
    {
        Dnode cd = Pop(queue);
        int u = cd.id;
        printf("**%d %d\n", u, cd.w);
        if(visited[u])
            continue;
        visited[u] = 1;
        ArcNode *p = list->vertex[u].firstarc;

        while(p)
        {
            int tempv;
            for(int i = 0; i < list->info.vexnum; i++){
                if(!strcmp(p->info.adjvex, list->vertex[i].data.name))
                    tempv = i;
            }
            int tempw = p->info.weight[flag];

            
            for(int i = 0; i < list->info.vexnum; i++)
                printf("%d ", dist[i].w);
            if(!visited[tempv] && dist[tempv].w > dist[u].w+tempw){
                dist[tempv].w = dist[u].w+tempw;
                path[tempv] = u;
                Push(queue, dist[tempv]);
            }
            for(int i = 0; i < list->info.vexnum; i++)
                printf("%d ", dist[i].w);
            printf("\n\n");
            p = p->nextarc;
        }
        printf("---\n");
    }
    printf("****%d\n", dist[end].w);
}

Queue *InitQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    queue_node *p = (queue_node *)malloc(sizeof(queue_node));
    p->next = NULL;
    q->front = q->rear = p;
    return q;
}

void Push(Queue *list, Dnode node)
{
    queue_node *Qnode = (queue_node *)malloc(sizeof(queue_node));
    Qnode->data = node;
    Qnode->next = NULL;
    if(Isempty(list)){
        list->rear->next = Qnode;
        list->rear = Qnode;
    } else {
        queue_node *q = list->front;
        queue_node *p = list->front->next;
        for(; p; q = p, p = p->next){
            if(p->data.w > Qnode->data.w){
                q->next = Qnode;
                Qnode->next = p;
                return ;
            }
        }
        list->rear->next = Qnode;
        list->rear = Qnode;
    }
}

Dnode Pop(Queue *list)
{
    if(!Isempty(list)){
        queue_node *p = list->front->next;
        list->front->next = p->next;
        Dnode re = p->data;
        free(p);
        if(list->front->next == NULL)
            list->rear = list->front;
        return re;
    }
}

int Isempty(Queue *list)
{
    if(list->front == list->rear)
        return 1;
    else 
        return 0;
}

void list_add(VertexNode *vnode, ArcNode *node)
{
    if(vnode->firstarc == NULL){
        vnode->firstarc = node;
        node->nextarc = NULL;
    } else {
        ArcNode *p = vnode->firstarc;
        for(; p->nextarc; p = p->nextarc){

        }
        p->nextarc = node;
        node->nextarc = NULL;
    }
}

void list_del(VertexNode *vnode, char *name)
{
    ArcNode *q = NULL;
    ArcNode *p = vnode->firstarc;
    if(p->nextarc == NULL){
        vnode->firstarc = NULL;
    } else {
        for(; p; q = p, p = p->nextarc){
            if(!strcmp(p->info.adjvex, name)){
                if(vnode->firstarc == p){
                    vnode->firstarc = p->nextarc;
                }else
                    q->nextarc = p->nextarc;
                free(p);
            }
        }
    }
}