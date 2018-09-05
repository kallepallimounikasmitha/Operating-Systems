/*
 * 3.c
 * 
 * Copyright 2018 Saranya <saranya@saranya>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <sys/ipc.h> 
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define READ 0
#define WRITE 1
//char* phrase = "saranya";
int main(int argc, char **argv)
{
	int pdf[2], bytesread;
	int m[100];
	int n[100];
	int status,sum=0;
	pipe(pdf);
	int j;
	int i=fork();
		if(i==0)
		{
			close(pdf[READ]);
			int x;
			for(j=0;x!=0;j++)
				x=scanf("%d",&n[j]);
			n[j-1]=-1;
			write(pdf[WRITE],n,100*sizeof(int));
			close(pdf[WRITE]);
		}
		else
		{
			wait(&status);
			close(pdf[WRITE]);
			bytesread = read(pdf[READ],m,100*sizeof(int));
			for(j=0;m[j]!=-1;j++)
			{
				sum=sum+m[j];
				printf("%d\n",m[j]);
			}
			printf("Sum is %d",sum);
			close(pdf[READ]);
		}
	return 0;
}

