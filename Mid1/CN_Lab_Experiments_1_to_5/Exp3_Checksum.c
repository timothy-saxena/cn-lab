    #include <stdio.h>
    #include <string.h>

    int main() {
        char data[10][5], sum[5], checksum[5];
        int n;

        // I/P:
        // 2
        // 1010
        // 1100

        printf("Enter number of 4-bit words: ");
        scanf("%d", &n);

        printf("Enter data words:\n");

        for (int i = 0; i < n; i++) scanf("%s", data[i]);

        strcpy(sum, data[0]);

        for (int i = 1; i < n; i++) {
            int carry = 0;
            char temp[5];

            for (int j = 3; j >= 0; j--) {
                int result = (sum[j] - '0') + (data[i][j] - '0') + carry;

                temp[j] = (result % 2) + '0';
                carry = result / 2;
            }

            if (carry) {
                for (int j = 3; j >= 0; j--) {
                    int result = (temp[j] - '0') + carry;

                    temp[j] = (result % 2) + '0';
                    carry = result / 2;
                }
            }

            temp[4] = '\0';  // IMPORTANT
            strcpy(sum, temp);
        }

        for (int i = 0; i < 4; i++) checksum[i] = (sum[i] == '0') ? '1' : '0';

        checksum[4] = '\0';

        printf("Sum      : %s\n", sum);
        printf("Checksum : %s\n", checksum);

        return 0;
    }