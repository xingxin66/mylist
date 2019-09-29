#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

#define UNUM 1000

struct arg{
	int sum;
	float ave;
};

int compar(const void *a,const void *b);
void show(int *,int);
void urand(int *,int);
void mysort(int *,int);
struct arg op(int *,int);
