# DanskeTal

Dette program konverterer heltal til deres tilsvarende danske tekstformat.

## Funktion

Funktionen `dansketal` konverterer et heltal til dansk tekst og skriver resultatet i en buffer.

### Funktionens Signatur

```c
void dansketal(int num, char* buffer, DanskeTalConfig* config);
```

### Struct definition

```c
typedef struct {
    int use_en;
} DanskeTalConfig;
```

## Hvordan bruger jeg det?

Alt du skal gøre er at skrive et tal ind i number variablen i main funktionen i main.c.

```c
#include <stdio.h>
#include "dansketal.h"

int main() {
    char buffer[256];
    int number = 2000000000;
    DanskeTalConfig config = {1}; // Brug "en" for store tal
    dansketal(number, buffer, &config);
    printf("%d på dansk er: %s\n", number, buffer);
    return 0;
}
```

## Kompilering og kørsel

For at kompilere og køre programmet, brug følgende kommandoer:

```
gcc main.c dansketal.c helpers.c -o dantal
```

Efterfulgt af:

```
./dantal
```

## Brug af demofil

Der er vedlagt en demofil, der kører et par forskellige eksempler igennem.
For at kompilere og køre demofilen, brug følgende kommandoer:

```
gcc demo.c dansketal.c helpers.c -o demo
```

Efterfulgt af:

```
./demo
```
