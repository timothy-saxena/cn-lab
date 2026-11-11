#include <stdio.h>

int main(void) {
    int capacity, rate, n;
    int i;

    printf("Enter capacity, output rate and number of arrivals: ");
    scanf("%d%d%d", &capacity, &rate, &n);

    int packet, sent;
    int bucket = 0;

    for(i = 1; i <= n; i++) {
        printf("Time %d - Enter packet size: ", i);
        scanf("%d", &packet);

        if(bucket + packet <= capacity)
            bucket += packet;
        else
            printf("Packet dropped\n");

        sent = rate;
        if(bucket < rate)
            sent = bucket;
        bucket -= sent;

        printf("Sent: %d, Remaining: %d\n", sent, bucket);
    }

    while(bucket > 0) {
        sent = rate;
        if(bucket < rate)
            sent = bucket;
        bucket -= sent;
        printf("Draining - Sent: %d, Remaining: %d\n", sent, bucket);
    }
}
