
typedef struct {
	long ino;
	char name[NAME_MAX+1];
}Dirent;

typedef struct{
	int fd;
	Dirent d;
}my_DIR;

my_DIR *my_opendir(char *dirname);
Dirent *my_readdir(my_DIR *dfd);
void my_closedir(my_DIR *dfd);

