#include "Operations.h"
 
void PrintNode(AdjList *list)
{
    system("clear");
    if(list->info.vexnum == 0){
        printf("暂无记录\n");
        return ;
    }
    int ice = 0;
    int choice, x, y;
    char name[30], info[100];
    printf("\n\n\n\t\t\t[1]全部\n");
    printf("\t\t\t[2]地点\n");
    printf("\t\t\t[3]相关信息\n");
    printf("\t\t\t[4]坐标\n");
    printf("\t\t\t[5]返回\n");
    printf("\t\t输入查询选项:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        for(int i = 0; i < MAX_V; i++){
            if(!strcmp(list->vertex[i].data.name, "0"))
                continue;
            printf("地点 : %s\n", list->vertex[i].data.name);
            printf("相关信息 : %s\n", list->vertex[i].data.info);
            printf("坐标 : x-%d y-%d\n", list->vertex[i].data.x, list->vertex[i].data.y);
            printf("--------------------------------------------------------------------\n");
        }
        break;
    case 2:
        printf("请输入地点的名称:");
        scanf("%s", name);
        for(int i = 0; i < MAX_V; i++) {
            if(!strcmp(name, list->vertex[i].data.name)) {
                printf("名称:%s\n", name);
                printf("信息:%s\n", list->vertex[i].data.info);
                printf("坐标:x-%d y-%d\n", list->vertex[i].data.x, list->vertex[i].data.y);
                ice = 1;
                break;
            }
        }
        if(!ice)
            printf("暂无记录\n");
        break;
    case 3:
        printf("请输入有关信息:");
        scanf("%s", info);
        for(int i = 0; i < MAX_V; i++) {
            if(!strcmp(info, list->vertex[i].data.info)) {
                printf("名称:%s\n", list->vertex[i].data.name);
                printf("信息:%s\n", list->vertex[i].data.info);
                printf("坐标:x-%d y-%d\n", list->vertex[i].data.x, list->vertex[i].data.y);
                printf("---------------------------------------------------------------\n");
                ice = 1;
            }
        }
        if(!ice)
            printf("暂无记录\n");
        break;
    case 4:
        printf("请输入地点的坐标（x y）:");
        scanf("%d %d", &x, &y);
        for(int i = 0; i < MAX_V; i++) {
            if(list->vertex[i].data.x == x && list->vertex[i].data.y == y) {
                printf("名称:%s\n", list->vertex[i].data.name);
                printf("信息:%s\n", list->vertex[i].data.info);
                printf("坐标:x-%d y-%d\n", list->vertex[i].data.x, list->vertex[i].data.y);
                printf("---------------------------------------------------------------\n");
                ice = 1;
                break;
            }
        }
        if(!ice)
            printf("暂无记录\n");
        break;
    case 5:
        return ;
    default:
        printf("请输入正确选项！\n");
        break;
    }

}

void PrintPath(AdjList *list)
{
    system("clear");
    if(list->info.arcnum == 0){
        printf("暂无记录\n");
        return ;
    }
    for(int i = 0; i < MAX_V; i++){
        if(!strcmp(list->vertex[i].data.name, "0"))
            continue;
        for(ArcNode *p = list->vertex[i].firstarc; p; p = p->nextarc){
            printf("起点 : %s\n", p->info.vex);
            printf("终点 : %s\n", p->info.adjvex);
            printf("相关信息 : %s\n", p->info.info);
	    printf("路径长度 : %d\n", p->info.weight[0]);
	    printf("优美指数 : %d\n", p->info.weight[1]);
	    printf("绿荫指数 : %d\n", p->info.weight[2]);
	    printf("----------------------------------------------------------------\n");
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

int Login(AdjList *list)
{
    struct termios oldt,newt;
	tcgetattr(0,&oldt);
	newt = oldt;
	newt.c_lflag &= ~(ECHO|ICANON);
	char ch;
	int i= 0;
	char password_buf1[20];
    printf("请输入密码:");
    while(1){
        setbuf(stdin, NULL);
        tcsetattr(0,TCSANOW,&newt);
        scanf("%c",&ch);
        tcsetattr(0,TCSANOW,&oldt);
        if(i == 20 || ch == '\n')
            break;
        password_buf1[i] = ch;
        printf("*");
        i++;
    }
    if(!strcmp(password_buf1, list->info.password))
        return 0;
    else 
        return 1;
}

int ChangePass(AdjList *list)
{
    struct termios oldt,newt;
	tcgetattr(0,&oldt);
	newt = oldt;
	newt.c_lflag &= ~(ECHO|ICANON);
	char ch;
	int i= 0;
	char password_buf1[20];
	char password_buf2[20];
    do{
        printf("\t\t\t请输入密码:");
        i = 0;
        while(1){
            setbuf(stdin, NULL);
            tcsetattr(0,TCSANOW,&newt);
            scanf("%c",&ch);
            tcsetattr(0,TCSANOW,&oldt);
            if(i == 20 || ch == '\n')
                break;
            password_buf1[i] = ch;
            printf("*");
            i++;
        }

        printf("\n\t\t\t请再次输入密码:");
        i = 0;
        while(1){
            setbuf(stdin, NULL);
            tcsetattr(0,TCSANOW,&newt);
            scanf("%c",&ch);
            tcsetattr(0,TCSANOW,&oldt);
            if(i == 20 || ch == '\n')
                break;
            password_buf2[i] = ch;
            printf("*");
            i++;
        }
        if(!strcmp(password_buf1, password_buf2)){
            strcpy(list->info.password, password_buf2);
            printf("successful.\n");
            break;
        } else {
            printf("again.\n");
        }
    }while(1);
}
 
int SearchVertex(AdjList *list, char *name)
{
    for(int i = 0; i < MAX_V; i++) {
        if(!strcmp(name, list->vertex[i].data.name)) {
            printf("名称:%s\n", name);
            printf("信息:%s\n", list->vertex[i].data.info);
            printf("坐标:x-%d y-%d\n", list->vertex[i].data.x, list->vertex[i].data.y);
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
    printf("请输入新地点的名称:");
    scanf("%s", node->data.name);
    printf("请输入新地点的有关信息:");
    scanf("%s", node->data.info);
    printf("请输入新地点的坐标（x y）:");
    scanf("%d %d", &node->data.x, &node->data.y);
    for(int i = 0; i < MAX_V; i++){
        if(!strcmp(list->vertex[i].data.name, "0")){
            list->vertex[i] = *node;
            break;
        }   
    } 
    list->info.vexnum++;

    printf("插入成功.\n");
    return 0;
}
 
int ModifyVertex(AdjList *list)
{
    int choice;
    char info[100];
    char name[30], newname[30];
    VertexNode *node = NULL;

    system("clear");
    printf("请输入待修改地点的名称:");
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
        printf("[1]名称\n");
        printf("[2]相关信息\n");
        printf("[3]横坐标\n");
        printf("[4]纵坐标\n");
        printf("[5]返回\n");
        printf("请输入待修改的内容:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("请输入新名称:");
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
            printf("请输入新相关信息:");
            scanf("%s", info);
            strcpy(node->data.info, info);
            break;
        case 3:
            printf("请输入新横坐标:");
            scanf("%d", &node->data.x);
            break;
        case 4:
            printf("请输入新纵坐标:");
            scanf("%d", &node->data.y);
            break;
        case 5:
            return 0;
        default:
            printf("请输入正确选项！\n");
        }
    }

    printf("修改成功\n");
    return 0;
}
 
int DeleteVertex(AdjList *list)
{
    int confirm;
    int edge_num = 0;
    char name[30];

    system("clear");
    printf("请输入待删除的地点名称:");
    scanf("%s", name);
    if(SearchVertex(list, name)){
        printf("not found.\n");
        return 1;
    }

    while(1) {
        printf("请确认你的选择(0-no, 1-yes):");
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
            printf("删除成功\n");
            return 0;
        }else if(confirm == 0){
            return 0;
        } else 
            printf("请输入正确选项！\n");
    }
}
 
int InsertEdge(AdjList *list)
{
    int tem;
    char sta[30], des[30], info[100];

    system("clear");
    printf("请输入起始地点:");
    scanf("%s", sta);
    if(SearchVertex(list, sta)){
        printf("not found.\n");
        return 1;
    }

    printf("请输入终止地点:");
    scanf("%s", des);
    if(SearchVertex(list, des)){
        printf("not found.\n");
        return 1;
    }

    ArcNode *node = (ArcNode *) malloc (sizeof(ArcNode));
    strcpy(node->info.vex, sta);
    strcpy(node->info.adjvex, des);
    printf("请输入相关信息:");
    scanf("%s", info);
    strcpy(node->info.info, info);
//   weight initialization
    printf("请输入路径长度:");
    scanf("%d", &node->info.weight[0]);
    printf("请输入优美指数:");    
    scanf("%d", &tem);
    node->info.weight[1] = MAX_G - tem;
    printf("请输入绿荫指数:");
    scanf("%d", &tem);
    node->info.weight[2] = MAX_G - tem;
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
    node2->info.weight[1] = node->info.weight[1];
    node2->info.weight[2] = node->info.weight[2];
    for(int i = 0; i < MAX_V; i++)
        if(!strcmp(des, list->vertex[i].data.name)){
            list_add(&list->vertex[i], node2);
            break;
        }

    list->info.arcnum++;
    printf("新建路径成功\n");
    return 0;
}
 
int ModifyEdge(AdjList *list)
{
    int choice;
    int weight;
    ArcNode *p = NULL, *q = NULL;
    char sta[30], des[30], info[100];

    system("clear");
    printf("请输入起始地点:");
    scanf("%s", sta);
    if(SearchVertex(list, sta)){
        printf("not found.\n");
        return 1;
    }

    printf("请输入终止地点:");
    scanf("%s", des);
    if(SearchVertex(list, des)){
        printf("not found.\n");
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
        printf("该路径不存在\n");
        return -1;
    }

    while(1) {
        printf("[1]相关信息\n");
        printf("[2]路径长度\n");
        printf("[3]优美指数\n");
        printf("[4]绿荫指数\n");
        //printf("[5]weight4\n");
        printf("[6]返回\n");
        printf("请输入待修改的内容:");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                //memset(p->info.info, 0, sizeof(p->info.info));
                //memset(q->info.info, 0, sizeof(q->info.info));
                printf("请输入新的相关信息:\n");
                scanf("%s", info);
                strcpy(p->info.info, info);
                strcpy(q->info.info, info);
                break;
            case 2:
                printf("请输入新的路径长度:\n");
                scanf("%d", &weight);
                p->info.weight[0] = weight;
                q->info.weight[0] = weight;
                break;
            case 3:
                printf("请输入新的优美指数:\n");
                scanf("%d", &weight);
                p->info.weight[1] = MAX_G - weight;
                q->info.weight[1] = MAX_G - weight;
                break;
            case 4:
                printf("请输入新的绿荫指数:\n");
                scanf("%d", &weight);
                p->info.weight[2] = MAX_G - weight;
                q->info.weight[2] = MAX_G - weight;
                break;
            // case 5:
            //     printf("enter weight4 plz.\n");
            //     scanf("%d", &weight);
            //     p->info.weight[3] = weight;
            //     break;
            case 6:
                return 0;
            default:
                printf("请输入正确内容！\n");
        }
    }

    printf("修改成功\n");
    return 0;
}
 
int DeleteEdge(AdjList *list)
{
    char sta[30], des[30];
    system("clear");
    printf("请输入起始地点:");
    scanf("%s", sta);
    if(SearchVertex(list, sta)){
        printf("not found.\n");
        return 1;
    }

    printf("请输入终止地点:");
    scanf("%s", des);
    if(SearchVertex(list, des)){
        printf("not found.\n");
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
    printf("删除成功\n");
    return 0;
}
 
int Dijkstra(AdjList *list, int flag)
{
    system("clear");
    char sta[30], des[30];
    int start, end;
    Path path_[MAX_V];
    int visited[MAX_V] = {0};
    Dnode dist[MAX_V];
    Queue *queue = InitQueue();

    printf("请输入起始地点:");
    scanf("%s", sta);
    if(SearchVertex(list, sta)){
        printf("not found.\n");
        return 1;
    }
    printf("请输入终止地点:");
    scanf("%s", des);
    if(SearchVertex(list, des)){
        printf("not found.\n");
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
    for(int i = 0; i < list->info.vexnum; i++){
        dist[i].id = i;
        dist[i].w = 30000;
        path_[i].index = 0;
        path_[i].path[path_[i].index] = start;
        visited[i] = 0;
    }
    dist[start].w = 0;
    Push(queue, dist[start]);
    while (!Isempty(queue))
    {
        Dnode cd = Pop(queue);
        int u = cd.id;
        // printf("**%d %d\n", u, cd.w);
        // for(int i = 0; i < path_[u].index; i++)
        //     printf("%d ", path_[u].path[i]);
        // printf("\n");
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

            
            // for(int i = 0; i < list->info.vexnum; i++)
            //     printf("%d ", dist[i].w);
            if(!visited[tempv] && dist[tempv].w > dist[u].w+tempw){
                dist[tempv].w = dist[u].w+tempw;
                // printf("++%d %d %d\n", tempv, path_[tempv].index, u);
                for(int i = 0; i <= path_[u].index; i++)
                    path_[tempv].path[i] = path_[u].path[i];
                path_[tempv].index = path_[u].index;
                path_[tempv].path[++path_[tempv].index] = tempv;
                Push(queue, dist[tempv]);
            }
            // for(int i = 0; i < list->info.vexnum; i++)
            //     printf("%d ", dist[i].w);
            // printf("\n\n");
            p = p->nextarc;
        }
        // printf("---\n");
    }
    printf("\t\t起始地点:%s\n", sta);
    printf("\t\t    途径:\n");
    // for(int i = 0; i < list->info.vexnum; i++){
        for(int j = 1; j < path_[end].index; j++)
            printf("\t\t\t %s\n", list->vertex[path_[end].path[j]].data.name);
        printf("\t\t终止地点:%s\n", des);
    // }
    if(dist[end].w != 30000)
        printf("\t\t路径总长: %d\n", dist[end].w);
    else
        printf("not exit.\n");
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
