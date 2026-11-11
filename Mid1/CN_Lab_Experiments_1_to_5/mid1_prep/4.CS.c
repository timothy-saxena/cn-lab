#include <stdio.h>
#include <string.h>

int main() {
    char data[100], stuffed[200];
    int i, j = 0;

    printf("Enter data: ");
    scanf("%s", data);

    // Start of frame
    strcpy(stuffed, "DLESTX");
    j = strlen(stuffed);

    for (i = 0; i < strlen(data); i++) {
        // If data contains DLE, stuff another DLE
        if (data[i] == 'D' && data[i + 1] == 'L' && data[i + 2] == 'E') {
            stuffed[j++] = 'D';
            stuffed[j++] = 'L';
            stuffed[j++] = 'E';
        }

        // Copy original character
        stuffed[j++] = data[i];
    }

    // End of frame
    strcpy(stuffed + j, "DLEETX");

    printf("After character stuffing: %s\n", stuffed);
}