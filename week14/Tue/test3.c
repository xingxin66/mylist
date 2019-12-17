#include "my.h"
int i=0;

void fun(){
	i++;
	printf("tid=%p,i=%d\n",pthread_self(),i);
	//return 0;
}

int main(){
	pthread_t tid,tid1;
	int ret[4],i;
	for(int i=0;i<4;i++){
		ret[i]=pthread_create(&tid,NULL,(void*(*)())fun,NULL);
		if(ret[i]!=0){
			perror("failed!\n");
			return -1;
		}
	}
	for(int i=0;i<4;i++){
		pthread_detach(tid);	
	}
	//sleep(2);
	printf("Master done!\n");
	return 0;
}
