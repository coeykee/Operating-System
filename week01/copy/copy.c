#include<stdio.h>
#include<string.h>

int main(){
	//copy src.txt to des.txt
	FILE *fps=fopen("src.txt","r");
	FILE *fpd=fopen("des.txt","w");
	if(fps==NULL || fpd==NULL){
		printf("File not found!");
	 }

	char c;
	
	while(c!=EOF){
		c=fgetc(fps);
		fputc(c,fpd);
	}

	fclose(fps);
	fclose(fpd);

	return 0;

}
