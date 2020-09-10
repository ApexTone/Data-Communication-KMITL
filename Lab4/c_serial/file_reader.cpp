#include <stdio.h>
#include <string.h>

int main()
{
    FILE *filePointer;
    filePointer = fopen("test.txt", "r");
    if (filePointer == NULL)
    {
        printf("Error");
        return -1;
    }
    char words[5000];
    while (fscanf(filePointer, "%s", words) != EOF) // read until end of file
    {
        printf("%s\n", words);
    }
    fclose(filePointer);

    return 0;
}
