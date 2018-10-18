#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>


void sigint_hand(int sig){
char message[] = "caught sigint\n";
write(1,message, sizeof(message));

char prmpt[] = "CS361 >";
write(1, prmpt, sizeof(prmpt));
}

void sigstp_hand(int sig){

char message[] = "caught sigint\n";
write(1,message, sizeof(message));

char prmpt[] = "CS361 >";
write(1, prmpt, sizeof(prmpt));

}

int main()
{
signal(SIGINT, sigint_hand);
signal(SIGTSTP, sigstp_hand);

char line[500];
char argsarray[20][100];
 while(1){
   printf("CS361 >:");
   fgets(line,500, stdin); 
//exit commnand
  if(strcmp(argsarray[0],"exit") == 0)
    return 0;
}
char* word = strtok(line," ");
int k = 0; 

while(word){
pintf("word: %s\n", word);
strcpy(argsarray[k], word);

word = strtok(NULL, " ");
k = k++;

}
int pid = fork();
if(pid == 0)
{
printf("Pid: %d\n", getpid());
//fd1 = execv(argsarray[0], argsarray);
}
else{
int status;
wait(&status);

printf("pid: %d status: %d \n", pid, WEXITSTATUS(status));
printf("Exit\n");
}

}
