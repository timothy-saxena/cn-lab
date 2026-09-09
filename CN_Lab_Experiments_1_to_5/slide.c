#include <stdio.h>

int main() {
    int total_frames;
    int window_size;
    int lost_frame;

    printf("Enter total number of frames: ");
    scanf("%d", &total_frames);

    printf("Enter window size: ");
    scanf("%d", &window_size);

    printf("Enter frame to simulate loss (-1 for no loss): ");
    scanf("%d", &lost_frame);

    int start = 0;

    while (start < total_frames) {
        int end = start + window_size;

        if (end > total_frames) end = total_frames;

        printf("\n--- Current Window ---\n");

        for (int i = start; i < end; i++) {
            printf("Sending frame %d\n", i);

            if (i == lost_frame) {
                printf("Frame %d lost!\n", i);
            } else if (lost_frame != -1 && i > lost_frame) {
                printf("Frame %d discarded (out of order)\n", i);
            } else {
                printf("ACK %d received\n", i);
            }
        }

        if (lost_frame >= start && lost_frame < end) {
            printf("\nGo-Back-N activated.\n");
            printf("Retransmitting from frame %d:\n", lost_frame);

            for (int i = lost_frame; i < end; i++) {
                printf("Retransmitting frame %d\n", i);
            }

            printf("ACKs received for retransmitted frames.\n");

            // Loss has now been handled
            lost_frame = -1;
        }

        start = end;
    }
    printf("\nAll frames transmitted successfully.\n");

    return 0;
}