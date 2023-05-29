#include <stdio.h>
#define DISK_SIZE 16
#define INODE_BLOCKS 8
#define MIN_FILE_SIZE 1
#define MAX_FILE_SIZE 9
int isContiguousFree(int allocation[], int start_block, int num_blocks) 
{
    for (int i = start_block; i < start_block + num_blocks; i++) 
	{
        if (allocation[i] != -1) 
		{
            return 0; 
        }
    }
    return 1; 
}
void allocateBlocks(int allocation[], int start_block, int num_blocks, int file_size) 
{
    for (int i = start_block; i < start_block + num_blocks; i++) 
	{
        allocation[i] = file_size;
        file_size--;
    }
}
void displayAllocation(int allocation[], int n) 
{
    printf("\nBlock No.\tFile Size\n");
    for (int i = 0; i < n; i++) 
	{
        printf("%d\t\t", i);
        if (allocation[i] != -1) 
		{
            printf("%d KB\n", allocation[i]);
        } 
		else 
		{
            printf("Free\n");
        }
    }
}
int main() 
{
    int allocation[DISK_SIZE] = {0}; 
    int file_size;
    printf("Enter the file size (1 to 9 KB): ");
    scanf("%d", &file_size);
    if (file_size < MIN_FILE_SIZE || file_size > MAX_FILE_SIZE) 
	{
        printf("Invalid file size\n");
        return 1;
    }
    int start_block = -1;
    int num_blocks = 0;
    for (int i = INODE_BLOCKS; i < DISK_SIZE; i++) 
	{
        if (allocation[i] == -1) 
		{
            if (start_block == -1) 
			{
                start_block = i;
            }
            num_blocks++;
            if (num_blocks == file_size) 
			{
                break;
            }
        } 
		else 
		{
            start_block = -1;
            num_blocks = 0;
        }
    }
    if (num_blocks == file_size) 
	{
        allocateBlocks(allocation, start_block, num_blocks, file_size);
        printf("File allocated successfully!\n");
        displayAllocation(allocation, DISK_SIZE);
    } 
	else 
	{
        printf("Not enough contiguous blocks available\n");
        return 1;
    }
    return 0;
}
