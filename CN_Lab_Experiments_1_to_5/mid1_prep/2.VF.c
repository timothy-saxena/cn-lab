#include <stdio.h>
#include <string.h>

int main() {
    printf("Enter the data \n");
    char data[100];
    scanf("%s", data);

    int frame_count;
    printf("Enter frame count.");
    scanf("%d", &frame_count);

    int frame_sizes[frame_count];
    for (int i = 0; i < frame_count; i++) {
        printf("Enter size of frame %d: ", i + 1);
        scanf("%d", &frame_sizes[i]);
    }

    int pos = 0;
    for (int i = 0; i < frame_count; i++) {
        printf("Frame %d \n ", i + 1);
        for (int j = 0; j < frame_sizes[i] && pos < strlen(data); j++) {
            printf("%c", data[pos]);
            pos++;
        }
        printf("\n");
    }
}