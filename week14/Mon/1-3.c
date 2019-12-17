#include "my.h"
#define NUM_THREADS 4

struct info{
	int no;
	int n;
};

void sum(void *t){
	pthread_t my_tid;
	struct info *y;
	int sum=0;
	y=(struct info *)(t);
	for(int i=0;i<=y->n;i++){
		sum+=i;
	}
	my_tid = pthread_self();
	printf("\tThread %d:my tid is %lx\n",(int)y->no,my_tid);
	printf("\tsum 1 to %d = %d\n",y->n,sum);
}

int main(){
	pthread_t tid;
	struct info a[4];
	int rv,t;
	for(t= 0 ;t<NUM_THREADS;t++){
		a[t].no=t;
		a[t].n=100*(t+1);
		rv=pthread_create(&tid,NULL,(void*(*)())sum,(void*)&a[t]);
		if(rv!=0){
			printf("thread create failed!\n");
			return -1;		
		}
		printf("Create thread %lx\n",tid);
		
	}
	printf("Good bye!\n");
	pthread_exit(NULL);
}
