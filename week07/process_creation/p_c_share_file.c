//Program where Parent and Child share File Access
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
int fdrd, fdwt;
char c;

int main(argc, argv)
	int argc;
	char *argv[];
{
	if(argc !=3)
		exit(1);
	if((fdrd = open(argv[1], O_RDONLY)) == -1)
		exit(1);
	if((fdwt = creat(argv[2], 0666)) == -1)
		exit(1);

	fork();
	/* both processes execute same code */
	rdwrt();
	exit(0);
return 0;
}

rdwrt(){
	for(;;){
		if(read(fdrd, &c, 1) != 1)
			return;
		write(fdwt, &c, 1);

	}

}


/*

OUTPUT:
ubuntu@ubuntu-OptiPlex-360:~/Operating-system/week07/process_creation$ gcc p_c_share_file.c 
p_c_share_file.c: In function ‘main’:
p_c_share_file.c:18:2: warning: implicit declaration of function ‘fork’ [-Wimplicit-function-declaration]
  fork();
  ^
p_c_share_file.c:20:2: warning: implicit declaration of function ‘rdwrt’ [-Wimplicit-function-declaration]
  rdwrt();
  ^
p_c_share_file.c: At top level:
p_c_share_file.c:25:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 rdwrt(){
 ^
p_c_share_file.c: In function ‘rdwrt’:
p_c_share_file.c:27:6: warning: implicit declaration of function ‘read’ [-Wimplicit-function-declaration]
   if(read(fdrd, &c, 1) != 1)
      ^
p_c_share_file.c:28:4: warning: ‘return’ with no value, in function returning non-void
    return;
    ^
p_c_share_file.c:29:3: warning: implicit declaration of function ‘write’ [-Wimplicit-function-declaration]
   write(fdwt, &c, 1);
   ^
ubuntu@ubuntu-OptiPlex-360:~/Operating-system/week07/process_creation$ ./a.out src.txt des.txt
ubuntu@ubuntu-OptiPlex-360:~/Operating-system/week07/process_creation$ cat src.txt 
AGJxbvjhn
sjkmvslk
LKklK
lkj>m.l;LKLJLjoijj
askpk[k
@@$$#%$#%CXGFCABC 
ubuntu@ubuntu-OptiPlex-360:~/Operating-system/week07/process_creation$ cat des.txt
AGJxbvjhn
sjkmvslk
LKklK
lkj>m.l;LKLJLjoijj
askpk[k
@@$$#%$#%CXGFCABC 
ubuntu@ubuntu-OptiPlex-360:~/Operating-system/week07/process_creation$  
*/
