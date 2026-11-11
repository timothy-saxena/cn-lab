#include <stdio.h>
int main() {
    char data[200];
    char stuffed[200];
    printf("enter data: ");
    scanf("%s", data);
    int j = 0, count = 0;
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

    printf("original data \n%s : ", data);
    printf("stuffed data \n%s\n : ", stuffed);
}