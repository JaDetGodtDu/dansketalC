#include <stdio.h>
#include "dansketal.h"

int main()
{
    char buffer[256];
    DanskeTalConfig config = {1}; // Brug "en" for store tal

    // Test 1: Positive tal
    int number1 = 123;
    dansketal(number1, buffer, &config);
    printf("\n%d in Danish is: %s\n", number1, buffer);
    // Forventet output: "123 på dansk er: et hundrede og treogtyve"

    int number1_1 = 1;
    dansketal(number1_1, buffer, &config);
    printf("\n%d in Danish is: %s\n", number1_1, buffer);
    // Forventet output: "1 på dansk er: en"

    // Test 2: Negative tal
    int number2 = -456;
    dansketal(number2, buffer, &config);
    printf("\n%d in Danish is: %s\n", number2, buffer);
    // Forventet output: "-456 på dansk er: minus fire hundrede og seksoghalvtreds"

    // Test 3: Store tal
    int number3 = 2000000000;
    dansketal(number3, buffer, &config);
    printf("\n%d in Danish is: %s\n", number3, buffer);
    // Forventet output: "2000000000 på dansk er: to milliarder"

    // Test 4: Nul
    int number4 = 0;
    dansketal(number4, buffer, &config);
    printf("\n%d in Danish is: %s\n", number4, buffer);
    // Forventet output: "0 på dansk er: nul"

    // Test 5: Tusinde
    int number5 = 1001;
    dansketal(number5, buffer, &config);
    printf("\n%d in Danish is: %s\n", number5, buffer);
    // Forventet output: "1001 på dansk er: et tusind og en"

    // Test 5.1: Tusinde
    int number5_1 = 1234;
    dansketal(number5_1, buffer, &config);
    printf("\n%d in Danish is: %s\n", number5_1, buffer);
    // Forventet output: "1234 på dansk er: et tusind to hundrede og fireogtredive"

    // Test 6: Én million
    int number6 = 1000000;
    dansketal(number6, buffer, &config);
    printf("\n%d in Danish is: %s\n", number6, buffer);
    // Forventet output: "1000000 på dansk er: en million"

    // Test 7: To milliader
    int number7 = 1000000000;
    dansketal(number7, buffer, &config);
    printf("\n%d in Danish is: %s\n", number7, buffer);
    // Forventet output: "1000000000 på dansk er: en milliard"

    // Test 8: Komplekse tal
    int number8 = 123456789;
    dansketal(number8, buffer, &config);
    printf("\n%d in Danish is: %s\n", number8, buffer);
    // Forventet output: "123456789 på dansk er: et hundrede og treogtyve millioner fire hundrede og seksoghalvtreds tusind syv hundrede og niogfirs"

    return 0;
}