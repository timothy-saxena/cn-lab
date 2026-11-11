#include <stdio.h>

int main() {
    char data[100], stuffed[200];
    int j = 0, count = 0;

    // I/P: 1011111101

    printf("Enter binary data: ");
    scanf("%s", data);

    for (int i = 0; data[i] != '\0'; i++) {
        stuffed[j++] = data[i];

        if (data[i] == '1') {
            count++;

            if (count == 5) {
                stuffed[j++] = '0';
                count = 0;
            }
        } else {
            count = 0;
        }
    }

    stuffed[j] = '\0';

    printf("Original data: %s\n ", data);
    printf("Stuffed data : %s\n ", stuffed);
}
