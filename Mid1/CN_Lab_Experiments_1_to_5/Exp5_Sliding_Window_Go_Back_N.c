#include <stdio.h>

int main() {
    int total, window, lost;

    // I/P:
    // 6
    // 3
    // 1

    printf("Enter total number of frames: ");
    scanf("%d", &total);

    printf("Enter window size: ");
    scanf("%d", &window);

    printf("Enter frame to simulate loss (-1 for none): ");
    scanf("%d", &lost);

    for (int start = 0; start < total; start += window) {
        int end = start + window;

        if (end > total) end = total;

        printf("\nWindow: ");

        for (int i = start; i < end; i++) printf("%d ", i);

        printf("\n");

        for (int i = start; i < end; i++) {
            printf("Sending frame %d\n", i);

            if (i == lost)
                printf("Frame %d lost!\n", i);
            else if (lost != -1 && i > lost)
                printf("Frame %d discarded (out of order)\n", i);
            else
                printf("ACK %d received\n", i);
        }

        if (lost >= start && lost < end) {
            printf("Go-Back-N: Retransmitting from frame %d\n", lost);

            for (int i = lost; i < end; i++)
                printf("Retransmitting frame %d\n", i);

            lost = -1;
        }
    }

    printf("\nAll frames transmitted successfully.\n");

    return 0;
}
