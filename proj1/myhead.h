#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UNUM 100

struct arg{
	int sum;
	float ave;
};

void show(int *,int);
int urand(int *,int);
struct arg op(int *,int);
