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

// Get the Soundex digit for a given character
char getSoundexCode(char c) {
    if (isalpha(c)) {
        return SoundexMap[toupper(c) - 'A'];
    }
    return c; // Preserve non-alphabetic characters
}

// Pad the Soundex result with zeros if necessary
void padzeros(char* soundex, int sIndex) {
    for (; sIndex < 4; ++sIndex) {
        soundex[sIndex] = '0';
    }
}

// Update the Soundex code array based on the new digit
void updateSoundex(char code, char* soundex, int* sIndex, char* previous_code) {
    // Check if the code is valid and not equal to the previous code
    if (code != '0') {
        // Update soundex if different from the previous code
        if (code != *previous_code) {
            soundex[(*sIndex)++] = code;
        }
        *previous_code = code;
    }
}

// Initialize the Soundex result
void initializeSoundex(const char* name, char* soundex, int* sIndex, char* previous_code) {
    soundex[0] = toupper(name[0]);
    *sIndex = 1;
    *previous_code = getSoundexCode(name[0]);
}

// Generate Soundex code from a name
void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    if (len == 0) {
        strcpy(soundex, "0000");
        return;
    }

    int sIndex;
    char previous_code;
    initializeSoundex(name, soundex, &sIndex, &previous_code);

    for (int i = 1; i < len && sIndex < 4; ++i) {
        char code = getSoundexCode(name[i]);
        updateSoundex(code, soundex, &sIndex, &previous_code);
    }

    padzeros(soundex, sIndex);
    soundex[4] = '\0';
}

#endif // SOUNDEX_H
