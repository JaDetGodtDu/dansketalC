#include <stdio.h>
#include <string.h>
#include "helpers.h"
#include "dansketal.h"

int main()
{
    char buffer[256];
    int number = 125;
    DanskeTalConfig config = {1}; // Use "en" for large numbers
    dansketal(number, buffer, &config);
    printf("%d in Danish is: %s\n", number, buffer);
    return 0;
}