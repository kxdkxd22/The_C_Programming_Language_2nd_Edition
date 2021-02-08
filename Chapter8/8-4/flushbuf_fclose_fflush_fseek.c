#include<stdio.h>
#include<sys/file.h>
#include<stdlib.h>

#define OPEN_MAX 20
#define PERMS 0666

typedef struct _iobuf{
	int cnt;
	char *ptr;
	char *base;
	int flag;
	int fd;

}my_FILE;


enum _flags{
        _READ = 01,
        _WRITE = 02,
        _UNBUF = 04,
        _EOF = 010,
        _ERR = 020
};


my_FILE _iob[OPEN_MAX]={
{0,(char *) 0,(char *) 0,_READ,0},
{0,(char *) 0,(char *) 0,_WRITE,1},
{0,(char *) 0,(char *) 0,_WRITE|_UNBUF,2}
};


int my_fillbuf(my_FILE *);
my_FILE *my_fopen(char *,char *);

int my_flushbuf(int,my_FILE *);
int my_fclose(my_FILE *);
int my_fflush(my_FILE *);

#define my_putc(x,p) (--(p)->cnt>=0?*(p)->ptr++ = (x):my_flushbuf((x),p))
#define my_getc(p) (--(p)->cnt >=0?(unsigned char)*(p)->ptr++:my_fillbuf(p))

int my_fseek(my_FILE *fp,long offset,int origin);

main(){
	
	my_FILE * f1 = my_fopen("1.txt","r");
	my_fseek(f1,15,0);
	my_FILE * f2 = my_fopen("2.txt","w"); 
	my_fseek(f2,2,2);
	int c;

	while((c=my_getc(f1))!=EOF){
		my_putc(c,f2);
	}

	my_fclose(f2);
}

int my_fseek(my_FILE *fp,long offset,int origin){
	unsigned nc;
	int rc = 0;

	if(fp->flag&_READ){
		if(origin == 1)
			offset -= fp->cnt;
		lseek(fp->fd,offset,origin);
		fp->cnt = 0;
	}else if(fp->flag&_WRITE){
		if((nc = fp->ptr-fp->base)>0)
			if(write(fp->fd,fp->base,nc)!=nc)
				rc=-1;
		if(rc!=-1)
			lseek(fp->fd,offset,origin);
	}
		
	return (rc==-1)?-1:0;
}

my_FILE *my_fopen(char *name,char *mode){
	int fd;
	my_FILE *fp;
	
	if(*mode !='r'&&*mode!='w'&&*mode!='a')
		return NULL;
	for(fp=_iob;fp<_iob+OPEN_MAX;fp++)
		if((fp->flag & (_READ|_WRITE))==0)
			break;
	if(fp>=_iob+OPEN_MAX)
		return NULL;
	
	if(*mode == 'w')
		fd = creat(name,PERMS);
	else if(*mode == 'a'){
		if((fd = open(name,O_WRONLY,0))==-1)
			fd = creat(name,PERMS);
		lseek(fd,0L,2);
	}else
		fd = open(name,O_RDONLY,0);
	
	if(fd == -1)
		return NULL;
	fp->fd = fd;
	fp->cnt = 0;
	fp->base = NULL;
	fp->flag = (*mode == 'r') ?_READ:_WRITE;
	return fp;
}

int my_fillbuf(my_FILE *fp){

	int bufsize;
	
	if((fp->flag&(_READ|_EOF|_ERR))!=_READ)
		return EOF;
	bufsize = (fp->flag&_UNBUF)?1:BUFSIZ;
	if(fp->base ==NULL)
		if((fp->base = (char *)malloc(bufsize))==NULL)
			return EOF;
	fp->ptr = fp->base;
	fp->cnt = read(fp->fd,fp->ptr,bufsize);
	if(--fp->cnt < 0){
		if(fp->cnt == -1)
			fp->flag |= _EOF;
		else 
			fp->flag |= _ERR;
		fp->cnt = 0;
		return EOF;
	}
	return (unsigned char)*fp->ptr++;
}


int my_flushbuf(int x,my_FILE *fp){
	
	int bufsize;
	unsigned nc;

	if(fp < _iob || fp >= _iob+OPEN_MAX)
	 	return EOF;
	
	if((fp->flag&(_WRITE|_EOF|_ERR))!=_WRITE)
		return EOF;

	bufsize = (fp->flag&_UNBUF)?1:BUFSIZ;
	
	if(fp->base == NULL){
		if((fp->base = (char *)malloc(bufsize)) == NULL){
			//fp->flag |= _ERR;
			return EOF;
		}
	}else{
		nc = fp->ptr - fp->base;
		if(write(fp->fd,fp->base,nc)!=nc){
			//fp->flag |= _ERR;
			return EOF;
		}			
	}

	fp->ptr = fp->base;
	*fp->ptr++ = (char)x;
	fp->cnt = bufsize - 1;
	return x;
}

int my_fclose(my_FILE *fp){
	int rc;

	if((rc =my_fflush(fp))!=EOF){
		free(fp->base);
		fp->ptr = NULL;
		fp->base = NULL;
		fp->cnt = 0;
		fp->flag &= ~(_READ|_WRITE);
	}
	return rc;
}

int my_fflush(my_FILE *fp){
	int rc = 0;	
	if(fp<_iob || fp>= _iob+OPEN_MAX)
		return EOF;
	if(fp->flag&_WRITE)
		rc = my_flushbuf(0,fp);
	fp->ptr = fp->base;
	fp->cnt = (fp->flag&_UNBUF)?1:BUFSIZ;
	return rc;	
	
}











