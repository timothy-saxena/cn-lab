#include <stdio.h>

int main(void) {
    int capacity, rate, n, time, incoming, sent, dropped;
    int bucket = 0;

    printf("Enter bucket capacity, output rate and time slots: ");
    scanf("%d%d%d", &capacity, &rate, &n);
    printf("Time\tIncoming\tDropped\tSent\tRemaining\n");

    for(time = 1; time <= n || bucket > 0; time++) {
        incoming = 0;
        if(time <= n) {
            printf("Enter arrival size at time %d: ", time);
            scanf("%d", &incoming);
        }

        dropped = 0;
        if(bucket + incoming <= capacity)
            bucket += incoming;
        else
            dropped = incoming;

        sent = rate;
        if(bucket < rate)
            sent = bucket;
        bucket -= sent;

        printf("%d\t%d\t\t%d\t%d\t%d\n", time, incoming, dropped, sent, bucket);
    }
    return 0;
}
