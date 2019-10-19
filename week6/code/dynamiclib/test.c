#include "mylib.h"

int main(){
	int num[10];
	int n=10;
	init(num,n);
	show(num,n);
	printf("max = %d\n",max(num,n));
	printf("sum = %d\n",sum(num,n));
	return 0;
}
