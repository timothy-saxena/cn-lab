#include <stdio.h>

int main(void) {
    int a, b, c, d;

    printf("Enter IPv4 address: ");
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);

    if(a == 0 || a == 127)
        printf("Special address range\n");
    else if(a <= 126) {
        printf("Class A\nDefault mask: 255.0.0.0\n");
        printf("Network address: %d.0.0.0\n", a);
        printf("Host part: %d.%d.%d\n", b, c, d);
    } else if(a <= 191) {
        printf("Class B\nDefault mask: 255.255.0.0\n");
        printf("Network address: %d.%d.0.0\n", a, b);
        printf("Host part: %d.%d\n", c, d);
    } else if(a <= 223) {
        printf("Class C\nDefault mask: 255.255.255.0\n");
        printf("Network address: %d.%d.%d.0\n", a, b, c);
        printf("Host part: %d\n", d);
    } else if(a <= 239)
        printf("Class D: Multicast\n");
    else
        printf("Class E: Reserved\n");
}
