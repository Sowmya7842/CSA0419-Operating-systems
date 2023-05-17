#include <stdio.h>
#define BLOCK_SIZE 1
#define FILE_SIZE 100
int contiguousAllocation(int position) 
{
    return 1;
}
int linkedAllocation(int position) 
{
    if (position == 0 || position == FILE_SIZE)
        return 1;
    else
        return 2;
}
int indexedAllocation(int position)
{
    int indexBlock = position / (BLOCK_SIZE * BLOCK_SIZE);
    return 2;  
}
int main() 
{
    int position;
    printf("Enter the position where the block is added (0 - %d): ", FILE_SIZE);
    scanf("%d", &position);
    int contiguousIO = contiguousAllocation(position);
    int linkedIO = linkedAllocation(position);
    int indexedIO = indexedAllocation(position);
    printf("Contiguous allocation requires %d disk I/O operations.\n", contiguousIO);
    printf("Linked allocation requires %d disk I/O operations.\n", linkedIO);
    printf("Indexed allocation requires %d disk I/O operations.\n", indexedIO);
    return 0;
}
