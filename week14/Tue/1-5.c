#include "my.h"

#define SIZE 10

int a[SIZE],b[SIZE];

void max_fun(int *arg){
	int *ap=arg;
	int rv,i,k=0;
	for(i=1;i<SIZE;i++){
		if(ap[i]>ap[k])
		{
			k=i;
		}
	}
	pthread_exit((void *)&ap[k]);
}

void check_error(int num,char *error){
	if(num!=0){
		printf("%s",error);
		return -1;
	}
}

int main(void){
	pthread_t tid1,tid2;
	int i,rv,**ptr1,**ptr2;
	int *c=(int *)malloc(100*sizeof(int));
	int *d=(int *)malloc(100*sizeof(int));
	for(i=0;i<100;i++){
		c[i]=rand();
		d[i]=rand();
	}
	
	
	rv=pthread_create(&tid1,NULL,(void*(*)())max_fun,c);
	if(rv!=0){
			printf("thread create failed!\n");
			return -1;		
	}
	rv=pthread_create(&tid2,NULL,(void*(*)())max_fun,d);
	if(rv!=0){
			printf("thread create failed!\n");
			return -1;		
	}
	
	pthread_join(tid1,(void**)&ptr1);
	pthread_join(tid2,(void**)&ptr2);
	printf("thread1's max value is: %d\n",*ptr1);
	printf("thread2's max value is: %d\n",*ptr2);
	printf("max value = %d\n",((*ptr1)>(*ptr2)?(*ptr1):(*ptr2)));
	exit(0);
}
