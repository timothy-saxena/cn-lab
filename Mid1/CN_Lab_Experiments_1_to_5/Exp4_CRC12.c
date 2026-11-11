#include <stdio.h>
#include <string.h>

int main() {
    char data[100], codeword[120];
    char generator[] = "1100000001111";

    int data_length;
    int generator_length = strlen(generator);

    // I/P: 110101

    printf("Enter data: ");
    scanf("%s", data);

    data_length = strlen(data);

    strcpy(codeword, data);

    // Append 12 zeros
    for (int i = 0; i < generator_length - 1; i++)
        codeword[data_length + i] = '0';

    codeword[data_length + generator_length - 1] = '\0';

    // XOR division
    for (int i = 0; i <= strlen(codeword) - generator_length; i++) {
        if (codeword[i] == '1') {
            for (int j = 0; j < generator_length; j++) {
                if (codeword[i + j] == generator[j])
                    codeword[i + j] = '0';
                else
                    codeword[i + j] = '1';
            }
        }
    }

    printf("CRC: ");

    for (int i = data_length; i < data_length + generator_length - 1; i++) {
        printf("%c", codeword[i]);
    }

    printf("\n");
}
