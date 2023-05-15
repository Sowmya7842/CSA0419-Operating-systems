#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_USERS 3
#define MAX_FILES 3
struct User 
{
    char name[20];
    char files[MAX_FILES][20];
};
struct Directory 
{
    struct User users[MAX_USERS];
};
int main() 
{
    struct Directory directory;
    int i, j;
    for (i = 0; i < MAX_USERS; i++) 
	{
        printf("Enter the name of user %d: ", i + 1);
        scanf("%s", directory.users[i].name);
        printf("Creating %d files for user %d:\n", MAX_FILES, i + 1);
        for (j = 0; j < MAX_FILES; j++) 
		{
            printf("Enter the name of file %d: ", j + 1);
            scanf("%s", directory.users[i].files[j]);
        }
        printf("\n");
    }
    for (i = 0; i < MAX_USERS; i++) 
	{
        printf("User %d: %s\n", i + 1, directory.users[i].name);
        printf("Files: ");
        for (j = 0; j < MAX_FILES; j++) 
		{
            printf("%s ", directory.users[i].files[j]);
        }
        printf("\n\n");
    }
    return 0;
}
