#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/dir.h>
#include<sys/types.h>
#include"dirent.h"

#define MAX_PATH 1024

#ifndef DIRSIZ
#define DIRSIZ 14
#endif

void dirwalk(char *,void(*fcn)(char *));

void fsize(char *);

main(int argc,char *argv[]){

	if(argc == 1){
		fsize(".");
	}else
		while(--argc>0)
			fsize(*++argv);

}

void fsize(char *name){

	struct stat stbuf;
	
	if(stat(name,&stbuf)==-1){
		fprintf(stderr,"fsize: can't access %s\n",name);
		return;
	}
	if((stbuf.st_mode&S_IFMT)==S_IFDIR)
		dirwalk(name,fsize);

	printf("%5u %6o %3u %8ld %s\n",stbuf.st_ino,stbuf.st_mode,stbuf.st_nlink,stbuf.st_size,name);

}


void dirwalk(char *dir,void(*fcn)(char *)){

	char name[MAX_PATH];
	Dirent *dp;
	my_DIR *dfd;

	if((dfd = my_opendir(dir)) == NULL){
		fprintf(stderr,"dirwalk: can't open %s\n",dir);
		return;
	}

	while((dp = my_readdir(dfd))!=NULL){
		if(strcmp(dp->name,".")==0 || strcmp(dp->name,"..")==0)
			continue;
		if(strlen(dir)+strlen(dp->name)+2>sizeof(name))
			fprintf(stderr,"dirwalk: name %s/%s too long\n",dir,dp->name);
		else
			sprintf(name,"%s/%s",dir,dp->name);
			(*fcn)(name);
	}

	my_closedir(dfd);
}

my_DIR * my_opendir(char *dirname){

	int fd;
	struct stat stbuf;
	my_DIR *dp;

	if((fd=open(dirname,O_RDONLY,0))==-1 || fstat(fd,&stbuf)==-1 || (stbuf.st_mode&S_IFMT)!=S_IFDIR||(dp=(my_DIR*)malloc(sizeof(my_DIR)))==NULL)
		return NULL;
	dp->fd = fd;
	return dp;
}

void my_closedir(my_DIR *dp){
	if(dp){
		close(dp->fd);
		free(dp);
	}
}

struct my_direct{
	ino_t d_ino;
	char d_name[DIRSIZ];
};

Dirent *my_readdir(my_DIR *dp){
	struct my_direct *dirbuf;
	static Dirent d;
	int n;
	
	while((n=read(dp->fd,(char *)dirbuf,sizeof(dirbuf)))==sizeof(dirbuf)){
		if(dirbuf->d_ino == 0)
			continue;
		
		d.ino = dirbuf->d_ino;
		strncpy(d.name,dirbuf->d_name,14);
		d.name[14] = '\0';
	
		return &d;
	}
	return NULL;
}




