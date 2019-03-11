#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(argc, argv)
	int argc;
	char *argv[];	
{
	int fd;
	char buf[1024];
	struct stat statbuf;

	if(argc != 2){
		//exit();
		printf("Calls exit()");		
	}

	fd = open(argv[1], O_RDONLY);
	if(fd == -1){
		//exit();
		printf("Calls exit()");
	}	

	if(unlink(argv[1]) == -1){
		//exit();
		printf("Calls exit()");
	}	

	if(stat(argv[1], &statbuf) == -1)
		printf("stat %s fails as it should\n", argv[1]);
	else
		printf("stat %s succeeded!!!\n", argv[1]);
	if(fstat(fd, &statbuf) == -1)
		printf("fstat %s fails!!!\n", argv[1]);
	else
 		printf("fstat %s succeeds as it should\n", argv[1]);
	while(read(fd, buf, sizeof(buf)) > 0)
		printf("%1024s", buf);
return 0;
	
}

/*
OUTPUT:
ubuntu@ubuntu-OptiPlex-360:~/Operating-system/week07/unlink$ gedit one.txt two.txt
ubuntu@ubuntu-OptiPlex-360:~/Operating-system/week07/unlink$ gcc unlink.c 
unlink.c: In function ‘main’:
unlink.c:26:5: warning: implicit declaration of function ‘unlink’ [-Wimplicit-function-declaration]
  if(unlink(argv[1]) == -1){
     ^
unlink.c:39:8: warning: implicit declaration of function ‘read’ [-Wimplicit-function-declaration]
  while(read(fd, buf, sizeof(buf)) > 0)
        ^
ubuntu@ubuntu-OptiPlex-360:~/Operating-system/week07/unlink$ ./a.out one.txt two.txt
Calls exit()stat one.txt fails as it should
fstat one.txt succeeds as it should
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   ones content
ubuntu@ubuntu-OptiPlex-360:~/Operating-system/week07/unlink$ 



RESULT:
File one.txt gets deleted

*/

