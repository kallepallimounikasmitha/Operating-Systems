#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void upper_string(char []);

int main(int argc, char **argv)
{
    int shmid, status; 
    char *a, *b; 
    
  //  int i; 
    shmid = shmget(IPC_PRIVATE, 2*sizeof(int), 0777|IPC_CREAT); 
    
    if (fork() == 0) 
    {
		 b = (char *) shmat(shmid, 0, 0); 
         scanf("%s",b);
         shmdt(b);              
    } 
    else
    {
		int x = wait(&status);
		a = (char *) shmat(shmid, 0, 0);
		upper_string(a);
		printf("%s",a);
        shmdt(a);         
     } 	     
	return 0;
}

void upper_string(char s[]) {
   int c = 0;
 
   while (s[c] != '\0') {
      if (s[c] >= 'a' && s[c] <= 'z') {
         s[c] = s[c] - 32;
      }
      c++;
   }
}


