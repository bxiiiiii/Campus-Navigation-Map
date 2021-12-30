#include "UI.h"

void UI(AdjList *list)
{
    int choice;
    while(1) {
	system("clear");
        printf("[1]管理员\n");
        printf("[2]用户\n");
        printf("请选择登录身份:");
        scanf("%d", &choice);
        if(choice == 1) {
            if(!Login(list))
                admini_UI(list);
            else {
                printf("密码错误,请重新输入\n");
                continue;
            }
            break;
        } else if(choice = 2) {
            user_UI(list);
            break;
        } else
            printf("输入有误,请重新输入\n");
    }
}
 
void admini_UI(AdjList *list)
{
    int choice;
    while(1) {
       system("clear");
        printf("\n\n\n\n\t\t\t[1]新建地点\n");
        printf("\t\t\t[2]修改地点\n");
        printf("\t\t\t[3]删除地点\n");
        printf("\t\t\t[4]新建路径\n");
        printf("\t\t\t[5]修改路径\n");
        printf("\t\t\t[6]删除路径\n");
        printf("\t\t\t[7]修改密码\n");
        printf("\t\t\t[8]保存修改\n");
        printf("\t\t\t[9]退出\n");
        printf("\t\t\t[10]查看地点\n");
        printf("\t\t\t[11]查看地图\n");
        printf("\t      请输入选择:");
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
                ChangePass(list);
                break;
            case 8:
                SaveGraph(list);
                break;
            case 9:
                return ;
            case 10:
                PrintNode(list);
                break;
            case 11:
                PrintPath(list);
                break;
            default:
                printf("输入有误，请重新输入\n");
        }
    
        fflush(stdin);
        //getchar();
        char tem[30];
        printf("请输入任意键继续:");
        scanf("%s", tem);}
}
 
void user_UI(AdjList *list)
{
    int choice;
    while(1) {
        system("clear");
        printf("\n\n\n\n\n\t\t\t[1]查看地图\n");
        printf("\t\t\t[2]查看景点\n");
        printf("\t\t\t[3]查询最短路径\n");
        printf("\t\t\t[4]查询优美路径\n");
        printf("\t\t\t[5]查询绿荫路径\n");
        printf("\t\t\t[6]退出\n\n");
        printf("\t      请输入选择:");
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
        fflush(stdin);
        //getchar();
        char tem[30];
        printf("输入任意内容继续:");
        scanf("%s", tem);
    }
}
