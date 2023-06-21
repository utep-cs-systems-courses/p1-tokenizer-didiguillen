#include <stdio.h>
int main()
{
  printf(">");
  char buf[5000];
  fgets(buf, 5000, stdin);
  printf("%s", buf);
}
