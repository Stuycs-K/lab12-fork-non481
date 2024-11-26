#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int get_rand_num() {
  int file = open("/dev/random", O_RDONLY);
  if (file == -1) {
      perror("Failed to open /dev/random");
      exit(EXIT_FAILURE);
  }
  int random_num;
  read(file, &random_num, sizeof(random_num));
  close(file);
  return abs(random_num % 5) + 1;
}

void child() {
  int death_time = get_rand_num();
  printf("Child [%d] %d seconds \n", getpid(), death_time);
  sleep(death_time);
  printf("Child [%d] finished after %d seconds\n", getpid(), death_time);
  exit(death_time);
}
int main() {
  pid_t child1, child2, parent;
  parent  = getpid();
  printf("%d about to create %d child processes\n", getpid(), 2);
  child1 = fork();
  if(child1 == 0){
    child();
  }
  child2 = fork();
  if(child2 == 0) {
    child();
  }
  int status;
  pid_t child_pid = wait(&status);
  int sleep_time = WEXITSTATUS(status);
  printf("Main Process %d is done. Child %d slept for %d sec\n", parent, child_pid, sleep_time);
}
