#include <stdio.h>
#include <string.h>

void divide(char divident[], char divisor[]) {
    int n = strlen(divident);
    int m = strlen(divisor);

    for (int i = 0; i <= n - m; i++) {
        if (divident[i] == '1') {
            for (int j = 0; j < m; j++) {
                if (divident[i + j] == divisor[j])
                    divident[i + j] = '0';
                else
                    divident[i + j] = '1';
            }
        }
    }
}

int main() {
    char data[100];
    char divisor[20];
    char temp[100];
    char crc[20];
    char codeword[100];

    printf("Enter data: ");
    scanf("%s", data);

    printf("Enter divisor: ");
    scanf("%s", divisor);

    int dataLen = strlen(data);
    int divisorLen = strlen(divisor);

    /* Generate CRC */

    strcpy(temp, data);

    for (int i = 0; i < divisorLen - 1; i++) temp[dataLen + i] = '0';

    temp[dataLen + divisorLen - 1] = '\0';

    divide(temp, divisor);

    // Extract remainder
    for (int i = 0; i < divisorLen - 1; i++) crc[i] = temp[dataLen + i];

    crc[divisorLen - 1] = '\0';

    printf("\nCRC: %s", crc);

    /* Create codeword */

    strcpy(codeword, data);
    strcat(codeword, crc);

    printf("\nCodeword: %s", codeword);

    /* Check received codeword */

    printf("\n\nEnter received codeword: ");
    scanf("%s", codeword);

    divide(codeword, divisor);

    int error = 0;

    for (int i = strlen(codeword) - divisorLen + 1; i < strlen(codeword); i++) {
        if (codeword[i] == '1') {
            error = 1;
            break;
        }
    }

    if (error == 0)
        printf("No error detected.\n");
    else
        printf("Error detected.\n");

    return 0;
}