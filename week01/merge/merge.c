#include<stdio.h>
#include<string.h>

int main(){
	//merges first.txt into merged.txt keeps merged's contents
	FILE *fpf=fopen("first.txt","r");
	FILE *fpm=fopen("merged.txt","a");
	if(fpf==NULL || fpm==NULL){
		printf("File not found!");
	 }

	char c;
	
	do{
		c=fgetc(fpf);
		fputc(c,fpm);
	}while(c!=EOF);

	fclose(fpf);
	fclose(fpm);

	return 0;

}
