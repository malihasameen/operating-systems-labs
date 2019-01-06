#include <stdio.h>
#define LIMIT 4294967296
int main(){
	int physical_address, page_size = 4096;

	printf("Enter a 32-bit physical address: ");
	scanf("%d",&physical_address);
	
	if (physical_address < 0 || physical_address >= 4294967296){
		printf("Enter a valid 32-bit address!\n");
		return 1;	
	}

	int page_no = physical_address / page_size;
	int offset = physical_address % page_size;
	int starting_address = page_no * page_size;

	printf("Page Number: %d\n", page_no);
	printf("Offset: %d\n", offset);
	printf("Starting Address: 0x%x\n", starting_address);
	
}
