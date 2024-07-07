#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>


int LetterList(char letter, int row_value ,int column_value)
{
    char SetArray[6][8] = {
    {'B','F','P','V'},
    {'C','G','J','K','Q','S','X','Z'},
    {'D','T'},
    {'L'},
    {'M','N'},
    {'R'}
    };

     for (int i = 0; i < column_value; i++)
    {
        if (letter == SetArray[row_value][i])
        {
            return 1;
            break;
        }
    }
    return 0;
}


char ValueCheck6(char c)
{
    int row_value = 5;
    int column_value = 1;
    letter = toupper(c);
    if (LetterList(letter,row_value,column_value) == 1)
    {
        return '6';
    }
    else
    {
        return '0';
    }
}


char ValueCheck5(char c)
{
    int row_value = 4;
    int column_value = 2;
    letter = toupper(c);
    if (LetterList(letter,row_value,column_value) == 1)
    {
        return '5';
    }
    else
    {
        return ValueCheck6(c);
    }
}


char ValueCheck4(char c)
{
    int row_value = 3;
    int column_value = 1;
    letter = toupper(c);
    if (LetterList(letter,row_value,column_value) == 1)
    {
        return '4';
    }
    else
    {
        return ValueCheck5(c);
    }
}


char ValueCheck3(char c)
{
    int row_value = 2;
    int column_value = 2;
    letter = toupper(c);
    if (LetterList(letter,row_value,column_value) == 1)
    {
        return '3';
    }
    else
    {
        return ValueCheck4(c);
    }
}
char ValueCheck2(char c)
{
    int row_value = 1;
    int column_value = 8;
    letter = toupper(c);
    if (LetterList(letter,row_value,column_value) == 1)
    {
        return '2';
    }
    else
    {
        return ValueCheck3(c);
    }
}


char ValueCheck1(char c)
{
    int row_value = 0;
    int column_value = 4;
    letter = toupper(c);
    if (LetterList(letter,row_value,column_value) == 1)
    {
        return '1';
    }
    else
    {
        return ValueCheck2(c);
    }
}

char getSoundexCode(char c){ 
    return ValueCheck1(c);

}

void padzeros(char* soundex, int sIndex) 
{
    while (sIndex < 4)
    {
        soundex[sIndex++] = '0';
    }
}
void updatesoundexarray(char code, char* soundex, int* sIndex){
    if(code != soundex[(*sIndex) - 1])
    {
            soundex[(*sIndex)++] = code;
    }
}
void updatesoundexvowel(char code, char* soundex, int* sIndex, char* previous_code)
{    
    if((*previous_code) == '0' && code == soundex[(*sIndex) - 1])
    {
            soundex[(*sIndex)++] = code;
    }
    else 
    {
        updatesoundexarray(code, soundex, sIndex);
    }
}


void updatesoundex(char code, char* soundex, int* sIndex,char* previous_code)
 {
    
    if (code != '0' )
    {
        updatesoundexvowel(code, soundex, sIndex, previous_code);
    }
    else
    {
        (*previous_code) = code;
    }
    
}

void generateSoundex(const char *name, char *soundex)
 {
    int len = strlen(name);
    soundex[0] = getSoundexCode(name[0]);
    int sIndex = 1;
    char previous_code = '7';

    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        updatesoundex(code, soundex, &sIndex,&previous_code);
        
    }
    soundex[0] = toupper(name[0]);
    padzeros(soundex,sIndex);
    soundex[4] = '\0';
}
#endif // SOUNDEX_H
