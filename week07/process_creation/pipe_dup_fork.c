//Use of Pipe, Dup and Fork
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char string[] = "hello world";
int main(){
	int count, i;
	int to_par[2], to_chil[2];
	char buf[256];
	pipe(to_par);
	pipe(to_chil);
	if(fork() == 0){
		/*child process executes here*/
		close(0); //close old std input
		dup(to_chil); //dup pipe read to std input
		close(1); //close old std output
		dup(to_par[1]); //dup pipe write to std out
		close(to_par[1]); //close unneccessary pipe descriptors
		close(to_chil[0]);
		close(to_par[0]);
		close(to_chil[1]);
		for(;;)
		{
			if((count = read(0, buf, sizeof(buf))) == 0)
				printf("exit()"); //exit();
			write(1, buf, count);
		}
	}
	
	/*parent process executes here*/
	close(1);
	dup(to_chil[1]);
	close(0);
	dup(to_par[0]);
	close(to_chil[1]);
	close(to_par[0]);
	close(to_chil[0]);
	close(to_par[1]);
	for(i = 0; i < 15; i++){
		write(1, string, strlen(string));
		read(0, buf, sizeof(buf));
	}
return 0;
}
