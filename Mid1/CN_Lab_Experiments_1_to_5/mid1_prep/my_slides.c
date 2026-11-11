#include <stdio.h>
int main() {
    int n, window, start = 0, end, lost;
    printf("enter nof,windowsize,lost");
    scanf("%d %d %d", &n, &window, &lost);

    while (start < n) {
        end = start + window;
        if (end > n) end = n;
        printf("sending \n");
        for (int i = start; i < end; i++) {
            printf("%d ", i);
        }
        for (int i = start; i < end; i++) {
            if (i == lost) {
                printf("frame %d LOST", i);
                printf("\nno ack sent by receiver");
                printf("\nretranmit from n");
                for (; i < end; i++) {
                    printf("frame %d retranmited", i);
                }
                lost = -1;
                break;
            } else {
                printf("Frame %d done", i);
            }
        }
        start = end;
    }
}