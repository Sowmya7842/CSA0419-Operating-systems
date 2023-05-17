#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define MAX_LENGTH 100
int main() 
{
    char filename[100];
    char data[MAX_LENGTH];
    printf("Enter the filename: ");
    scanf("%s", filename);
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) 
	{
        perror("Failed to open the file");
        exit(EXIT_FAILURE);
    }
    printf("Enter the data to write to the file (maximum length: %d): ", MAX_LENGTH);
    scanf(" %[^\n]s", data);
    ssize_t bytesWritten = write(fd, data, sizeof(data));
    if (bytesWritten == -1) 
	{
        perror("Failed to write to the file");
        exit(EXIT_FAILURE);
    }
    close(fd);
    fd = open(filename, O_RDONLY);
    if (fd == -1) 
	{
        perror("Failed to open the file");
        exit(EXIT_FAILURE);
    }
    char fileData[MAX_LENGTH];
    ssize_t bytesRead = read(fd, fileData, sizeof(fileData));
    if (bytesRead == -1) 
	{
        perror("Failed to read from the file");
        exit(EXIT_FAILURE);
    }
    close(fd);
    printf("Data read from the file:\n%s\n", fileData);
    return 0;
}
