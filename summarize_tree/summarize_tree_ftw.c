#include <stdio.h>
#include <stdlib.h>
#include <ftw.h>
#include <sys/stat.h>
#include <string.h>


#define MAX_FTW_DEPTH 16

static int num_dirs, num_regular;

static int callback(const char *fpath, const struct stat *sb, int typeflag) {
  if (typeflag == FTW_D) {
    num_dirs++;
    return 0;
  } else {
    if (typeflag == FTW_F) {
      num_regular++;
      return 0;
    }
  }

  return 1;
  
}


int main(int argc, char** argv) {

  if (argc != 2) {
    printf("Need exactly two arguments\n");
  }

  num_dirs = 0;
  num_regular = 0;
  int errcode;

  if ((errcode = ftw(argv[1], callback, MAX_FTW_DEPTH)) != 0) {
    printf("FTW Error\n");
    return 1;
  }

  printf("There were %d directories.\n", num_dirs);
  printf("There were %d regular files.\n", num_regular);
  
}
