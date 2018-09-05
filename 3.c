#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/shm.h>
int main(int argc,char** argv)
{ 
	int shmid;
	int *a,*b;
	
	shmid=shmget(IPC_PRIVATE,50*sizeof(int),0777|IPC_CREAT);
	pid_t pid;
	pid=fork();
	int arr[50];
	if(pid==0)
	{
		
		printf("Enter the numbers\n");
		int t=scanf("%d",&arr[0]);
		int i=1;
		while(t==1)
		{
			t=scanf("%d",&arr[i]);
			//printf("%d",arr[i]);
			if(t==1)
			{
				i++;
			}
		}
		printf("wait : calculating sum \n");
		b = (int *)shmat(shmid, 0, 0);
		int k=0;
		for(k=0;k<=i;k++)
		{
			b[k]=arr[k];

		}
		
		b[i]=-1000;
		shmdt(b);
		sleep(2);
		b = (int *)shmat(shmid, 0, 0);

		shmdt(b);
		
		
			
	}else
	{
		waitpid(0,&pid,0);
		a=(int *)shmat(shmid,0,0);
		int j=0;
		int sum=0;
		printf("parent process");
		while(a[j]!=-1000)
		{

			sum=sum+a[j];

			j++;
		}
		a[j+1]=sum;
		printf("%d",sum);
		shmdt(a);
	}
}
		
