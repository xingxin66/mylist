#include "myhead.h"

void mysort(int *a,int n){
	int i=n,j;
	int temp;
	for(i=1;i<1000;i++){
	for(j=0;j<1000-i;j++){
	if(a[j]>a[j+1]){
	temp=a[j+1];
	a[j+1]=a[j];
	a[j]=temp;
}
}
}
}

int compar(const void *a,const void *b){
	int *aa=(int *)a,*bb=(int *)b;
	if(*aa>*bb)return 1;
	if(*aa==*bb)return 0;
	if(*aa<*bb) return -1;
}
