#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

const char SoundexMap[26] = {
    '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'
};

char getSoundexCode(char c) {
    c = toupper(c);
    if (c >= 'A' && c <= 'Z') {
        return SoundexMap[c - 'A'];
    }
    return '0';
}

void padzeros(char* soundex, int sIndex) {
    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }
}

void updatesoundex(char code, char* soundex, int* sIndex, char* previous_code) {
    if (code != '0' && code != *previous_code) {
        soundex[(*sIndex)++] = code;
        *previous_code = code;
    }
}

void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
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
