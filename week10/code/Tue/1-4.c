#include "my.h"

static void callback1(){
	printf("---------------callback1-----------------\n");
}

static void callback2(){
	printf("---------------callback2-----------------\n");
}

static void __attribute__ ((constructor)) before_main(){ //构造函数
	printf("-------------constructor-----------------\n");
}
	
static void __attribute__ ((destructor)) after_main(){ //析构函数	
	printf("-------------desstructor-----------------\n");
}

int main(){
	atexit(callback1);
	atexit(callback2);
	FILE *fp;
	char buf[]={"test data!"};
	if((fp=fopen("test.dat","w+"))==NULL){
		perror("fopen failed!\n");
		return -1;
	}
	if((fputs(buf,fp))==EOF){
		perror("fputs failed!\n");
	}
	printf("printf:data from line buffer\n");
	//exit(0);
	//_exit(0);
	return 0;
}
