#include <stdio.h>
#include <stdlib.h>
#include <ftw.h>
#include <sys/stat.h>
#include <string.h>


#define MAX_FTW_DEPTH 16

static int num_dirs, num_regular;

static int callback(const char *fpath, const struct stat *sb, int typeflag) {
  if (typeflag == FTW_D) { //if the typeflag indicates a directory, increment num_dirs and return exit value zero
    num_dirs++;
    return 0;
  } else {
    if (typeflag == FTW_F) { //if the typeflag indicates a file, incremend num_regular and return exit value zero
      num_regular++;
      return 0;
    }
  }

  //if something goes wrong, return exit value one
  return 1;
  
}


int main(int argc, char** argv) {

	//check to make sure we have the right number of arguments
  if (argc != 2) {
    printf("Need exactly two arguments\n");
  }

  //start the counters at zero
  num_dirs = 0;
  num_regular = 0;
  int errcode;

  //call ftw and make sure the exit value is zero
  if ((errcode = ftw(argv[1], callback, MAX_FTW_DEPTH)) != 0) {
    printf("FTW Error\n");
    return 1;
  }

  //print the results
  printf("There were %d directories.\n", num_dirs);
  printf("There were %d regular files.\n", num_regular);
  
}
