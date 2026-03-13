// Name: Lawrence Wong
// Student ID: 116408194

#include <criterion/criterion.h>
#include "../strgPtr.h"

// strgLen test cases
Test(strgLen, strgLen_Hello_Test){
    cr_expect_eq(strgLen("Hello"), 5);
}

Test(strgLen, strgLen_2Word_Test){
    cr_expect_eq(strgLen("Hello World"), 11);
}
Test(strgLen, strgLen_Symbol_Test){
    cr_expect_eq(strgLen("World!"), 6);
}

Test(strgLen, strgLen_EmptyString_Test){
    cr_expect_eq(strgLen(""), 0);
}

Test(strgLen, strgLen_NULL_Test){
    cr_expect_eq(strgLen(NULL), -1);
}

Test(strgLen, strgLen_MultipleSpaces_Test){
    cr_expect_eq(strgLen("   "), 3);
}

Test(strgLen, strgLen_OneChar_Test){
    cr_expect_eq(strgLen("a"), 1);
}

Test(strgLen, strgLen_Numbers_Test){
    cr_expect_eq(strgLen("12345"), 5);
}

Test(strgLen, strgLen_LettersNumbers_Test){
    cr_expect_eq(strgLen("abcde12345"), 10);
}

Test(strgLen, strgLen_Symbols_Test){
    cr_expect_eq(strgLen("!@#$%^&*()"), 10);
}

// strgCopy test cases
Test(strgCopy, strgCopy_Numbers_Test){
    char d[5];
    strgCopy("123456789", d, 5);
    cr_expect_str_eq(d, "1234");
}

Test(strgCopy, strgCopy_Char_Test){
    char d[2];
    strgCopy("Hello", d, 2);
    cr_expect_str_eq(d, "H");
}

Test(strgCopy, strgCopy_Terminator_Test){
    char d[1];
    strgCopy("Hello", d, 1);
    cr_expect_str_eq(d, "");
}

Test(strgCopy, strgCopy_2Words_Test){
    char d[17];
    strgCopy("Computer Science", d, 17);
    cr_expect_str_eq(d, "Computer Science");
}

Test(strgCopy, strgCopy_LargerArray_Test){
    char d[25];
    strgCopy("Long Array", d, 25);
    cr_expect_str_eq(d, "Long Array");
}

Test(strgCopy, strgCopy_EmptyArray_Test){
    char d[0];
    strgCopy("Hello", d, 0);
    cr_expect_str_eq(d, "");
}

Test(strgCopy, strgCopy_NULLString_Test){
    char d[10] = "";
    strgCopy(NULL, d, 10); 
    cr_expect_str_eq(d, "");
}

Test(strgCopy, strgCopy_Symbols_Test){
    char d[23];
    strgCopy("!@#$%^&*()", d, 23);
    cr_expect_str_eq(d, "!@#$%^&*()");
}

Test(strgCopy, strgCopy_Spaces_Test){
    char d[10];
    strgCopy("     ", d, 10);
    cr_expect_str_eq(d, "     ");
}

Test(strgCopy, strgCopy_SpacesChar_Test){
    char d[10];
    strgCopy("      a", d, 10);
    cr_expect_str_eq(d, "      a");
}

// strgChangeCase test cases
Test(strgChangeCase, strgChangeCase_Hello_Test){
    char s[] = "Hello";
    strgChangeCase(s);
    cr_expect_str_eq(s, "hELLO");
}

Test(strgChangeCase, strgChangeCase_Adjacency_Test){
    char s[] = "h1llo";
    strgChangeCase(s);
    cr_expect_str_eq(s, "h1lLO");
}

Test(strgChangeCase, strgChangeCase_2CharAdjacency_Test){
    char s[] = "h1";
    strgChangeCase(s);
    cr_expect_str_eq(s, "h1");
}

Test(strgChangeCase, strgChangeCase_Numbers_Test){
    char s[] = "1234567";
    strgChangeCase(s);
    cr_expect_str_eq(s, "1234567");
}

Test(strgChangeCase, strgChangeCase_Char_Test){
    char s[] = "h";
    strgChangeCase(s);
    cr_expect_str_eq(s, "H");
}

Test(strgChangeCase, strgChangeCase_EmptyString_Test){
    char s[] = "";
    strgChangeCase(s);
    cr_expect_str_eq(s, "");
}
 
Test(strgChangeCase, strgChangeCase_LongerString_Test){
    char s[] = "C4ps 1s N0t On";
    strgChangeCase(s);
    cr_expect_str_eq(s, "C4pS 1s N0t oN");
}

Test(strgChangeCase, strgChangeCase_NumberFirst_Test){
    char s[] = "1h";
    strgChangeCase(s);
    cr_expect_str_eq(s, "1h");
}

Test(strgChangeCase, strgChangeCase_Spaces_Test){
    char s[] = "   ";
    strgChangeCase(s);
    cr_expect_str_eq(s, "   ");
}

Test(strgChangeCase, strgChangeCase_NULL_Test){
    char *s = NULL;
    strgChangeCase(s);
    cr_expect_eq(s, NULL);
}

// strgDiff test cases
Test(strgDiff, strgDiff_SameString_Test){
    cr_expect_eq(strgDiff("Hello", "Hello"), -1);
}

Test(strgDiff, strgDiff_DiffString_Test){
    cr_expect_eq(strgDiff("H3llo", "Hello"), 1);
}

Test(strgDiff, strgDiff_BothEmpty_Test){
    cr_expect_eq(strgDiff("", ""), -1);
}

Test(strgDiff, strgDiff_FirstCharDiff_Test){
    cr_expect_eq(strgDiff("a", ""), 0);
}

Test(strgDiff, strgDiff_SecondCharDiff_Test){
    cr_expect_eq(strgDiff("", "a"), 0);
}

Test(strgDiff, strgDiff_FirstStringNull_Test){
    cr_expect_eq(strgDiff(NULL, "NULL"), -2);
}

Test(strgDiff, strgDiff_BothStringNull_Test){
    cr_expect_eq(strgDiff(NULL, NULL), -2);
}

Test(strgDiff, strgDiff_SecondStringNull_Test){
    cr_expect_eq(strgDiff("NULL", NULL), -2);
}

Test(strgDiff, strgDiff_LengthDifference_Test){
    cr_expect_eq(strgDiff("Hello World!", "Hello Worl"), 10);
}

Test(strgDiff, strgDiff_Spaces_Test){
    cr_expect_eq(strgDiff("     ", "      "), 5);
}

// strgInterleave test cases
Test(strgInterleave, strgInterleave_Basic_Test){
    char d[6];
    strgInterleave("abcdefghi", "123456789", d, 6);
    cr_expect_str_eq(d, "a1b2c");
}

Test(strgInterleave, strgInterleave_DifferentLengths1_Test){
    char d[20];
    strgInterleave("abcdefghi", "123", d, 20);
    cr_expect_str_eq(d, "a1b2c3defghi");
}

Test(strgInterleave, strgInterleave_DifferentLengths2_Test){
    char d[20];
    strgInterleave("abc", "123456789", d, 20);
    cr_expect_str_eq(d, "a1b2c3456789");
}

Test(strgInterleave, strgInterleave_Char_Test){
    char d[2];
    strgInterleave("abcd", "12345", d, 2);
    cr_expect_str_eq(d, "a");
}

Test(strgInterleave, strgInterleave_FirstNULL_Test){
    char d[20];
    strgInterleave(NULL, "12345", d, 20);
    cr_expect_str_eq(d, "");
}

Test(strgInterleave, strgInterleave_SecondNULL_Test){
    char d[10];
    strgInterleave("abcd", NULL, d, 10);
    cr_expect_str_eq(d, "");
}

Test(strgInterleave, strgInterleave_BothNULL_Test){
    char d[5];
    strgInterleave(NULL, NULL, d, 5);
    cr_expect_str_eq(d, "");
}

Test(strgInterleave, strgInterleave_Spaces_Test){
    char d[10];
    strgInterleave("abcde", "    ", d, 10);
    cr_expect_str_eq(d, "a b c d e");
}

Test(strgInterleave, strgInterleave_Symbols_Test){
    char d[20];
    strgInterleave("!@#$%", "     ", d, 20);
    cr_expect_str_eq(d, "! @ # $ % ");
}

Test(strgInterleave, strgInterleave_EmptyStrings_Test){
    char d[20];
    strgInterleave("", "", d, 20);
    cr_expect_str_eq(d, "");
}

// strgReverseLetters test cases
Test(strgReverseLetters, strgReverseLetters_Lowercase_Test){
    char d[] = "test";
    strgReverseLetters(d);
    cr_expect_str_eq(d, "tset");
}

Test(strgReverseLetters, strgReverseLetters_Uppercase_Test){
    char d[] = "TEST";
    strgReverseLetters(d);
    cr_expect_str_eq(d, "TSET");
}

Test(strgReverseLetters, strgReverseLetters_BothCases_Test){
    char d[] = "TeSt";
    strgReverseLetters(d);
    cr_expect_str_eq(d, "tSeT");
}

Test(strgReverseLetters, strgReverseLetters_Number_Test){
    char d[] = "T3st";
    strgReverseLetters(d);
    cr_expect_str_eq(d, "t3sT");
}

Test(strgReverseLetters, strgReverseLetters_Empty_Test){
    char d[] = "";
    strgReverseLetters(d);
    cr_expect_str_eq(d, "");
}

Test(strgReverseLetters, strgReverseLetters_NULL_Test){
    char *d = NULL;
    strgReverseLetters(d);
    cr_expect_eq(d, NULL);
}

Test(strgReverseLetters, strgReverseLetters_NotLetters_Test){
    char d[] = "*(07734)*";
    strgReverseLetters(d);
    cr_expect_str_eq(d, "*(07734)*");
}

Test(strgReverseLetters, strgReverseLetters_Palindrome_Test){
    char d[] = "racecar";
    strgReverseLetters(d);
    cr_expect_str_eq(d, "racecar");
}

Test(strgReverseLetters, strgReverseLetters_TwoWords_Test){
    char d[] = "Hello World!";
    strgReverseLetters(d);
    cr_expect_str_eq(d, "dlroW olleH!");
}

Test(strgReverseLetters, strgReverseLetters_SymbolsBetween_Test){
    char d[] = "a#!)b($())c#*d";
    strgReverseLetters(d);
    cr_expect_str_eq(d, "d#!)c($())b#*a");
}
