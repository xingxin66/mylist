#include "uhead.h"

struct arg op(int *a,int n){
	struct arg mynum;
	mynum.sum = 0;
	mynum.ave = 0.0;
	int i;
	for(i=0;i<n;i++){
	mynum.sum=a[i]+mynum.sum;
}
	mynum.ave=mysum/n;
	return mynum;
};
