#include "my.h"
int main()
{
	pid_t r;
	int r_num;
	int pipefd[2];
	char buf[4096];
	memset(buf,0,sizeof(buf));
	fflush(stdin);
	if(pipe(pipefd)<0){
		perror("pipe failed.\n");
		return -1;
	}
	r=fork();
	if(r<0){
		perror("fork failed.\n");
		return -1;
	}else if(r==0){
		close(pipefd[1]);
		/*int ppid=getppid();
		wait(&ppid);*/
		sleep(5);
		if(r_num=read(pipefd[0],buf,100)>0){
			printf("child read from pipe: %s,total=%d\n",buf,r_num);
		}
		close(pipefd[0]);
		sleep(5);
		exit(0);
	}else{
		close(pipefd[0]);
		/*for(int i=0;i<=7000;i++){
		if(write(pipefd[1],"1234567890",10)!=-1){
			printf("parent write %d.\n",10*(i+1));
		}
		}*/
		int i=1;
		while(write(pipefd[1],"1",1)!=-1){
			printf("parent write %d.\n",i);
			i++;
		}
		close(pipefd[1]);
		return 0;
	}
}
