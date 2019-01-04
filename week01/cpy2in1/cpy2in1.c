#include<stdio.h>
#include<string.h>

int main(){
	//copies first.txt into copied.txt and then sec.txt to copied.txt
	FILE *fpfirst=fopen("first.txt","r");
	FILE *fpsec=fopen("sec.txt","r");
	FILE *fpcopied=fopen("copied.txt","w");
	char c;
	if(fpfirst==NULL || fpsec==NULL || fpcopied==NULL ){
		printf("FIle not found!");
	 }

	while(c!=EOF){
		c=fgetc(fpfirst);
		fputc(c,fpcopied);
	}
	fclose(fpfirst);
	fclose(fpcopied);
	
	FILE *fpcopied2=fopen("copied.txt","w");
	char s;
   	while(s!=EOF){
		s=fgetc(fpsec);
		fputc(s,fpcopied2);
	}
	fclose(fpsec);
	fclose(fpcopied2);

	return 0;

}
