#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

char getFirstValidCharacter(const char *name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (isalpha(name[i])) {
            return toupper(name[i]);
        }
    }
    return '0';  // Return '0' if no valid character is found
}

char getSoundexCode(char c) {
    static const char soundexTable[26] = {
        '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', 
        '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'
    };
    c = toupper(c);
    return isalpha(c) ? soundexTable[c - 'A'] : '0';
}

void initializeSoundex(char *soundex, char firstCharacter) {
    soundex[0] = firstCharacter;
    memset(&soundex[1], '0', 3);  // Set soundex[1] to soundex[3] to '0'
    soundex[4] = '\0';
}

void fillSoundexCodes(const char *name, char *soundex) {
    int sIndex = 1;
    for (int i = 0; name[i] != '\0' && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != soundex[sIndex - 1]) {
            soundex[sIndex++] = code;
        }
    }
}

void generateSoundex(const char *name, char *soundex) {
    char firstChar = getFirstValidCharacter(name);
    initializeSoundex(soundex, firstChar);
    fillSoundexCodes(name, soundex);
}

#endif // SOUNDEX_H
