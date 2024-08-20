#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) {
    static const char soundexTable[26] = {
        '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', 
        '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'
    };
    c = toupper(c);
    return isalpha(c) ? soundexTable[c - 'A'] : '0';
}

void initializeSoundex(char *soundex, char firstCharacter) {
    soundex[0] = toupper(firstCharacter);
    soundex[1] = soundex[2] = soundex[3] = '0';
    soundex[4] = '\0';
}

int shouldAddToSoundex(char code, char *soundex, int sIndex) {
    return sIndex < 4 && code != '0' && code != soundex[sIndex - 1];
}

void processCharacter(const char *name, char *soundex, int *sIndex, int i) {
    char code = getSoundexCode(name[i]);
    if (shouldAddToSoundex(code, soundex, *sIndex)) {
        soundex[*sIndex] = code;
        (*sIndex)++;
    }
}

void generateSoundex(const char *name, char *soundex) {
    int i = 0;
    // Skip leading non-alphabetic characters
    while (name[i] && !isalpha(name[i])) i++;

    if (!name[i]) {
        initializeSoundex(soundex, '0');
        return;
    }

    initializeSoundex(soundex, name[i++]);

    int sIndex = 1;
    int len = strlen(name);
    for (; i < len; i++) {
        processCharacter(name, soundex, &sIndex, i);
    }
}

#endif // SOUNDEX_H
