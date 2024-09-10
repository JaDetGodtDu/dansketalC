#include <stdio.h>
#include <string.h>
#include "helpers.h"

void dansketal(int num, char *buffer, DanskeTalConfig *config)
{
    buffer[0] = '\0'; // Clear the buffer

    if (num == 0)
    {
        strcat(buffer, "nul");
        return;
    }

    if (num < 0)
    {
        strcat(buffer, "minus ");
        num = -num;
    }

    if (num < 10)
    {
        convert_units(num, buffer, 0, config);
    }
    else if (num < 100)
    {
        convert_tens(num, buffer, config);
    }
    else if (num < 1000)
    {
        convert_hundreds(num, buffer, config);
    }
    else if (num < 1000000)
    {
        convert_thousands(num, buffer, config);
    }
    else if (num < 1000000000)
    {
        convert_millions(num, buffer, config);
    }
    else
    {
        int billions = num / 1000000000;
        convert_units(billions, buffer, 1, config);
        strcat(buffer, " milliard");
        if (billions > 1)
        {
            strcat(buffer, "er");
        }
        if (num % 1000000000 != 0)
        {
            strcat(buffer, " ");
            convert_millions(num % 1000000000, buffer, config);
        }
    }
}

// int main()
// {
//     char buffer[256];
//     int number = -125;
//     DanskeTalConfig config = {1}; // Use "en" for large numbers
//     dansketal(number, buffer, &config);
//     printf("%d in Danish is: %s\n", number, buffer);
//     return 0;
// }