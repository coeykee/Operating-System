#include<stdio.h>
#include<string.h>

void print_content(char list[5][5]){

	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			printf("%c",list[i][j]);
		}
		printf("  ");
	}
}

int find_into(char list[5][5], char blk[1][5]){
	int flag = 0;
	for(int i=0; i<5; i++){
		if(strcmp(list[i],blk[0])== 0){
			printf("Block is in freelist.\n");
			return 1;
		}
	}
}

int del_from(char list[5][5], char blk[1][5]){
	int index;
	for(int i=0; i<5; i++){
		if(strcmp(list[i],blk[0])==0)
			index=i;
	}
	return index;
}

int if_empty(char list[5][5]){
	int flag;
	for(int i=0; i<5; i++){
		if(list[i][0]=' ')
			flag=1;
		else flag=0;	
	}
	return flag;
}

int is_marked_delayed(char blk[1][5]){
	if(strcmp(blk[0], "blk06")==0){ return 1;}
	else return 0;
}

int is_busy(char blk[1][5]){
	if(strcmp(blk[0], "blk05")==0){ return 1;}
	else return 0;
}

int main(){
	//1. kernel finds block on hash queue & buffer is free. So allocation takes place.

	char hash_queue[5][5] = {"blk00", "blk01", "blk02", "blk03", "blk04"};
	char free_list[5][5] = {"blk00", "blk01", "blk03", "blk06", "blk07"};
	printf("hash_queue:\n");
	print_content(hash_queue);
	printf("\n\nfree_list:\n");
	print_content(free_list);

	//process asks particular block
	char blk[1][5];
	printf("\n\nRequest block:");
	for(int k=0; k<5; k++){
		scanf("%c",&blk[0][k]);
	}


	//kernel finds block on hash_queue
	if(find_into(hash_queue, blk)==1){
		//if blk is in hash_queue
		printf("\nBlock hash is present in hash_queue.\n");
		if(is_busy(blk)==1){printf("Sets indemand flag.\n");// scaenario 5
		}

		else if(find_into(free_list, blk) == 25){
			//if blk is in freelist
			printf("\nblock is allocated by kernel.\n"); // scenario 1 
			//int index=del_from(free_list, blk);
			//printf("%d",index);
		}
		else{
			printf("Block is not in free_list.\n");
		}
	}
	else{
		//block is not in hash_queue
		printf("Block is not in hash_queue.\n");
	
		//check if free_list is empty 
		if(if_empty(free_list) == 1){ printf("Freelist is empty.\nProcess goes to sleep"); 
		// scenario 4.
		}

		else if(is_marked_delayed(blk) == 1){
			printf("Allocates another block.\n"); // scenario 3
		}

		else{printf("Allocates from free_list.\n"); // scenario 2
			}
	

	}
	
	return 0;	
}
