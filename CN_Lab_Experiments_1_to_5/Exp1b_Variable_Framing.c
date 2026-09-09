#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    int n;

    printf("VARIABLE FRAMING ALGORITHM\n");

    printf("Enter the string: ");
    scanf("%s", str);

    printf("Enter the number of frames: ");
    scanf("%d", &n);

    int frameSize[n];

    printf("Enter the size of each frame:\n");

    for (int i = 0; i < n; i++) {
        printf("Frame %d: ", i);
        scanf("%d", &frameSize[i]);
    }

    printf("\nNumber of frames: %d\n", n);

    int position = 0;

    for (int i = 0; i < n; i++) {
        printf("\nContent of frame %d: ", i);

        for (int j = 0; j < frameSize[i] && position < strlen(str); j++) {
            printf("%c", str[position]);
            position++;
        }
    }

    printf("\n");
}
