#include <gtest/gtest.h>
#include "Soundex.h"

void generateSoundex(const char *name, char *soundex);
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("AXL", soundex);
  EXPECT_STREQ(soundex,"A200");
}
TEST(SoundexTestsuite, BasicInput) {
    char soundex[5];
    generateSoundex("Robert", soundex);
    EXPECT_STREQ(soundex, "R163");
}

TEST(SoundexTestsuite, InputWithSpecialCharacters) {
    char soundex[5];
    generateSoundex("O'Connor", soundex);
    EXPECT_STREQ(soundex, "O252");
}

TEST(SoundexTestsuite, SingleCharacter) {
    char soundex[5];
    generateSoundex("A", soundex);
    EXPECT_STREQ(soundex, "A000");
}

TEST(SoundexTestsuite, MixedCaseInput) {
    char soundex[5];
    generateSoundex("bOB", soundex);
    EXPECT_STREQ(soundex, "B010");
}

TEST(SoundexTestsuite, EmptyInput) {
    char soundex[5];
    generateSoundex("", soundex);
    EXPECT_STREQ(soundex, "0000");
}

TEST(SoundexTestsuite, NonAlphabeticCharacters) {
    char soundex[5];
    generateSoundex("123456", soundex);
    EXPECT_STREQ(soundex, "0000");
}

TEST(SoundexTestsuite, AllSameLetters) {
    char soundex[5];
    generateSoundex("AAAA", soundex);
    EXPECT_STREQ(soundex, "A000");
}

TEST(SoundexTestsuite, ConsecutiveLettersMappingSameCode) {
    char soundex[5];
    generateSoundex("BFPV", soundex);
    EXPECT_STREQ(soundex, "B111");
}

TEST(SoundexTestsuite, FullAlphabetInput) {
    char soundex[5];
    generateSoundex("ABCDEFGHIJKLMNOPQRSTUVWXYZ", soundex);
    EXPECT_STREQ(soundex, "A123");
}

TEST(SoundexTestsuite, MixedCaseAndSymbols) {
    char soundex[5];
    generateSoundex("HeLLo_World!", soundex);
    EXPECT_STREQ(soundex, "H450");
}
