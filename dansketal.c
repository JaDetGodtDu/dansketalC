#include <stdio.h>
#include <string.h>
#include "helpers.h"

void dansketal(int num, char* buffer) {
    buffer[0] = '\0'; // Clear the buffer

    if (num < 0) {
        strcat(buffer, "minus ");
        num = -num;
    }

    if (num == 0) {
        strcat(buffer, "nul");
    } else if (num < 10) {
        convert_units(num, buffer,0);
    } else if (num < 100) {
        convert_tens(num, buffer);
    } else if (num < 1000) {
        convert_hundreds(num, buffer);
    } else if (num < 1000000) {
        convert_thousands(num, buffer);
    } else if (num < 1000000000) {
        convert_millions(num, buffer);
    }
}
int main() {
    char buffer[256];
    int number = 125000;
    dansketal(number, buffer);
    printf("%d in Danish is: %s\n", number, buffer);
    return 0;
}