#include <stdio.h>

int main(void) {
    char text[100];
    int key, i;

    printf("Enter uppercase text (no spaces): ");
    scanf("%99s", text);
    printf("Enter key (0 to 25): ");
    scanf("%d", &key);

    for(i = 0; text[i] != '\0'; i++)
        text[i] = 'A' + (text[i] - 'A' + key) % 26;
    printf("Encrypted text: %s\n", text);

    for(i = 0; text[i] != '\0'; i++)
        text[i] = 'A' + (text[i] - 'A' - key + 26) % 26;
    printf("Decrypted text: %s\n", text);

    return 0;
}
