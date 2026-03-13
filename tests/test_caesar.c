// Name: Lawrence Wong
// Student ID: 116408194

#include <criterion/criterion.h>
#include "../cse_caesar.h"

// encryptCaesar test cases
Test(encryptCaesar, encryptCaesar_Basic_Test) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxx";
    int r = encryptCaesar("hello", buf, 2);
    cr_expect_eq(r, 5);
    cr_expect_str_eq(buf, "jhpqu__EOM__");
}

Test(encryptCaesar, encryptCaesar_NULL_Test) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxx";
    int r = encryptCaesar(NULL, buf, 2);
    cr_expect_eq(r, -2);
    cr_expect_str_eq(buf, "xxxxxxxxxxxxxxxxxxxxxxxx");
}

Test(encryptCaesar, encryptCaesar_TooSmall_Test) {
    char buf[8] = "xxxxxxxx";
    int r = encryptCaesar("hello", buf, 8);
    cr_expect_eq(r, -1);
    cr_expect_str_eq(buf, "xxxxxxxx");
}

Test(encryptCaesar, encryptCaesar_Undefined_Test) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxx";
    int r = encryptCaesar("", buf, 10);
    cr_expect_eq(r, 0);
    cr_expect_str_eq(buf, "undefined__EOM__");
}

Test(encryptCaesar, encryptCaesar_Numbers_Test) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxx";
    int r = encryptCaesar("07734", buf, 2);
    cr_expect_eq(r, 5);
    cr_expect_str_eq(buf, "20180__EOM__");
}

// decryptCaesar test cases
Test(decryptCaesar, decryptCaesar_Basic_Test) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxx";
    int r = decryptCaesar("jhpqu__EOM__", buf, 2);
    cr_expect_eq(r, 5);
    cr_expect_str_eq(buf, "hello");
}

Test(decryptCaesar, decryptCaesar_NULL_Test) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxx";
    int r = decryptCaesar(NULL, buf, 2);
    cr_expect_eq(r, -2);
    cr_expect_str_eq(buf, "xxxxxxxxxxxxxxxxxxxxxxxx");
}

Test(decryptCaesar, decryptCaesar_NoEOMMarker_Test) {
    char buf[8] = "xxxxxxxx";
    int r = decryptCaesar("jhpqu", buf, 2);
    cr_expect_eq(r, -1);
    cr_expect_str_eq(buf, "xxxxxxxx");
}

Test(decryptCaesar, decryptCaesar_Undefined_Test) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxx";
    int r = decryptCaesar("undefined__EOM__", buf, 2);
    cr_expect_eq(r, 0);
    cr_expect_str_eq(buf, "undefined");
}

Test(decryptCaesar, decryptCaesar_Numbers_Test) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxx";
    int r = decryptCaesar("20180__EOM__", buf, 2);
    cr_expect_eq(r, 5);
    cr_expect_str_eq(buf, "07734");
}
