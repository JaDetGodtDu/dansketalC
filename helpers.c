#include <string.h>
#include "helpers.h"

void convert_units(int num, char* buffer, int is_large_number, DanskeTalConfig* config) {
    const char* units[] = {"nul", "et", "to", "tre", "fire", "fem", "seks", "syv", "otte", "ni"};
    const char* large_units[] = {"nul", "en", "to", "tre", "fire", "fem", "seks", "syv", "otte", "ni"};
    if (num >= 0 && num <= 9) {
        if (is_large_number && num == 1 && config->use_en_for_large_numbers) {
            strcat(buffer, large_units[num]);
        } else {
            strcat(buffer, units[num]);
        }
    }
}

void convert_tens(int num, char* buffer, DanskeTalConfig* config) {
    const char* tens[] = {"", "ti", "tyve", "tredive", "fyrre", "halvtreds", "tres", "halvfjerds", "firs", "halvfems"};
    if (num >= 10 && num <= 99) {
        if (num < 20) {
            const char* teens[] = {"ti", "elleve", "tolv", "tretten", "fjorten", "femten", "seksten", "sytten", "atten", "nitten"};
            strcat(buffer, teens[num - 10]);
        } else {
            if (num % 10 != 0) {
                convert_units(num % 10, buffer, 0, config);
                strcat(buffer, "og");
            }
            strcat(buffer, tens[num / 10]);
        }
    }
}

void convert_hundreds(int num, char* buffer, DanskeTalConfig* config) {
    if (num >= 100 && num <= 999) {
        if (num / 100 == 1) {
            strcat(buffer, "et hundrede");
        } else {
            convert_units(num / 100, buffer, 0, config);
            strcat(buffer, " hundrede");
        }
        if (num % 100 != 0) {
            strcat(buffer, " og ");
            convert_tens(num % 100, buffer, config);
        }
    }
}

void convert_thousands(int num, char* buffer, DanskeTalConfig* config) {
    if (num >= 1000 && num <= 999999) {
        int thousands = num / 1000;
        if (thousands < 10) {
            convert_units(thousands, buffer, 1, config);
        } else if (thousands < 100) {
            convert_tens(thousands, buffer, config);
        } else {
            convert_hundreds(thousands, buffer, config);
        }
        strcat(buffer, " tusinde");
        if (num % 1000 != 0) {
            strcat(buffer, " ");
            convert_hundreds(num % 1000, buffer, config);
        }
    }
}

void convert_millions(int num, char* buffer, DanskeTalConfig* config) {
    if (num >= 1000000) {
        int millions = num / 1000000;
        if (millions < 10) {
            convert_units(millions, buffer, 1, config);
        } else if (millions < 100) {
            convert_tens(millions, buffer, config);
        } else {
            convert_hundreds(millions, buffer, config);
        }
        strcat(buffer, " million");
        if (millions > 1) {
            strcat(buffer, "er");
        }
        if (num % 1000000 != 0) {
            strcat(buffer, " ");
            convert_thousands(num % 1000000, buffer, config);
        }
    }
}