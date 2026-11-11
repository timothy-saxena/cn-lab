#include <stdio.h>
#include <string.h>

void divide(char divident[], char divisor[]) {
    int n = strlen(divident);
    int m = strlen(divisor);

    for (int i = 0; i <= n - m; i++) {
        if (divident[i] == '1') {
            for (int j = 0; j < m; j++) {
                if (divident[i + j] == divisor[j]) {
                    divident[i + j] = '0';
                } else {
                    divident[i + j] = '1';
                }
            }
        }
    }
}

int main() {
    char data[20];
    char divisor[20];
    char crc[20];
    char temp[20];
    char codeword[20];

    printf("enter data");
    scanf("%s", data);

    printf("enter divsor");
    scanf("%s", divisor);

    strcpy(temp, data);

    int dataLen = strlen(data);
    int divLen = strlen(divisor);

    // append zeros
    for (int i = 0; i < divLen - 1; i++) temp[dataLen + i] = '0';
    temp[divLen + dataLen - 1] = '\0';

    divide(temp, divisor);

    // extract crc
    for (int i = 0; i < divLen - 1; i++) crc[i] = temp[dataLen + i];
    crc[divLen - 1] = '\0';

    printf("\n CRC: %s\n", crc);

    strcpy(codeword, data);
    strcat(codeword, crc);
    printf("\nCodeword: %s", codeword);

    printf("enter the codeword you received");
    scanf("%s", codeword);
    divide(codeword, divisor);

    int err = 0;
    for (int i = strlen(codeword) - divLen + 1; i < strlen(codeword); i++) {
        if (codeword[i] == '1') {
            err = 1;
            break;
        }
    }
    if (err) {
        printf("error");
    } else {
        printf("good");
    }
}
