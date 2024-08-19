#include <gtest/gtest.h>
#include "Soundex.h"

// Test case for a single character
TEST(SoundexTestsuite, HandlesSingleCharacter) {
    char soundex[5];
    generateSoundex("A", soundex);
    ASSERT_STREQ(soundex, "A000");
}

// Test case for a string with all vowels
TEST(SoundexTestsuite, HandlesVowelsOnly) {
    char soundex[5];
    generateSoundex("AEIOU", soundex);
    ASSERT_STREQ(soundex, "A000");
}

// Test case for a string with consecutive duplicates
TEST(SoundexTestsuite, HandlesConsecutiveDuplicates) {
    char soundex[5];
    generateSoundex("SSSSS", soundex);
    ASSERT_STREQ(soundex, "S020");
}

// Test case for a string with non-alphabetic characters
TEST(SoundexTestsuite, HandlesNonAlphabeticCharacters) {
    char soundex[5];
    generateSoundex("S1S2S3", soundex);
    ASSERT_STREQ(soundex, "S123");
}

// Test case for a string with mixed case
TEST(SoundexTestsuite, HandlesMixedCase) {
    char soundex[5];
    generateSoundex("hElLo", soundex);
    ASSERT_STREQ(soundex, "H040");
}

// Test case for a string with trailing non-alphabetic characters
TEST(SoundexTestsuite, HandlesTrailingNonAlphabeticCharacters) {
    char soundex[5];
    generateSoundex("Smit2", soundex);
    ASSERT_STREQ(soundex, "S530");
}

// Test case for a string where the Soundex code needs padding
TEST(SoundexTestsuite, HandlesPaddingWithZeros) {
    char soundex[5];
    generateSoundex("Sm", soundex);
    ASSERT_STREQ(soundex, "S500");
}

// Test case for a string where the Soundex code is exactly four characters long
TEST(SoundexTestsuite, HandlesExactLength) {
    char soundex[5];
    generateSoundex("Smith", soundex);
    ASSERT_STREQ(soundex, "S530");
}

// Test case for a string with special characters at the start
TEST(SoundexTestsuite, HandlesSpecialCharactersAtStart) {
    char soundex[5];
    generateSoundex("@mith", soundex);
    ASSERT_STREQ(soundex, "M030");
}

// Test case for a string where all characters are mapped to '0'
TEST(SoundexTestsuite, HandlesAllCharactersMappedToZero) {
    char soundex[5];
    generateSoundex("AEIOUY", soundex);
    ASSERT_STREQ(soundex, "A000");
}

// Test case for names with spaces and hyphens
TEST(SoundexTestsuite, HandlesSpacesAndHyphens) {
    char soundex[5];
    generateSoundex("Mc Donald", soundex);
    ASSERT_STREQ(soundex, "M325");
}

// Test case for names with multiple non-alphabetic characters in the middle
TEST(SoundexTestsuite, HandlesMultipleNonAlphabeticCharacters) {
    char soundex[5];
    generateSoundex("Jo'hn", soundex);
    ASSERT_STREQ(soundex, "J500");
}

// Test case for a name with different characters and exact output length
TEST(SoundexTestsuite, HandlesDifferentCharactersWithExactOutputLength) {
    char soundex[5];
    generateSoundex("Lloyd", soundex);
    ASSERT_STREQ(soundex, "L030");
}

// Test case for a very long name
TEST(SoundexTestsuite, HandlesLongName) {
    char soundex[5];
    generateSoundex("Alexanderson", soundex);
    ASSERT_STREQ(soundex, "A252");
}

// Test case for a name with leading non-alphabetic characters
TEST(SoundexTestsuite, HandlesLeadingNonAlphabeticCharacters) {
    char soundex[5];
    generateSoundex("1234Smith", soundex);
    ASSERT_STREQ(soundex, "S530");
}

// Test case for input with a name starting with a special character
TEST(SoundexTestsuite, HandlesNameStartingWithSpecialCharacter) {
    char soundex[5];
    generateSoundex("!Smith", soundex);
    ASSERT_STREQ(soundex, "S530");
}

// Test case for input where first character is non-alphabetic
TEST(SoundexTestsuite, HandlesFirstCharacterNonAlphabetic) {
    char soundex[5];
    generateSoundex("1Smith", soundex);
    ASSERT_STREQ(soundex, "S530");
}

// Test case for a name that maps to a Soundex code with padding needed
TEST(SoundexTestsuite, HandlesSoundexCodeWithPaddingNeeded) {
    char soundex[5];
    generateSoundex("Tully", soundex);
    ASSERT_STREQ(soundex, "T400");
}
