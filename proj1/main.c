#include "uhead.h"

int main(){
	int data[UNUM];
	struct arg m;
	m = op(data,UNUM);
	urand(data,UNUM);
	show(data,UNUM);
	printf("sum = %d, ave = %d",m.sum,m.ave);
	return 0;
}
