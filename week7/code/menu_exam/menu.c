#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void newfile(){
	FILE *fp;
	char name;
	printf("please input file name:");
	scanf("%s",&name);
	fp=fopen(&name,"w+");
	if(fp==NULL){
		perror("open file:fail or file exist!");	
	}else{	printf("new file successed\n");}
	fclose(fp);
}

void writefile(){
	FILE *fp;
	char name;
	char thing[100];
	printf("please input file name:");
	scanf("%s",&name);
	fp=fopen(&name,"wt+");
	printf("please input:\n");
	getchar();
	fgets(thing,99,stdin);
	fputs(thing,fp);
	if(fp==NULL){
		perror("write file failed\n");
	}else{
		printf("writed file successed\n");
	}
	fclose(fp);
}

void readfile(){
	FILE *fp;
	char buffer[20];
	char name;
	printf("please input file name:\n");
	scanf("%s",&name);
	fp=fopen(&name,"r");
	if(fp==NULL){
		perror("read file failed or file is not exist.\n");
	}else{
		while(fgetc(fp)!=EOF){
			fseek(fp,0,SEEK_SET);
			fgets(buffer,20,fp);
			printf("%s",buffer);
		}
	}
	fclose(fp);
}

void modify(){
	FILE *fp;
	char name;
	int a;
	printf("please input file name:\n");
	scanf("%s",&name);
	printf("**************\n");
	printf("0.exit\n");
	printf("1.write only\n");
	printf("2.read only\n");
	printf("3.write and read\n");
	printf("**************\n");
	printf("modify permission,please choose:\n");
	scanf("%d",&a);
	switch(a){
	case 0:
		exit(0);	
	case 1:
		chmod(&name,S_IWUSR);
		break;
	case 2:
		chmod(&name,S_IRUSR);
		break;
	case 3:
		chmod(&name,S_IWUSR|S_IRUSR);
		break;
	default:
		printf("Please input angin(0-3):");
}
	
}

void fuction(){
	int a;
	scanf("%d",&a);
	switch (a){
	case 0:
		exit(0);
	case 1:
		newfile();
		break;
	case 2:
		writefile();
		break;
	case 3:
		readfile();
		break;
	case 4:
		modify();
		break;
	case 5:
		break;
	default:
		printf("Please input angin(0-5):");
}
}

void menu(){
	printf("************************************\n");
	printf("	0.exit;\n");
	printf("	1.new file;\n");
	printf("	2.write file;\n");
	printf("	3.read file;\n");
	printf("	4.modify permission;\n");
	printf("	5.look or modify permission;\n");
	printf("************************************\n");
	printf("Please input your choice(0-5):");
	fuction();
}
