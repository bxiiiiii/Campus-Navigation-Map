#include <stdio.h>
#include <stdlib.h>
#include "UI.h"
#include "Operations.h"
 
int main(int argc, char *argv[]) {
    AdjList list;
    if(CreatGraph(&list) == 1)
        InitGraph(&list);
    UI(&list);
    SaveGraph(&list);
    return 0;
}