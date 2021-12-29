#include "UI.h"

void UI(AdjList *list)
{
    int choice;
    while(1) {
        printf("[1]管理员\n");
        printf("[2]用户\n");
        printf("请选择登录身份:");
        scanf("%d", &choice);
        if(choice == 1) {
            admini_UI(list);
            break;
        } else if(choice = 2) {
            user_UI(list);
            break;
        } else
            printf("输入有误，请重新输入\n");
    }
}
 
void admini_UI(AdjList *list)
{
    int choice;
    while(1) {
        printf("[1]insert node\n");
        printf("[2]modify node\n");
        printf("[3]delete node\n");
        printf("[4]insert path\n");
        printf("[5]modify path\n");
        printf("[6]delete path\n");
        printf("[7]save change\n");
        printf("[8]exit\n");
        printf("//[9]show node\n");
        printf("//[10]show path\n");
        printf("请输入选择:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                InsertVertex(list);
                break;
            case 2:
                ModifyVertex(list);
                break;
            case 3:
                DeleteVertex(list);
                break;
            case 4:
                InsertEdge(list);
                break;
            case 5:
                ModifyEdge(list);
                break;
            case 6:
                DeleteEdge(list);
                break;
            case 7:
                SaveGraph(list);
                break;
            case 8:
                return ;
            case 9:
                PrintNode(list);
                break;
            case 10:
                PrintPath(list);
                break;
            default:
                printf("输入有误，请重新输入\n");
        }
    }
}
 
void user_UI(AdjList *list)
{
    int choice;
    while(1) {
        printf("[1]查看地图\n");
        printf("[2]查看景点\n");
        printf("[3]最优路径查询\n");
        printf("[4]find1");
        printf("[5]find2\n");
        printf("[6]return");
        printf("请输入选择:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                PrintPath(list);
                break;
            case 2:
                PrintNode(list);
                break;
            case 3:
                Dijkstra(list, 0);
                break;
            case 4:
                Dijkstra(list, 1);
                break;
            case 5:
                Dijkstra(list, 2);
            case 6:
                return ;
            default:
                printf("输入有误，请重新输入\n");
        }
    }
}
