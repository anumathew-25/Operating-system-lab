#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(void){
    char *path,path1[10];
    struct stat *nfile;
    nfile=(struct stat*)malloc(sizeof(struct stat));
    printf("enter name of file whose statics has to ");
    scanf("%s",path1);
    stat(path1,nfile);
    printf("user id %d\n",nfile->st_uid);
    printf("block size :%ld\n",nfile->st_size);
    printf("last access time %ld\n",nfile->st_atime);
    printf("time of last modification %ld\n",nfile->st_atime);
    printf("production mode %d\n",nfile->st_mode);
    printf("size of file %ld\n",nfile->st_size);
    printf("number of links:%ld\n",nfile->st_nlink);


}