#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

// Mapping of consonants to Soundex digits
const char SoundexMap[26] = {
    '0', // A
    '1', // B
    '2', // C
    '3', // D
    '0', // E
    '1', // F
    '2', // G
    '0', // H
    '0', // I
    '2', // J
    '2', // K
    '3', // L
    '5', // M
    '5', // N
    '6', // O
    '1', // P
    '2', // Q
    '2', // R
    '3', // S
    '0', // T
    '0', // U
    '0', // V
    '3', // W
    '0', // X
    '0'  // Y
};

// Function to get the Soundex digit for a given character
char getSoundexCode(char c) {
    if (isalpha(c)) {
        return SoundexMap[toupper(c) - 'A'];
    }
    return c; // Preserve non-alphabetic characters
}

// Function to pad Soundex result with zeros if necessary
void padzeros(char* soundex, int sIndex) {
    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }
}

// Function to update the Soundex code array
void updatesoundex(char code, char* soundex, int* sIndex, char* previous_code) {
    if (code != '0' && code != *previous_code) {
        soundex[(*sIndex)++] = code;
        *previous_code = code;
    } else if (code == '0') {
        *previous_code = code;
    }
}

// Function to generate Soundex code from a name
void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    if (len == 0) {
        strcpy(soundex, "0000");
        return;
    }
    
    soundex[0] = toupper(name[0]);
    int sIndex = 1;
    char previous_code = getSoundexCode(name[0]);

    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        updatesoundex(code, soundex, &sIndex, &previous_code);
    }
    
    padzeros(soundex, sIndex);
    soundex[4] = '\0';
}

#endif // SOUNDEX_H
