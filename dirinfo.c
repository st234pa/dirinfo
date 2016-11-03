#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(){
  struct dirent *d;
  DIR *x = opendir(".");
  long t = 0;
  while(d = readdir(x)){
    //printf("%d\n",d->d_type );
    if (d->d_type == 4){
      printf("%s",d->d_name );
      printf("/\n");
    }
    else {
      printf("%s\n",d->d_name );
      struct stat *s;
      stat(d->d_name, s);
      t+=1;
    }
   
  }
  printf("%d\n", t);
  return 0;
}
