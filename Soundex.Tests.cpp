#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("AX", soundex);
 // ASSERT_EQ(soundex,"A200");
}
TEST(SoudexTestsuite, positivecase)
{
  char soundex[5];
  generateSoundex("Robert", soundex);
}
TEST(SoudexTestsuite, vowelcase)
{
  char soundex[5];
  generateSoundex("Tymczak", soundex);
}
TEST(SoudexTestsuite, zeropadding)
{
  char soundex[5];
  generateSoundex("B", soundex);
}
TEST(SoudexTestsuite, samearray)
{
  char soundex[5];
  generateSoundex("Pfister", soundex);
}