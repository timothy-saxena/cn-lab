#include <stdio.h>
#include <string.h>

int main() {
    char data[200];
    char stuffed[200];

    printf("Enter data: ");
    scanf("%s", data);
    strcpy(stuffed, "DLESTX");
    int j = strlen(stuffed);
    for (int i = 0; i < strlen(data); i++) {
        if (data[i] == 'D' && data[i + 1] == 'L' && data[i + 2] == 'E') {
            stuffed[j++] = 'D';
            stuffed[j++] = 'L';
            stuffed[j++] = 'E';
        }
        stuffed[j++] = data[i];
    }
    strcpy(stuffed + j, "DLEETX");
    printf("Original: %s ", data);
    printf("Stuffed: %s ", stuffed);
}