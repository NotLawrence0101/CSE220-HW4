// Name: Lawrence Wong
// Student ID: 116408194

#include <criterion/criterion.h>
#include "../strgPtr.h"

Test(strgLen, lengthTests){
    cr_expect_eq(strgLen("Hello"), 5);
    cr_expect_eq(strgLen("Hello World"), 11);
    cr_expect_eq(strgLen("World!"), 6);
    cr_expect_eq(strgLen(""), 0);
    cr_expect_eq(strgLen(NULL), -1);
    cr_expect_eq(strgLen("   "), 3);
    cr_expect_eq(strgLen("a"), 1);
    cr_expect_eq(strgLen("12345"), 5);
    cr_expect_eq(strgLen("abcde12345"), 10);
    cr_expect_eq(strgLen("!@#$%^&*()"), 10);
}

Test(strgCopy, copyTests){
    char a[5];
    strgCopy("123456789", a, 5);
    cr_expect_str_eq(a, "1234");

    char b[2];
    strgCopy("Hello", b, 2);
    cr_expect_str_eq(b, "H");

    char c[1];
    strgCopy("Hello", c, 1);
    cr_expect_str_eq(c, "");

    char d[17];
    strgCopy("Computer Science", d, 17);
    cr_expect_str_eq(d, "Computer Science");

    char e[25];
    strgCopy("Long Array", e, 25);
    cr_expect_str_eq(e, "Long Array");
    
    char f[0];
    strgCopy("Hello", f, 0);
    cr_expect_str_eq(f, "");

    char g[10];
    strgCopy(NULL, g, 10); 
    cr_expect_str_eq(g, "");

    char h[23];
    strgCopy("!@#$%^&*()", h, 23);
    cr_expect_str_eq(h, "!@#$%^&*()");

    char i[10];
    strgCopy("     ", i, 10);
    cr_expect_str_eq(i, "     ");

    strgCopy("      a", i, 10);
    cr_expect_str_eq(i, "      a");
}

Test(strgChangeCase, changeCasesTest){
    char s[] = "Hello";
    strgChangeCase(s);
    cr_expect_str_eq(s, "hELLO");

    char s1[] = "h1llo";
    strgChangeCase(s1);
    cr_expect_str_eq(s1, "h1lLO");

    char s2[] = "h1";
    strgChangeCase(s2);
    cr_expect_str_eq(s2, "h1");

    char s3[] = "1234567";
    strgChangeCase(s3);
    cr_expect_str_eq(s3, "1234567");
    
    char s4[] = "h";
    strgChangeCase(s4);
    cr_expect_str_eq(s4, "H");

    char s5[] = "";
    strgChangeCase(s5);
    cr_expect_str_eq(s5, "");

    char s6[] = "1";
    strgChangeCase(s6);
    cr_expect_str_eq(s6, "1");
    
    char s7[] = "C4ps 1s N0t On";
    strgChangeCase(s7);
    cr_expect_str_eq(s7, "C4pS 1s N0t oN");

    char s8[] = "1h";
    strgChangeCase(s8);
    cr_expect_str_eq(s8, "1h");

    char s9[] = "   ";
    strgChangeCase(s9);
    cr_expect_str_eq(s9, "   ");
}

Test(strgDiff, diffTest){
    cr_expect_eq(strgDiff("Hello", "Hello"), -1);
    cr_expect_eq(strgDiff("H3llo", "Hello"), 1);
    cr_expect_eq(strgDiff("", ""), -1);
    cr_expect_eq(strgDiff("a", ""), 0);
    cr_expect_eq(strgDiff("", "a"), 0);
    cr_expect_eq(strgDiff(NULL, "NULL"), -2);
    cr_expect_eq(strgDiff(NULL, NULL), -2);
    cr_expect_eq(strgDiff("NULL", NULL), -2);
    cr_expect_eq(strgDiff("Hello World!", "Hello Worl"), 10);
    cr_expect_eq(strgDiff("     ", "      "), 5);
}

Test(strgInterleave, studentTest){
    char a[6];
    strgInterleave("abcdefghi", "123456789", a, 6);
    cr_expect_str_eq(a, "a1b2c");

    char b[20];
    strgInterleave("abcdefghi", "123", b, 20);
    cr_expect_str_eq(b, "a1b2c3defghi");

    char c[20];
    strgInterleave("abc", "123456789", c, 20);
    cr_expect_str_eq(c, "a1b2c3456789");

    char d[2];
    strgInterleave("abcd", "12345", d, 2);
    cr_expect_str_eq(d, "a");

    char e[20];
    strgInterleave(NULL, "12345", e, 20);
    cr_expect_str_eq(e, "");

    strgInterleave("abcd", NULL, e, 20);
    cr_expect_str_eq(e, "");

    strgInterleave(NULL, NULL, e, 20);
    cr_expect_str_eq(e, "");

    char f[10];
    strgInterleave("abcde", "    ", f, 10);
    cr_expect_str_eq(f, "a b c d e");

    char g[20];
    strgInterleave("!@#$%", "     ", g, 20);
    cr_expect_str_eq(g, "! @ # $ % ");

    char h[20];
    strgInterleave("", "", h, 20);
    cr_expect_str_eq(h, "");
}

Test(strgReverseLetters, studentTest){
    char a[] = "Test";
    strgReverseLetters(a);
    cr_expect_str_eq(a, "tseT");

    char b[] = "W0ah";
    strgReverseLetters(b);
    cr_expect_str_eq(b, "h0aW");

    char c[] = "";
    strgReverseLetters(c);
    cr_expect_str_eq(c, "");
}
