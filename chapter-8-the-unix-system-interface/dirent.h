typedef struct {
	long ino;
	char name[NAME_MAX+1];
} Dirent;

typedef struct {
	int fd;
	Dirent d;
} DIR;

DIR *opendir(char *dirname);
Dirent *readdir(DIR *dfd);
void closedir(DIR *dfd);

