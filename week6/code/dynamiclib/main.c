#include <dlfcn.h>
#include <stdio.h>
#include "mylib.h"

int main(){
	void (*pTest)();
	void *pdlHandle = 	dlopen("libdynamic.so",RTLD_LAZY);
	if(pdlHandle == NULL){
	printf("failed load library\n");
	return -1;
}
	char* pszErr = dlerror();
	if(pszErr!=NULL){
	printf("%s\n",pszErr);
	return -1;
}
	pTest = dlsym(pdlHandle,"dynamic");
	pszErr = dlerror();
	if(pszErr!=NULL){
	printf("%s\n",pszErr);
	dlclose(pdlHandle);
	return -1;
}
	(*pTest)();
	dlclose(pdlHandle);
	return 0;
}
