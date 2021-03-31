
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "erproc.h"
int main()
{
  
  // printf("Length of the string = %d\n", length);
  int fd = Socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in adr = {0};
  adr.sin_family = AF_INET;
  adr.sin_port = htons(34543);
  Inet_pton(AF_INET, "127.0.0.1", &adr.sin_addr);
  Connect(fd, (struct sockaddr *)&adr, sizeof adr);
  char *msg = malloc(sizeof(char) + 256);
  int msgLength;
  printf("Write messag:\n ");
  scanf("%s", msg);
  msgLength = strlen(msg);
  write(fd, msg, msgLength);
  size_t nread;
  char buf[256];
  nread = read(fd, buf, 256);

  if (nread == (size_t)-1)
  {
    perror("read failed");
    exit(EXIT_FAILURE);
  }
  if (nread == 0)
  {
    printf("END OF FILE occured\n");
  }
  write(STDOUT_FILENO, buf, nread);
  close(fd);

  return 0;
}