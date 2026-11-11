#include <stdio.h>
#include <string.h>

int main() {
    char data[100];
    int size;

    printf("Enter the data \n");
    scanf("%s", data);

    printf("Enter the fized frame size.");
    scanf("%d", &size);

    for (int i = 0; i < strlen(data); i += size) {
        printf("[");
        for (int j = i; j < i + size && j < strlen(data); j++) {
            printf("%c", data[j]);
        }
        printf("]\n");
    }
}