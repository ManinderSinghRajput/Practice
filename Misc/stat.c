#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define FILENAME "/tmp/meralink"

int main()
{
  struct stat st;

  lstat(FILENAME, &st);
  if (S_ISLNK(st.st_mode)) {
    printf("O yes link!!\n");
    printf("Inode:%d\n",(int)st.st_ino);
    stat(FILENAME, &st);
    printf("Inode by stat:%d\n",(int)st.st_ino);
  }
  else
  {
    printf("O no link!!\n");
    printf("%d\n",(int)st.st_ino);
  }
  return 0;
}
