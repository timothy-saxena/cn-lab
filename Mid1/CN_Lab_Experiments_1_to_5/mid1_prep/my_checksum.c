#include <stdio.h>

int sender(int data[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += data[i];
    printf("sender sum: %d", sum);
    int checksum = ~sum;
    printf("checksum value: %d", checksum);
    return checksum;
}
void reciever(int data[], int n, int checksum) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += data[i];
    printf("receicver sum: %d", sum);

    sum += checksum;

    int result = ~sum;
    printf("final checksum: %d", result);

    if (result == 0)
        printf("\nAccepted");
    else
        printf("\nRejected");
}

int main() {
    int data[100];
    int n, checksum;
    printf("nuber of elements: ");
    scanf("%d ", &n);
    for (int i = 0; i < n; i++) scanf("%d", &data[i]);
    checksum = sender(data, n);
    reciever(data, n, checksum);
}