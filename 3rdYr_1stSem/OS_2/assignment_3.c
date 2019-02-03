#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/wait.h>
int main()
{
	char semaphoreName[] = "semaphore";
	sem_t* namedSemaphore;
	if((namedSemaphore=sem_open(semaphoreName, O_CREAT, 0644, 0)) == SEM_FAILED)
	{
		perror("Semaphore Creation Failed");
		exit(1);
	}
	pid_t pid_x,pid_y;
	int i;
	pid_x=fork();
	if(pid_x<0)
	{
		perror("Forking error for X\n");
		exit(1);
	}
	else if(pid_x==0)
	{
		for(i=0; i<10; i++)
		{
			printf("X %d\n",i);
			sleep(0);
		}
		sem_post(namedSemaphore);
		exit(0);
	}
	else
	{
		pid_y=fork();
		if(pid_y<0)
       		{
                	perror("Forking error for Y\n");
			exit(1);
        	}
        	else if(pid_y==0)
        	{
			sem_wait(namedSemaphore);
                	for(i=0; i<10; i++)
                	{
                        	printf("Y %d\n",i);
                        	sleep(1);
                	}
			sem_close(namedSemaphore);
			sem_unlink(semaphoreName);
                	exit(0);
        	}
		else
		{
			wait(NULL);
		}
		wait(NULL);
	}
	return 0;
}
