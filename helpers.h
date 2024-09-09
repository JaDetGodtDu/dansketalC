#ifndef HELPERS_H
#define HELPERS_H

void convert_units(int num, char* buffer, int is_thousands);
void convert_tens(int num, char* buffer);
void convert_hundreds(int num, char* buffer);
void convert_thousands(int num, char* buffer);
void convert_millions(int num, char* buffer);

#endif