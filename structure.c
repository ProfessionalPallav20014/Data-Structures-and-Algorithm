#include <stdio.h>
#include <string.h>

struct train {
    char trname[50];  
    int trid;
    char status[20];  
};

int main() {
    struct train tr;
    strcpy(tr.trname, "ABC Express");
    strcpy(tr.status, "Running");
    tr.trid = 1235;

    printf("The status of the train is %s\n", tr.status);
    printf("The ID of the train is %d\n", tr.trid);
    printf("The name of the train is %s\n", tr.trname);

    return 0;
}