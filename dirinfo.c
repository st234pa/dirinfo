#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>

void print_total_size(int size) {
  char units[4][4] = {"B", "KB", "MB", "GB"}; int i = 0;
  while(size / 1024 > 1) {
    size = size / 1024;
    i++;
  }
  printf("Total size: %d %s\n", size, units[i]);
}

/*int size(struct dirent *d) {
  struct stat buf;
  stat(d->d_name, &buf);
  int size;
  size = buf.st_size;
  return size;
  }*/

int main(){
  struct dirent *d;
  DIR *x = opendir(".");
  int t = 0;
  if (x) {
    while(d = readdir(x)){
      printf("%s",d->d_name );
      if (d->d_type == 4){  
	printf("/");
      }
      struct stat buf;
      stat(d->d_name, &buf);
      int size;
      size = buf.st_size;
      t+=size;
      printf("\n");
    }
    closedir(x);
  }
  //printf("%d\n", t);
  print_total_size(t);
  
  return 0;
}
