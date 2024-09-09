#ifndef HELPERS_H
#define HELPERS_H

typedef struct {
    int use_en_for_large_numbers;
} DanskeTalConfig;

void convert_units(int num, char* buffer, int is_large_number, DanskeTalConfig* config);
void convert_tens(int num, char* buffer, DanskeTalConfig* config);
void convert_hundreds(int num, char* buffer, DanskeTalConfig* config);
void convert_thousands(int num, char* buffer, DanskeTalConfig* config);
void convert_millions(int num, char* buffer, DanskeTalConfig* config);

#endif // HELPERS_H