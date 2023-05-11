#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 20
typedef struct 
{
    char name[MAX_FILENAME_LENGTH];
    int size;
} File;
int numFiles = 0;
File files[MAX_FILES];
void createFile(char* name, int size) 
{
    if (numFiles >= MAX_FILES) 
	{
        printf("Directory is full, cannot create file\n");
        return;
    }
    if (strlen(name) > MAX_FILENAME_LENGTH - 1) 
	{
        printf("Filename too long, please use a shorter name\n");
        return;
    }
    strcpy(files[numFiles].name, name);
    files[numFiles].size = size;
    numFiles++;
    printf("File created: %s (%d bytes)\n", name, size);
}
void deleteFile(char* name) 
{
    int i;
    for (i = 0; i < numFiles; i++) 
	{
        if (strcmp(files[i].name, name) == 0) 
		{
            printf("File deleted: %s (%d bytes)\n", files[i].name, files[i].size);
            files[i] = files[numFiles - 1];
            numFiles--;
            return;
        }
    }
    printf("File not found: %s\n", name);
}
void displayFiles() 
{
    int i;
    printf("Directory listing:\n");
    for (i = 0; i < numFiles; i++) 
	{
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }
}
int main() 
{
    char choice;
    char name[MAX_FILENAME_LENGTH];
    int size;
    while (1) 
	{
        printf("\n1. Create file\n");
        printf("2. Delete file\n");
        printf("3. Display files\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);
        switch (choice) 
		{
            case '1':
                printf("Enter filename: ");
                scanf("%s", name);
                printf("Enter file size (in bytes): ");
                scanf("%d", &size);
                createFile(name, size);
                break;
            case '2':
                printf("Enter filename: ");
                scanf("%s", name);
                deleteFile(name);
                break;
            case '3':
                displayFiles();
                break;
            case '4':
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
    }
    return 0;
}
