#include <gtest/gtest.h>
#include "Soundex.h"

void generateSoundex(const char *name, char *soundex);
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("AXL", soundex);
 // ASSERT_EQ(soundex,"A200");
}
TEST(SoundexTestsuite, BasicInput) {
    generateSoundex("Robert", "R163");
}

TEST(SoundexTestsuite, InputWithSpecialCharacters) {
    generateSoundex("O'Connor", "O252");
}

TEST(SoundexTestsuite, SingleCharacter) {
    generateSoundex("A", "A000");
}

TEST(SoundexTestsuite, MixedCaseInput) {
    generateSoundex("bOB", "B010");
}

TEST(SoundexTestsuite, EmptyInput) {
    generateSoundex("", "0000");
}

TEST(SoundexTestsuite, NonAlphabeticCharacters) {
    generateSoundex("123456", "0000");
}

TEST(SoundexTestsuite, AllSameLetters) {
    generateSoundex("AAAA", "A000");
}

TEST(SoundexTestsuite, ConsecutiveLettersMappingSameCode) {
    generateSoundex("BFPV", "B111");
}

TEST(SoundexTestsuite, FullAlphabetInput) {
    generateSoundex("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "A123");
}

TEST(SoundexTestsuite, MixedCaseAndSymbols) {
    generateSoundex("HeLLo_World!", "H450");
}
