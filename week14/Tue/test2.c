#include "my.h"

void fun(){
	printf("tid=%p\n",pthread_self());
}

int main(){
	pthread_t tid,tid1;
	int ret;
	ret=pthread_create(&tid,NULL,(void*(*)())fun,NULL);
	pthread_join(tid,NULL);
	ret=pthread_create(&tid1,NULL,(void*(*)())fun,NULL);
	pthread_join(tid1,NULL);
	return 0;
}
