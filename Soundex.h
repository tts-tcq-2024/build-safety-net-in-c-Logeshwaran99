#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

// Get the Soundex code for a given character
char getSoundexCode(char c) {
    static const char codeTable[26] = {
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
        '0', // O
        '1', // P
        '2', // Q
        '2', // R
        '3', // S
        '0', // T
        '0', // U
        '1', // V
        '3', // W
        '0', // X
        '0'  // Y
    };
    c = toupper(c);
    if (isalpha(c)) {
        return codeTable[c - 'A'];
    }
    return '0';
}

// Update the Soundex code array based on the new digit
int updateSoundex(char code, int sIndex, char *soundex) {
    if (code != '0' && (sIndex == 1 || code != soundex[sIndex - 1])) {
        soundex[sIndex] = code;
        return ++sIndex;
    }
    return sIndex;
}

int emptyfunction(const char *name, char *soundex){
    if (name == NULL || name[0] == '\0') {
        strcpy(soundex, "0000");
        return;
    }
}

// Generate Soundex code from a name
void generateSoundex(const char *name, char *soundex) {
    emptyfunction(name,soundex);
    soundex[0] = toupper(name[0]);
    int sIndex = 1;

    for (int i = 1; name[i] != '\0' && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        sIndex = updateSoundex(code, sIndex, soundex);
    }
    
    memset(soundex + sIndex, '0', 4 - sIndex);
    soundex[4] = '\0';
}

#endif // SOUNDEX_H
