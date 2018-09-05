#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define READ 0
#define WRITE 1
void upper_string(char s[]);
char* phrase = "saranya";

 
int main(int argc, char **argv)
{
	int pdf[2], bytesread;
	char* mess[100];
	
	pipe(pdf);
	int i=fork();
	if(i==0)
	{
		close(pdf[READ]);
		write(pdf[WRITE],phrase,strlen(phrase)+1);
		close(pdf[WRITE]);
	}
	else
	{
		close(pdf[WRITE]);
		bytesread = read(pdf[READ],mess,100);
		upper_string(mess);
		printf("Read %d bytes : \n%s \n",bytesread,mess);
		close(pdf[READ]);
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

