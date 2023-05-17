#include <stdio.h>
#define DISK_BLOCK_SIZE 8192     
#define POINTER_SIZE 4           
#define DIRECT_BLOCKS 12
#define INDIRECT_POINTERS 1024   
#define DOUBLE_INDIRECT_POINTERS (INDIRECT_POINTERS * INDIRECT_POINTERS)
#define TRIPLE_INDIRECT_POINTERS (DOUBLE_INDIRECT_POINTERS * INDIRECT_POINTERS)
long long calculateMaxFileSize() 
{
    long long maxFileSize = 0;
    long long totalBlocks = DIRECT_BLOCKS;
    long long singleIndirectBlocks = DISK_BLOCK_SIZE / POINTER_SIZE;
    totalBlocks += singleIndirectBlocks;
    long long doubleIndirectBlocks = singleIndirectBlocks * singleIndirectBlocks;
    totalBlocks += doubleIndirectBlocks;
    long long tripleIndirectBlocks = doubleIndirectBlocks * singleIndirectBlocks;
    totalBlocks += tripleIndirectBlocks;
    maxFileSize = totalBlocks * DISK_BLOCK_SIZE;
    return maxFileSize;
}

int main() 
{
    long long maxFileSize = calculateMaxFileSize();
    printf("Maximum file size: %lld bytes\n", maxFileSize);
    return 0;
}
