#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
  pid_t p;
  if(p<0){
    perror("failed to fork");
    exit(1);
  } else if ( p == 0){
    printf("Hello from Child!\n");
  }else{
    printf("%d about to create %d child processes", getpid(), 2);
    p = fork();
  }
}
