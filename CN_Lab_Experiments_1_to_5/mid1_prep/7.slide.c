#include <stdio.h>

int main() {
    int n, window, start = 0, lost;
    int i, end;

    printf("Enter the number of frames: ");
    scanf("%d", &n);

    printf("Enter the window size: ");
    scanf("%d", &window);

    printf("Enter frame number to simulate loss: ");
    scanf("%d", &lost);

    while (start < n) {
        end = start + window;

        if (end > n) end = n;

        printf("\nSending window: ");

        for (i = start; i < end; i++) printf("%d ", i);

        printf("\n");

        for (i = start; i < end; i++) {
            if (i == lost) {
                printf("Frame %d lost\n", i);
                printf("Receiver sends NAK for frame %d\n", i);

                printf("Go-Back-N: Retransmitting from frame %d\n", i);

                for (; i < end; i++)
                    printf("Frame %d retransmitted successfully\n", i);

                lost = -1;
                break;
            } else {
                printf("Frame %d transmitted successfully\n", i);
            }
        }

        start = end;
    }

    printf("\nAll frames transmitted successfully.\n");

    return 0;
}