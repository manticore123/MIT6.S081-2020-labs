#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
int main(int argc, char *argv[]){
    int time = atoi(argv[1]);
    // printf("%d %d",time,argc);
    if(argc != 2){
        printf("wrong usage: argc should be only one");
        exit(1);

    }else{
        sleep(time);
        exit(0);
    }

}