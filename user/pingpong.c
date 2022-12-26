#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#define RD 0
#define WR 1
int main(int argc, char *argv[]){
    int p1[2],p2[2];
    pipe(p1),pipe(p2);
    char buf[5];
    int size;
    int pid = fork();
    if(pid == 0){
      //read from parent
      close(p1[WR]);
      if((size = read(p1[0],buf,sizeof(buf)))>0){
        printf("%d: received ",getpid());
        write(1,buf,size);
      }else{
        printf("%d:receive failed\n",getpid());

      }
      //write to parent
      close(p2[RD]);
      write(p2[WR],"pong\n",5);
      exit(0);
    }else if( pid > 0){
      //write to child
        close(p1[RD]);
        write(p1[1],"ping\n",5);
        wait(0);
      //read from child
      close(p2[WR]);
      if((size = read(p2[RD],buf,sizeof(buf)))>0){
        printf("%d: reveived ",getpid());
        write(1,buf,size);
      }else{
        printf("%d:reveive failed\n",getpid());
      }
    }else{
      printf("fork error\n");
    }
    exit(0);
}