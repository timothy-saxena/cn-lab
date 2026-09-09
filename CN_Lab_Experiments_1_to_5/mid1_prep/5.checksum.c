#include <stdio.h>

int sender(int data[], int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) sum += data[i];

    printf("\nSender Side");
    printf("\nSum = %d", sum);

    int checksum = ~sum;

    printf("\nChecksum = %d\n", checksum);

    return checksum;
}

void receiver(int data[], int n, int checksum) {
    int sum = 0;

    for (int i = 0; i < n; i++) sum += data[i];

    printf("\nReceiver Side");
    printf("\nSum = %d", sum);

    sum += checksum;

    int result = ~sum;

    printf("\nFinal Checksum = %d", result);

    if (result == 0)
        printf("\nAccepted");
    else
        printf("\nRejected");
}

int main() {
    int n, data[200], checksum;

    printf("CHECKSUM ALGORITHM\n");

    printf("\nEnter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");

    for (int i = 0; i < n; i++) scanf("%d", &data[i]);

    checksum = sender(data, n);

    receiver(data, n, checksum);

    return 0;
}