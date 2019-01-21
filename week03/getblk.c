#include<stdio.h>
#include<string.h>

char hash_queue[5][5] = {"blk00", "blk01", "blk02", "blk03", "blk04"};
char free_list[5][5] = {"blk01", "blk02", "blk03", "blk05", "blk06"};
char delayed_write[5][5] = {"blk05", " ", " ", " ", " "};
char busy[5][5] = {"blk06", " ", " ", " ", " "};

int search_in(char buffer[])
{
    char keywords [32][10]={"blk00", "blk01", "blk02", "blk03", "blk04"};
    int i,flag=0;
    for(i=0;i<32;i++)
    {
        if(strcmp(keywords[i],buffer)==0)
        {
            flag=1;
            break;
        }
    }
    return flag;
} 

int is_empty(char array[5][5]){return 0;}

void delete_from(char array[5][5], char blk[5]){}

void insert_in(char array[5][5], char blk[5]){}

void display(char array[5][5]){
	int i,j;
	for(i = 0; i<5; i++){
		for(j = 0; j<5 ; j++){
			printf("%c", array[i][j]);
		}
		printf("\t");
	}
}

int main(){

	printf("Enter block: ");
	char blk[5];
	int i;
	for(i = 0; i<5; i++){
		scanf("%c",&blk[i]);
	}

	int flag=0;
	repeat :

	while(flag!=1){
		printf("\nhash_queue:\n");
		display(hash_queue);
		printf("\n\nfree_list:\n");
		display(free_list);
		printf("\n\nBusy buffers:\n");
		display(busy);
		printf("\n\nmarked as delayed_write:\n");
		display(delayed_write);
		if(search_in(blk) == 1){
			printf("Block is present in hash_queue\n");
			if(search_in(blk) == 1){
				printf("Block is Busy\n");
				printf("process is in sleep mode now\n");
			}
			insert_in(busy, blk);
			printf("Marked as busy\n");
			delete_from(free_list, blk);
			printf("Deleted from free_list\n");
			printf("Buffer is allocated.");
			flag=1;
		}
		else{
			if(is_empty(free_list) == 1){
				printf("free_list is empty\n");
				printf("process goes to sleep\n");
			}
			delete_from(free_list, blk);
			if(	search_in(blk) == 1){
				printf("Block has delayed write\n");
				printf("Performs delayed write\n" );
			
			}
			delete_from(free_list, blk);
			printf("Deleted from free_list\n");
			delete_from(hash_queue, blk);
			insert_in(hash_queue,blk);
			printf("Buffer is allocated\n");
			flag=1;
		}
	}
	return 0;
}