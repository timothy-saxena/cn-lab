#include <stdio.h>
#include <string.h>

int main()
{
    char data[100];
    int size;

    // I/P: HELLOWORLD 5

    printf("Enter data: ");
    scanf("%s", data);

    printf("Enter frame size: ");
    scanf("%d", &size);

    printf("\nFixed Frames:\n");

    for (int i = 0; i < strlen(data); i += size)
    {
        printf("[");
        for (int j = i; j < i + size && j < strlen(data); j++)
            printf("%c", data[j]);
        printf("]\n");
    }

    return 0;
}